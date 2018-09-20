#ifndef AFFIN_H
#define AFFIN_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Affin{
private:
    int claveA,claveB,privada;
    string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ._-0123456789";
public:
    Affin();
    Affin(int,int);
    string cifrado(string);
    string descifrado(string);
    int modulo(int,int);
    int euclides(int,int);
    int euclides_extendido(int,int);
};

#endif // AFFIN_H
