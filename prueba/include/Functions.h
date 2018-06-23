#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <NTL/ZZ.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace NTL;

ZZ Modulo_ZZ(ZZ,ZZ);
int Modulo_enteros(int,int);
ZZ Valor_Absoluto(ZZ);
ZZ Euclides_Binario(ZZ,ZZ);
ZZ Euclides_Extendido(ZZ,ZZ);
ZZ Inversa(ZZ,ZZ);
ZZ Potencia(ZZ,ZZ,ZZ);
ZZ Multiplicacion_Modular(ZZ,ZZ,ZZ);

string zz_To_String(ZZ);
ZZ String_To_zz(string p);
ZZ int_ZZ(int n);
int ZZ_int(ZZ z);

bool miillerTest(ZZ,ZZ);
bool isPrime(ZZ,int);

#endif // FUNCTIONS_H
