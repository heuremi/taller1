#include <iostream>
#include "Software.h"
#include "Usuario.h"
#include "Juego.h"
#include "Ofimatica.h"
#include "Produccion.h"
#include "Navegador.h"
#include "Seguridad.h"
#include "Social.h"
using namespace std;

vector<Software*> bibliotecaSoftware;
vector<Usuario*> bibliotecaUsuario;
Usuario* usuarioActual;

//Muestra los softwares del usuario actual.
void mostrarUsuarioSoftware(){
    //si la lista de softwares del usuario esta vacia no se puede recorrer.
    if(usuarioActual->getListaSoftwaresSize() == 0){
        cout << "No tienes Softwares." << endl;
        return;
    }
    //si la lista de softwares del usuario no esta vacia se recorre y se imprime.
    for(int i = 0; i < usuarioActual->getListaSoftwaresSize(); i++){
        cout << "ID en tu biblioteca: " << i+1 << ", " << usuarioActual->getSoftware(i)->toString() << endl;
    }
}

//Muestra los softwares de la lista general de softwares.
void mostrarTodosSoftware(){
    //Si no hay softwares no se puede recorrer.
    if(bibliotecaSoftware.empty()){
        cout << "No existen Softwares." << endl;
        return;
    }
    //Si hay softwares se recorre.
    for(int i = 0; i < bibliotecaSoftware.size(); i++){
        //Si es de tipo de seguridad solo es posible que lo accedan los usuarios administradores.
        if(typeid(*bibliotecaSoftware[i]) == typeid(Seguridad)){
            if(usuarioActual->getLog()){
                cout << "ID General: " << i+1 << ", " << bibliotecaSoftware[i]->toString() << endl;
            }
        } else {
            //si el usuario es de tipo nino, solo puede ver los softwares para menores de 18.
            if(usuarioActual->getEdad() < 18 && bibliotecaSoftware[i]->getRestriccion() < 18){
                cout << "ID General: " << i+1 << ", " << bibliotecaSoftware[i]->toString() << endl;
            }
            // si el usuario es normal puede ver todos los softwares menos seguridad.
            else if(usuarioActual->getEdad() >= 18) {
                cout << "ID General: " << i+1 << ", " << bibliotecaSoftware[i]->toString() << endl;
            }
        }
    }
}

//revisa si existe un software en la lista de softwares del usuario actual, retorna true en caso de ser encontrado y false en caso de no existir.
bool existirSoftwareEnListaUsuario(Software softwareBuscado){
    for(int i = 0; i < usuarioActual->getListaSoftwaresSize(); i++){
        //si se encuentra el software buscado en la lista del usuario actual, se retorna verdadero
        if(usuarioActual->getSoftware(i)->getNombre() == softwareBuscado.getNombre()){
            return true;
        }
    }
    //en caso de que el software no este en la lista del usuario actual.
    return false;
}

//busca un software en la lista general de softwares, retorna la posicion del software en la lista.
int buscarSoftware(Software* software){
    for(int i = 0; i < bibliotecaSoftware.size(); i++){
        if(bibliotecaSoftware[i]->getNombre() == software->getNombre()){
            return i;
        }
    }
    return -1;
}

//busca un usuario en la lista general de usuarios, retorna la posicion en la lista.
int buscarUsuario(string usuario){
    for(int i = 0; i < bibliotecaUsuario.size(); i++){
        if(bibliotecaUsuario[i]->getNombre() == usuario){
            return i;
        }
    }
    return -1;
}

//agrega un software en la lista de softwares del usuario.
void agregarSoftware(){
    //muestra los softwares posibles para agregar.
    mostrarTodosSoftware();
    cout << "Ingrese el ID del software a agregar:" << endl;
    int numero;
    cin >> numero;
    //verificar que el numero sea valido y que no exista ya en la lista de software del usuario.
    if(bibliotecaSoftware[numero-1] != nullptr && !existirSoftwareEnListaUsuario(*bibliotecaSoftware[numero-1])){
        //si es administrador, se puede agregar cualquier software a su biblioteca.
        if(usuarioActual->getLog()){
            Software* software = bibliotecaSoftware[numero-1];
            usuarioActual->agregarSoftware(software);
            bibliotecaSoftware[numero-1]->agregarUsuario(usuarioActual->getNombre());
            cout << "Software agregado con exito." << endl;
            return;
        } 
        //revisar si el software tiene restriccion.
        else if(typeid(*bibliotecaSoftware[numero-1]) != typeid(Seguridad)){
            //si es nino, que sea para menores de 18.
            if(usuarioActual->getEdad() < 18 && bibliotecaSoftware[numero-1]->getRestriccion() < 18){
                Software* software = bibliotecaSoftware[numero-1];
                usuarioActual->agregarSoftware(software);
                bibliotecaSoftware[numero-1]->agregarUsuario(usuarioActual->getNombre());
                cout << "Software agregado con exito." << endl;
                return;
            } //si tiene restriccion pero el usuario es mayor de edad, lo puede agregar.
            else if(usuarioActual->getEdad() >= 18){
                Software* software = bibliotecaSoftware[numero-1];
                usuarioActual->agregarSoftware(software);
                bibliotecaSoftware[numero-1]->agregarUsuario(usuarioActual->getNombre());
                cout << "Software agregado con exito." << endl;
                return;
            }
        }
    }
    cout << "El software no pudo ser agregado." << endl;
}

//revisa si se puede eliminar el software de forma permanente, retorna true si puede hacerlo y false en caso contrario.
bool revisarEliminarSoftware(Software* softwareActual){
    //si el tamano de la lista de usuarios es 0, significa que ningun otro usuario lo usa y debe ser eliminado.
    if(softwareActual->getListaUsuariosSize() == 0){
        bibliotecaSoftware.erase(bibliotecaSoftware.begin()+buscarSoftware(softwareActual));
        return true;
    } 
    return false;
}

//elimina un software en la lista de softwares del usuario.
void eliminarSoftware(){
    //muestra los softwares posibles para eliminar.
    mostrarUsuarioSoftware();
    cout << "Ingrese el ID en tu biblioteca del software a eliminar:" << endl;
    int numero;
    cin >> numero;
    //revisar si el id del software existe.
    if(numero - 1 <= usuarioActual->getListaSoftwaresSize()){
        Software* softwareActual = usuarioActual->getSoftware(numero-1);
        //se revisa si se puede eliminar el usuario de la lista de usuarios del software.
        if(usuarioActual->getSoftware(numero-1)->eliminarUsuario(usuarioActual->getNombre())){
            //se elimina el software de los softwares del usuario.
            usuarioActual->eliminarSoftware(numero-1);
            cout << "El software fue eliminado con exito." << endl;
            cout << "Deseas que el software sea eliminado de forma permanente? (Se consultará a todos los usuarios que utilizan el software)\n1) Si.\n2) No." << endl;
            string opcion;
            cin >> opcion;
            if(opcion == "1"){
                //se verifica que pueda ser eliminado
                if(revisarEliminarSoftware(softwareActual)){
                    cout << "El software fue eliminado de forma permanente." << endl;
                } else {
                    cout << "Se seguirá consultando al resto de los usuarios." << endl;
                }
            } else if(opcion == "2"){
                cout << "El software no se eliminara de forma permanente." << endl;
            } else {
                cout << "Opcion invalida, retornando al menu." << endl;
            }
        } else {
            cout << "El software no pudo ser eliminado." << endl;
        }
    } else {
        cout << "El ID no es valido." << endl;
    }
}

//inicio sesion, verifica que el usuario exista, y que el usuario y la contrasena sean correctas.
bool login(){
    string nombre, password;
    cout << "Log in: " << endl;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Contrasena: ";
    cin >> password;
    //se recorren los usuarios.
    for(int i = 0; i < bibliotecaUsuario.size(); i++){
        //si el usuario existe.
        if(bibliotecaUsuario[i]->getNombre() == nombre){
            //si la contrasena es correcta.
            if(bibliotecaUsuario[i]->getPassword() == password){
                cout << "Iniciaste sesion." << endl;
                //en caso de acceder, pasa a ser el usuario actual.
                usuarioActual = bibliotecaUsuario[i];
                //se buscan los softwares que tiene el usuario.
                return true;
            } else {
                break;
            }
        }
    }
    cout << "Ingreso incorrecto.\n";
    return false;
}

//se accede a las opciones de ofimatica.
void accederOfimatica(Ofimatica* ofimatica){
    cout << "Bienvenido a " << ofimatica->getNombre() << endl;
    cout << "1) Crear Archivo.\n2) Eliminar Archivo.\n3) Ver cantidad de Archivos.\n4)Volver al menu." << endl;
    string opcion;
    cin >> opcion;
    if(opcion == "1"){
        //se crea un archivo.
        ofimatica->agregarArchivo();
        cout << "El archivo fue agregado." << endl;
        accederOfimatica(ofimatica);
    } else if(opcion == "2"){
        //se elimina un archivo.
        ofimatica->eliminarArchivo();
        cout << "El ultimo archivo fue eliminado." << endl;
        accederOfimatica(ofimatica);
    } else if(opcion == "3"){
        //se muestra la cantidad de archivos.
        cout << "La cantidad de archivos actual es " << ofimatica->getCantArchivos() << "." << endl;
        accederOfimatica(ofimatica);
    } else if(opcion == "4"){
        //retorna al menu.
        usuarioActual->agregarSoftware(ofimatica);
        cout << "Volviendo al menu." << endl;
    } else {
        usuarioActual->agregarSoftware(ofimatica);
        cout << "Opcion invalida, volviendo al menu." << endl;
    }
}

//se acceden a los softwares según su tipo.
void accederSoftware(){
    //se muestran los softwares del usuario.
    mostrarUsuarioSoftware();
    cout << "Ingrese el ID en tu biblioteca del software: ";
    int numero;
    cin >> numero;
    if(numero - 1 <= usuarioActual->getListaSoftwaresSize()){
        if(Juego* juego = dynamic_cast<Juego*> (usuarioActual->getSoftware(numero-1))){
            //se castea del tipo juego.
            cout << "Bienvenido a " << juego->getNombre() << ", no estoy implementado aun, lo sentimos." << endl;
        } else if(Ofimatica* ofimatica = dynamic_cast<Ofimatica*> (usuarioActual->getSoftware(numero-1))){
            //se castea del tipo ofimatica y se accede al software.
            usuarioActual->eliminarSoftware(numero-1);
            accederOfimatica(ofimatica);
        } else if(Produccion* produccion = dynamic_cast<Produccion*> (usuarioActual->getSoftware(numero-1))){
            //se castea del tipo produccion.
            cout << "Bienvenido a " << produccion->getNombre() << ", no estoy implementado aun, lo sentimos." << endl;
        } else if(Navegador* navegador = dynamic_cast<Navegador*> (usuarioActual->getSoftware(numero-1))){
            //se castea del tipo navegador.
            cout << "Bienvenido a " << navegador->getNombre() << ", no estoy implementado aun, lo sentimos." << endl;
        } else if(Seguridad* seguridad = dynamic_cast<Seguridad*> (usuarioActual->getSoftware(numero-1))){
            //se castea del tipo seguridad.
            cout << "Bienvenido a " << seguridad->getNombre() << ", no estoy implementado aun, lo sentimos." << endl;
        } else if(Social* social = dynamic_cast<Social*> (usuarioActual->getSoftware(numero-1))){
            //se castea del tipo social.
           cout << "Bienvenido a " << social->getNombre() << ", no estoy implementado aun, lo sentimos." << endl;
        }
    } else {
        cout << "Numero no valido." << endl;
    }
}

//funcion menu, redirige al resto de las opciones.
void menu(){
    string opcion;
    cout << "----- MENU -----" << endl;
    cout << "Seleccione una opcion: " << endl;
    cout << "1) Ver Softwares Usuario." << endl;
    cout << "2) Ver todos los Softwares." << endl;
    cout << "3) Agregar Software." << endl;
    cout << "4) Eliminar Software." << endl;
    cout << "5) Acceder a un Software." << endl;
    cout << "6) Log out. " << endl;
    cin >> opcion;
    if(opcion == "1"){
        mostrarUsuarioSoftware();
    } else if(opcion == "2"){
        mostrarTodosSoftware();
    } else if(opcion == "3"){
        agregarSoftware();
    } else if(opcion == "4"){
        eliminarSoftware();
    } else if(opcion == "5"){
        accederSoftware();
    } else if(opcion == "6"){
        cout << "Cerrando sesion." << endl;
        return;
    } else {
        cout << "Opcion invalida." << endl;
    }
    menu();
}

//consulta si volver a iniciar sesion o terminar el programa.
bool consultarLogIn(){
    cout << "Desea volver a iniciar sesion?\n1) Si. \n2) No." << endl;
    string opcion;
    cin >> opcion;
    if(opcion == "1") return true;
    else if(opcion == "2"){
        cout << "Adios." << endl;
    } else {
        cout << "Opcion invalida, adios." << endl;
    }
    return false;
}

int main()
{
    // poblar vector usuario (administrador).
    Usuario adm1("Juanito", "abcdef", 25, "juanitoperez@gmail.com", true);
    bibliotecaUsuario.push_back(&adm1);

    // poblar vector usuario (ninios).
    Usuario nin1("Florencia", "estrella2", 12, "", false);
    Usuario nin2("Matilda", "extraaa4", 14, "", false);
    Usuario nin3("Josefina", "shsh22", 16, "", false);
    Usuario nin4("Benjamin", "blanco24", 8, "", false);
    bibliotecaUsuario.push_back(&nin3);
    bibliotecaUsuario.push_back(&nin1);
    bibliotecaUsuario.push_back(&nin2);
    bibliotecaUsuario.push_back(&nin4);

    // poblar vector usuario (normales).
    Usuario nor1("Remi", "nose123", 20, "cvazqueztes@gmail.com", false);
    Usuario nor2("Joaquin", "tilino3000", 23, "joaquino40@gmail.com", false);
    Usuario nor3("Esperanza", "yogurt", 18, "espetz@gmail.com", false);
    Usuario nor4("Paola", "cachupines", 30, "paolacortes@gmail.com", false);
    Usuario nor5("Karim", "renacuajos22", 27, "karimmes@gmail.com", false);
    Usuario nor6("Carolina", "sakuras", 45, "caro.lina@gmail.com", false);
    Usuario nor7("Mateo", "motomoto6", 51, "teoteo@gmail.com", false);
    Usuario nor8("Lily", "vainilaDog5", 21, "lilycita@gmail.com", false);
    Usuario nor9("Agustin", "tiburoncin18", 19, "agusstd@gmail.com", false);
    Usuario nor10("Lia", "gravedad999", 34, "liaaa_2@gmail.com", false);
    bibliotecaUsuario.push_back(&nor1);
    bibliotecaUsuario.push_back(&nor2);
    bibliotecaUsuario.push_back(&nor3);
    bibliotecaUsuario.push_back(&nor4);
    bibliotecaUsuario.push_back(&nor5);
    bibliotecaUsuario.push_back(&nor6);
    bibliotecaUsuario.push_back(&nor7);
    bibliotecaUsuario.push_back(&nor8);
    bibliotecaUsuario.push_back(&nor9);
    bibliotecaUsuario.push_back(&nor10);

    //Poblar software juego FPS.
    Juego juego1("Counter-Strike", "Valve", 18, 9000, "FPS");
    Juego juego2("Fornite", "Epic_Games", 12, 0, "FPS");
    bibliotecaSoftware.push_back(&juego1);
    bibliotecaSoftware.push_back(&juego2);

    //Poblar software juego MMO.
    Juego juego3("Dungeon_&_Dragons", "SSG", 15, 10000, "MMO");
    Juego juego4("Guild_Wars", "ArenaNet", 14, 0, "MMO");
    bibliotecaSoftware.push_back(&juego3);
    bibliotecaSoftware.push_back(&juego4);

    //Poblar software juego Puzzle.
    Juego juego5("Solitario", "Winter", 8, 0, "Puzzle");
    Juego juego6("Mahjong", "Cokke", 8, 0, "Puzzle");
    bibliotecaSoftware.push_back(&juego5);
    bibliotecaSoftware.push_back(&juego6);

    //Poblar software juego Carrera.
    Juego juego7("Mario Kart", "Nintendo", 6, 50000, "Carrera");
    Juego juego8("Fall_Guys", "Epic_Games", 8, 0, "Carrera");
    bibliotecaSoftware.push_back(&juego7);
    bibliotecaSoftware.push_back(&juego8);

    //Poblar software juego Sandbox.
    Juego juego9("GTA", "Rockstar", 18, 60000, "Sandbox");
    Juego juego10("Minecraft", "Mojang", 6, 20000, "Sandbox");
    bibliotecaSoftware.push_back(&juego9);
    bibliotecaSoftware.push_back(&juego10);

    //Poblar software juego Accion.
    Juego juego11("Among_us", "Epic_Games", 18, 8000, "Accion");
    Juego juego12("Spider-Man", "Insomniac-Games", 12, 15000, "Accion");
    bibliotecaSoftware.push_back(&juego11);
    bibliotecaSoftware.push_back(&juego12);

    //Poblar software juego Arcade.
    Juego juego13("Pac-Man", "Atari", 6, 0, "Arcade");
    Juego juego14("Mortal-Kombat", "Super_Nintendo", 12, 20000, "Arcade");
    bibliotecaSoftware.push_back(&juego13);
    bibliotecaSoftware.push_back(&juego14);

    //Poblar software juego Deportes.
    Juego juego15("FIFA", "EA", 8, 40000, "Deportes");
    Juego juego16("Rocket_League", "Psyonix", 8, 0, "Deportes");
    bibliotecaSoftware.push_back(&juego15);
    bibliotecaSoftware.push_back(&juego16);

    //Poblar software juego Simulacion.
    Juego juego17("Los_Sims", "EA", 12, 3000, "Simulacion");
    Juego juego18("Goat_Simulator", "Coffee_Stain", 18, 0, "Simulacion");
    bibliotecaSoftware.push_back(&juego17);
    bibliotecaSoftware.push_back(&juego18);

    //Poblar software juego Estrategia.
    Juego juego19("TFT", "Riot_Games", 12, 0, "Estrategia");
    Juego juego20("Crusader_Kings", "Paradox", 18, 20000, "Estrategia");
    bibliotecaSoftware.push_back(&juego19);
    bibliotecaSoftware.push_back(&juego20);

    //Poblar software ofimatica.
    Ofimatica ofi1("Word", "Microsoft", 10, 5000);
    Ofimatica ofi2("Excel", "Microsoft", 10, 5000);
    Ofimatica ofi3("Zoom", "Zoom_Voice", 10, 0);
    Ofimatica ofi4("Google_Drive", "Google", 10, 0);
    Ofimatica ofi5("Slack", "Slack_Technologies", 14, 0);
    bibliotecaSoftware.push_back(&ofi1);
    bibliotecaSoftware.push_back(&ofi2);
    bibliotecaSoftware.push_back(&ofi3);
    bibliotecaSoftware.push_back(&ofi4);
    bibliotecaSoftware.push_back(&ofi5);

    //Poblar software produccion.
    Produccion prod1("YouTube", "Google", 18, 0, "Video");
    Produccion prod2("Spotify", "Spotify", 18, 3000, "Musica");
    Produccion prod3("Twitch", "Amazon", 18, 0, "Streaming");
    Produccion prod4("Snapchat", "Snap", 18, 0, "Fotos");
    bibliotecaSoftware.push_back(&prod1);
    bibliotecaSoftware.push_back(&prod2);
    bibliotecaSoftware.push_back(&prod3);
    bibliotecaSoftware.push_back(&prod4);

    //Poblar software navegador.
    Navegador nav1("Google_Chrome", "Google", 0, 0);
    Navegador nav2("Internet_Explorer", "Microsoft", 0, 0);
    bibliotecaSoftware.push_back(&nav1);
    bibliotecaSoftware.push_back(&nav2);

    //Poblar software seguridad.
    Seguridad seg1("Malwarebytes", "Malwarebytes", 0, 10000, "Ransomware");
    Seguridad seg2("Spybot", "Safer", 0, 0, "Spyware");
    Seguridad seg3("Norton_360", "Norton_360", 0, 30000, "Botnets");
    Seguridad seg4("Kaspersky", "Kaspersky", 0, 0, "Rootkits");
    Seguridad seg5("Herramienta_de_eliminacion", "Microsoft", 0, 0, "Gusano");
    Seguridad seg6("ESET_NOD32", "ESET", 0, 28000, "Troyanos");
    bibliotecaSoftware.push_back(&seg1);
    bibliotecaSoftware.push_back(&seg2);
    bibliotecaSoftware.push_back(&seg3);
    bibliotecaSoftware.push_back(&seg4);
    bibliotecaSoftware.push_back(&seg5);
    bibliotecaSoftware.push_back(&seg6);

    //Poblar software social.
    Social so1("Instagram", "Meta", 0, 0);
    Social so2("Twitter", "X", 18, 0);
    bibliotecaSoftware.push_back(&so1);
    bibliotecaSoftware.push_back(&so2);

    bool volverSesion = true;
    while(volverSesion){
        if(login()){
            menu();
        }
        //si se quiere iniciar sesion, se repite nuevamente el login.
        volverSesion = consultarLogIn();
    }
    
    return 0;
}