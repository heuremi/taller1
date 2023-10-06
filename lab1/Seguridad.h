#pragma once
#include <iostream>
#include "Software.h"
using namespace std;

class Seguridad: public Software
{
private:
    string malware;

public:
    Seguridad();
    Seguridad(string, string, int, int, string);
    string getMalware();
    void setMalware(string);
    string toString();
};

Seguridad::Seguridad():Software(){};
Seguridad::Seguridad(string nombre, string developer, int restriccion, int precio, string malware):Software(nombre, developer, restriccion, precio){
    this -> malware = malware;
};
string Seguridad::getMalware(){return this -> malware;};
void Seguridad::setMalware(string malware){this -> malware = malware;};
string Seguridad::toString(){
    return "Tipo: Seguridad, Nombre : " + nombre + ", Developer: " + developer + ", Edad recomendada: " + to_string(restriccion)+ ", Precio: " + to_string(precio) + ", Malware: " + malware;
};