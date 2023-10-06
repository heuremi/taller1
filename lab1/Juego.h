#pragma once
#include <iostream>
#include "Software.h"
using namespace std;

class Juego: public Software
{
private:
    string genero;

public:
    Juego();
    Juego(string, string, int, int, string);
    string getGenero();
    void setGenero(string);
    string toString();
};

Juego::Juego():Software(){};
Juego::Juego(string nombre, string developer, int restriccion, int precio, string genero):Software(nombre, developer, restriccion, precio){
    this -> genero = genero;
};
string Juego::getGenero(){return this -> genero;};
void Juego::setGenero(string genero){this -> genero = genero;};
string Juego::toString(){
    return "Tipo: Juego, Nombre : " + nombre + ", Developer: " + developer + ", Edad recomendada: " + to_string(restriccion)+ ", Precio: " + to_string(precio) + ", Genero: " + genero;
};