#pragma once
#include <iostream>
#include <vector>
#include "Software.h"
#include "Usuario.h"
using namespace std;

class Social: public Software
{
private:
    vector<string> amigos;

public:
    Social();
    Social(string, string, int, int);
    string getAmigos();
    void agregarAmigo(string);
    void eliminarAmigo(string);
    string toString();
};

Social::Social():Software(){};
Social::Social(string nombre, string developer, int restriccion, int precio):Software(nombre, developer, restriccion, precio){};
string Social::getAmigos(){
    if(amigos.empty()) return "El usuario no tiene amigos.";
    string amistad = "";
    for(int i = 0; i < this -> amigos.size(); i++){
        amistad += amigos[i] + "\n"; //arreglar eso
    }
    return amistad;
};
void Social::agregarAmigo(string amistad){this -> amigos.push_back(amistad);};
void Social::eliminarAmigo(string amistad){
    for(int i = 0; i < amigos.size(); i++){
        if(amigos[i] == amistad){
            amigos.erase(amigos.begin()+i);
            return;
        }
    }
    return;
};
string Social::toString(){
    return "Tipo: Social, Nombre : " + nombre + ", Developer: " + developer + ", Edad recomendada: " + to_string(restriccion)+ ", Precio: " + to_string(precio);
}