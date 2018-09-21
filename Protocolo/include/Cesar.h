#ifndef CESAR_H
#define CESAR_H

#include <iostream>
#include <string>

using namespace std;

class Cesar{
private:
    int clave;
    string alfabeto;
public:
    int len;

    Cesar(int,string);
    int modulo(int,int);
    string cifrar(string,int);
    string descifrar(string,int);
};

#endif // CESAR_H
