#ifndef RSA_H
#define RSA_H

#include "Functions.h"

class RSA {
private:
    ZZ Phi,numero1,numero2,N;
    ZZ clave_privada;
    string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ._-0123456789";
//funciones a prueba
    //void generador_semilla(int);
    //int porcentaje(int);
    //void generador(int,int,int,int,int);
public:
    ZZ num_N,clave_publica;
    int numero_a_cifrar,exponente;

    RSA();
    RSA(ZZ,ZZ);
    bool verificar_primo(ZZ);
    string Cifrar(string mensaje);
    string Descifrar(string mensaje);

};

#endif // RSA_H

