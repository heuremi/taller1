#pragma once
#include <iostream>
#include "Software.h"
using namespace std;

class Produccion: public Software
{
private:
    string tipoDeSolucion;

public:
    Produccion();
    Produccion(string, string, int, int, string);
    string getTipoDeSolucion();
    void setTipoDeSolucion(string);
};

Produccion::Produccion():Software(){};
Produccion::Produccion(string nombre, string developer, int restriccion, int precio, string tipoDeSolucion):Software(nombre, developer, restriccion, precio){
    this -> tipoDeSolucion = tipoDeSolucion;
};
string Produccion::getTipoDeSolucion(){return this -> tipoDeSolucion;};
void Produccion::setTipoDeSolucion(string tipoDeSolucion){this -> tipoDeSolucion = tipoDeSolucion;};