#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "Affin.h"
#include "Cesar.h"
#include "Enigma.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#define tamaho alfabeto.length()
using namespace std;

class Administrador{
private:


public:
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    Administrador();

    string Encriptado(string);



};

#endif // ADMINISTRADOR_H
