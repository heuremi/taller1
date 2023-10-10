#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Software
{
public:
    string nombre;
    string developer;
    int restriccion;
    vector<string> listaNombreUsuarios; 
    int precio;

//public:
    Software();
    Software(string, string, int, int);
    string getNombre();
    string getDeveloper();
    int getRestriccion();
    int getPrecio();
    string getNombreUsuario(int);
    int getListaUsuariosSize();
    void setNombre(string);
    void setDeveloper(string);
    void setRestriccion(int);
    void setPrecio(int);
    void agregarUsuario(string); 
    bool eliminarUsuario(string);
    virtual string toString();
};

Software::Software(){};
Software::Software(string nombre, string developer, int restriccion, int precio){
    this -> nombre = nombre;
    this -> developer = developer;
    this -> restriccion = restriccion;
    this -> precio = precio;
};
string Software::getNombre(){
    return this -> nombre;
};
string Software::getDeveloper(){
    return this -> developer;
};
int Software::getRestriccion(){
    return this -> restriccion;
};
int Software::getPrecio(){
    return this -> precio;
};
string Software::getNombreUsuario(int i){
    return this -> listaNombreUsuarios[i];
};
int Software::getListaUsuariosSize(){
    return this-> listaNombreUsuarios.size();
};
void Software::setNombre(string nombre){this -> nombre = nombre;};
void Software::setDeveloper(string developer){this -> developer = developer;};
void Software::setRestriccion(int restriccion){this -> restriccion = restriccion;};
void Software::setPrecio(int precio){this -> precio = precio;};
void Software::agregarUsuario(string nombreUsuario){this -> listaNombreUsuarios.push_back(nombreUsuario);};
bool Software::eliminarUsuario(string nombreUsuario){
    for(int i = 0; i < this->listaNombreUsuarios.size(); i++){
        if(this -> listaNombreUsuarios[i] == nombreUsuario){
            this->listaNombreUsuarios.erase(listaNombreUsuarios.begin() + i);
            return true; // Usuario encontrado y eliminado, devuelve true
        }
    }
    return false; // Usuario no encontrado, devuelve false
};
string Software::toString(){
    return "Nombre : " + nombre + ", Developer: " + developer + ", Edad recomendada: " + to_string(restriccion) + ", Precio: " + to_string(precio);
};