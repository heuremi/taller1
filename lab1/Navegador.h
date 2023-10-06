#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Software.h"
using namespace std;

class Navegador: public Software
{
private:
    vector<string> historial;

public:
    Navegador();
    Navegador(string, string, int, int);
    string getHistorial();
    void visitarPagina(string);
    string toString();
};

Navegador::Navegador():Software(){};
Navegador::Navegador(string nombre, string developer, int restriccion, int precio):Software(nombre, developer, restriccion, precio){};
string Navegador::getHistorial(){
    if(historial.empty()) return "No existe historial.";
    string nav = "";
    int tamanio = this -> historial.size();
    int valor = min(tamanio, 10);
    for(int i = valor; i >= 0; i--){
        nav += this -> historial[i] + "\n";
    }
    return nav;};
void Navegador::visitarPagina(string pagina){this -> historial.push_back(pagina);};
string Navegador::toString(){
    return "Tipo: Navegador, Nombre : " + nombre + ", Developer: " + developer + ", Edad recomendada: " + to_string(restriccion)+ ", Precio: " + to_string(precio);
};