#pragma once
#include <iostream>
#include <vector>
#include "Software.h"
using namespace std;

class Ofimatica: public Software
{
private:
    int cantArchivos;

public:
    Ofimatica();
    Ofimatica(string, string, int, int);
    int getCantArchivos();
    void agregarArchivo();
    void eliminarArchivo();
};

Ofimatica::Ofimatica():Software(){};
Ofimatica::Ofimatica(string nombre, string developer, int restriccion, int precio):Software(nombre, developer, restriccion, precio){
    this -> cantArchivos = 0; 
};
int Ofimatica::getCantArchivos(){return this -> cantArchivos;};
void Ofimatica::agregarArchivo(){this -> cantArchivos++;};
void Ofimatica::eliminarArchivo(){this -> cantArchivos--;};