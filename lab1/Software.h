#pragma once
#include <iostream>
#include <vector>
#include "Usuario.h"
using namespace std;

class Software
{
private:
    string nombre;
    string developer;
    int restriccion;
    vector<Usuario> listaUsuarios; 
    int precio;

public:
    Software();
    Software(string, string, int, int);
    string getNombre();
    string getDeveloper();
    int getRestriccion();
    int getPrecio();
    string getListaUsuarios();
    void setNombre(string);
    void setDeveloper(string);
    void setRestriccion(int);
    void setPrecio(int);
    void agregarUsuario(Usuario); 
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
string Software::getListaUsuarios(){
    int usuarioSize = this -> listaUsuarios.size();
    string usuarios = "";
    for(int i = 0; i < usuarioSize; i++){
        usuarios += "arreglar"; //ARREGLAR !!!!!!!
    }
    return usuarios;
};
void Software::setNombre(string nombre){this -> nombre = nombre;};
void Software::setDeveloper(string developer){this -> developer = developer;};
void Software::setRestriccion(int restriccion){this -> restriccion = restriccion;};
void Software::setPrecio(int precio){this -> precio = precio;};
void Software::agregarUsuario(Usuario usuario){ //CAMBIAR TIPOOOO
    this -> listaUsuarios.push_back(usuario);
};