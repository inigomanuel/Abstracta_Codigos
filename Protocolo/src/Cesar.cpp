#include "Cesar.h"

Cesar::Cesar(int clave1){
    clave1 = clave;
    alfabeto = "abcdefghijklmnopqrstuvwxyz ";
	len = alfabeto.size();
}

int Cesar::modulo(int a, int b){
	int r, q;
	q = a/b;
	r = a-(b*q);
	if(r<0){return r+b;}
	return r;
}

string Cesar::cifrar(string mensaje, int clave1) {
    for(int i=0; i<mensaje.size(); i++) {
        int d = modulo(alfabeto.find(mensaje[i])+clave1,len);
        mensaje[i] = alfabeto[d];
    }
    return mensaje;
}

string Cesar::descifrar(string mensaje, int clave1) {
    for(int i=0; i<mensaje.size() ;i++) {
        int d = modulo(alfabeto.find(mensaje[i])-clave1,len);
        mensaje[i] = alfabeto[d];
    }
    return mensaje;
}

