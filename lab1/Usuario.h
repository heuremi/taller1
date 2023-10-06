#pragma once
#include <iostream>
#include <vector>
#include "Software.h"
using namespace std;

class Usuario
{
private:
    string nombre;
    string password;
    int edad;
    string correo;
    bool log;

public:
    Usuario();
    Usuario(string, string, int, string, bool);
    string getNombre();
    string getPassword();
    int getEdad();
    string getCorreo();
    bool getLog();
    void setNombre(string);
    void setPassword(string);
    void setEdad(int);
    void setCorreo(string); 
    void setLog(bool);
};

Usuario::Usuario(){};
Usuario::Usuario(string nombre, string password, int edad, string correo, bool log){
    this -> nombre = nombre;
    this -> password = password;
    this -> edad = edad;
    this -> correo = correo;
    this -> log = log;
};
string Usuario::getNombre(){
    return this -> nombre;
};
string Usuario::getPassword(){
    return this -> password;
};
int Usuario::getEdad(){
    return this -> edad;
};
string Usuario::getCorreo(){
    return this -> correo;
};
bool Usuario::getLog(){
    return this -> log;
}

void Usuario::setNombre(string nombre){this -> nombre = nombre;};
void Usuario::setPassword(string password){this -> password = password;};
void Usuario::setEdad(int edad){this -> edad = edad;};
void Usuario::setCorreo(string correo){this -> correo = correo;};
void Usuario::setLog(bool log){this -> log = log;};