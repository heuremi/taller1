# Laboratorio 1

## Objetos creados en el main:


### USUARIOS 


Usuario administrador

adm1: {nombre:"Juanito"; contrasena:"abcdef"; edad:25; correo:"juanitoperez@gmail.com"; log:"true"}.


Usuario niño(4)

nin1: {nombre:"Florencia"; contrasena:"estrella2"; edad:12; correo:""; log:"false"}.

nin2: {nombre:"Matilda"; contrasena:"extraaa4"; edad:14; correo:""; log:"false"}.

nin3: {nombre:"Josefina"; contrasena:"shsh22"; edad:16; correo:""; log:"false"}.

nin4: {nombre:"Benjamin"; contrasena:"blanco24"; edad:8; correo:""; log:"false"}.


Usuario normal(10)

nor1: {nombre:"Remi"; contrasena:"nose123"; edad:20; correo:"cvazqueztes@gmail.com"; log:"false"}.

nor2: {nombre:"Joaquin"; contrasena:"tilino3000"; edad:23; correo:"joaquino40@gmail.com"; log:"false"}.

nor3: {nombre:"Esperanza"; contrasena:"yogurt"; edad:18; correo:"espetz@gmail.com"; log:"false"}.

nor4: {nombre:"Paola"; contrasena:"cachupines"; edad:30; correo:"paolacortes@gmail.com"; log:"false"}.

nor5: {nombre:"Karim"; contrasena:"renacuajos22"; edad:27; correo:"karimmes@gmail.com"; log:"false"}.

nor6: {nombre:"Carolina"; contrasena:"sakuras"; edad:45; correo:"caro.lina@gmail.com"; log:"false"}.

nor7: {nombre:"Mateo"; contrasena:"motomoto6"; edad:51; correo:"teoteo@gmail.com"; log:"false"}.

nor8: {nombre:"Lily"; contrasena:"vainilaDog5"; edad:21; correo:"lilycita@gmail.com"; log:"false"}.

nor9: {nombre:"Agustin"; contrasena:"tiburoncin18"; edad:19; correo:"agusstd@gmail.com"; log:"false"}.

nor10: {nombre:"Lia"; contrasena:"gravedad999"; edad:34; correo:"liaaa_2@gmail.com"; log:"false"}.


### SOFTWARES


Software Juego (20)

juego1: {nombre:"Counter-Strike"; developer:"Valve"; restriccion:18; precio:9000; genero:"FPS"}.

juego2: {nombre:"Fornite"; developer:"Epic_Games"; restriccion:12; precio:0; genero:"FPS"}.

juego3: {nombre:"Dungeon_&_Dragons"; developer:"SSG"; restriccion:15; precio:10000; genero:"MMO"}.

juego4: {nombre:"Guild_Wars"; developer:"ArenaNet"; restriccion:14; precio:0; genero:"MMO"}.

juego5: {nombre:"Solitario"; developer:"Winter"; restriccion:8; precio:0; genero:"Puzzle"}.

juego6: {nombre:"Mahjong"; developer:"Cokke"; restriccion:8; precio:0; genero:"Puzzle"}.

juego7: {nombre:"Mario Kart"; developer:"Nintendo"; restriccion:6; precio:50000; genero:"Carrera"}.

juego8: {nombre:"Fall_Guys"; developer:"Epic_Games"; restriccion:8; precio:0; genero:"Carrera"}.

juego9: {nombre:"GTA"; developer:"Rockstar"; restriccion:18; precio:60000; genero:"Sandbox"}.

juego10: {nombre:"Minecraft"; developer:"Mojang"; restriccion:6; precio:20000; genero:"Sandbox"}.

juego11: {nombre:"Among_us"; developer:"Epic_Games"; restriccion:18; precio:8000; genero:"Accion"}.

juego12: {nombre:"Spider-Man"; developer:"Insomniac-Games"; restriccion:12; precio:15000; genero:"Accion"}.

juego13: {nombre:"Pac-Man"; developer:"Atari"; restriccion:6; precio:0; genero:"Arcade"}.

juego14: {nombre:"Mortal-Kombat"; developer:"Super_Nintendo"; restriccion:12; precio:20000; genero:"Arcade"}.

juego15: {nombre:"FIFA"; developer:"EA"; restriccion:8; precio:40000; genero:"Deportes"}.

juego16: {nombre:"Rocket_League"; developer:"Psyonix"; restriccion:8; precio:0; genero:"Deportes"}.

juego17: {nombre:"Los_Sims"; developer:"EA"; restriccion:12; precio:3000; genero:"Simulacion"}.

juego18: {nombre:"Goat_Simulator"; developer:"Coffee_Stain"; restriccion:18; precio:0; genero:"Simulacion"}.

juego19: {nombre:"TFT"; developer:"Riot_Games"; restriccion:12; precio:0; genero:"Estrategia"}.

juego20: {nombre:"Crusader_Kings"; developer:"Paradox"; restriccion:18; precio:20000; genero:"Estrategia"}.


Software Ofimatica(5)

ofi1: {nombre:"Word"; developer:"Microsoft"; restriccion:10; precio:5000}.

ofi2: {nombre:"Excel"; developer:"Microsoft"; restriccion:10; precio:5000}.

ofi3: {nombre:"Zoom"; developer:"Zoom_Voice"; restriccion:10; precio:0}.

ofi4: {nombre:"Google_Drive"; developer:"Google"; restriccion:10; precio:0}.

ofi5: {nombre:"Slack"; developer:"Slack_Technologies"; restriccion:14; precio:0}.


Software Produccion(4)

prod1: {nombre:"YouTube"; developer:"Google"; restriccion:18; precio:0; tipoDeSolucion:"Video"}.

prod2: {nombre:"Spotify"; developer:"Spotify"; restriccion:18; precio:3000; tipoDeSolucion:"Musica"}.

prod3: {nombre:"Twitch"; developer:"Amazon"; restriccion:18; precio:0; tipoDeSolucion:"Streaming"}.

prod4: {nombre:"Snapchat"; developer:"Snap"; restriccion:18; precio:0; tipoDeSolucion:"Fotos"}.


Software Navegador(2)

nav1: {nombre:"Google_Chrome"; developer:"Google"; restriccion:0; precio:0}.

nav2: {nombre:"Internet_Explorer"; developer:"Microsoft"; restriccion:0; precio:0}.


Software Seguridad(6)

Seguridad seg1("Malwarebytes", "Malwarebytes", 0, 10000, "Ransomware").

seg1: {nombre:"Malwarebytes"; developer:"Malwarebytes"; restriccion:0; precio:10000; malware:"Ransomware"}.

seg2: {nombre:"Spybot"; developer:"Safer"; restriccion:0; precio:0; malware:"Spyware"}.

seg3: {nombre:"Norton_360"; developer:"Norton_360"; restriccion:0; precio:30000; malware:"Botnets"}.

seg4: {nombre:"Kaspersky"; developer:"Kaspersky"; restriccion:0; precio:0; malware:"Rootkits"}.

seg5: {nombre:"Herramienta_de_eliminacion"; developer:"Microsoft"; restriccion:0; precio:0; malware:"Gusano"}.

seg6: {nombre:"ESET_NOD32"; developer:"ESET"; restriccion:0; precio:28000; malware:"Troyanos"}.


Software Social(2)

so1: {nombre:"Instagram"; developer:"Meta"; restriccion:0; precio:0}.

so2: {nombre:"Twitter"; developer:"X"; restriccion:18; precio:0}.

## FUNCIONES DEL MAIN

mostrarUsuarioSoftware: Muestra los softwares del usuario actual. [void]

mostrarTodosSoftware: Muestra los softwares de la lista general de softwares. [void]

existirSoftwareEnListaUsuario(Software): Revisa si existe un software en la lista de softwares del usuario actual, retorna true en caso de ser encontrado y false en caso de no existir. [bool]

buscarSoftware(Software*): Busca un software en la lista general de softwares, retorna la posicion del software en la lista. [int]

buscarUsuario(string): Busca un usuario en la lista general de usuarios, retorna la posicion en la lista. [int]

agregarSoftware(): Agrega un software en la lista de softwares del usuario. [void]

revisarEliminarSoftware(Software*): Revisa si se puede eliminar el software de forma permanente, retorna true si puede hacerlo y false en caso contrario. [bool]

eliminarSoftware(): Elimina un software en la lista de softwares del usuario. [void]

login(): Inicio sesion, verifica que el usuario exista, y que el usuario y la contrasena sean correctas. [bool]

accederOfimatica(Ofimatica*): Se accede a las opciones de ofimatica. [void]

accederSoftware(): Se acceden a los softwares según su tipo. [void]

menu(): Funcion menu, redirige al resto de las opciones. [void]

## COMANDOS PARA INICIAR EL PROGRAMA DESDE LA TERMINAL

cd lab1

g++ -o main main.cpp

./main