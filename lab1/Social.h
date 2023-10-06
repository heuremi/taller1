#pragma once
#include <iostream>
#include <vector>
#include "Software.h"
#include "Usuario.h"
using namespace std;

class Social: public Software
{
private:
    vector<Usuario> amigos;

public:
    Social();
    Social(string, string, int, int);
    string getAmigos();
    void agregarAmigo(Usuario);
    void eliminarAmigo(Usuario);
};

Social::Social():Software(){};
Social::Social(string nombre, string developer, int restriccion, int precio):Software(nombre, developer, restriccion, precio){};
string Social::getAmigos(){
    if(amigos.empty()) return "El usuario no tiene amigos.";
    string amistad = "";
    /*
    for(int i = 0; i < this -> amigos.size(); i++){
        amistad += ""; //arreglar eso
    } */
    return amistad;
};
void Social::agregarAmigo(Usuario amistad){this -> amigos.push_back(amistad);};
void Social::eliminarAmigo(Usuario amistad){
    /*
    for(int i = 0; i < amigos.size(); i++){
        if(amigos[i].getNombre() == amistad.getNombre()){
            //amigos.erase(i);
            return;
        }
    }
    */
    return;
};