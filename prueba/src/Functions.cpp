#include "Functions.h"

ZZ cero=to_ZZ("0");
ZZ menos_1=to_ZZ("-1");
ZZ uno=to_ZZ("1");
ZZ dos=to_ZZ("2");

ZZ Modulo_ZZ(ZZ a, ZZ b){
    ZZ q=a/b;
    ZZ r=a-q*b;
    if(r<0){
        r+=b;
    }
    return r;
}

int Modulo_enteros(int a, int b){
    int q=a/b;
    int r=a-q*b;
    if(r<0){
        r+=b;
    }
    return r;
}

ZZ Valor_Absoluto(ZZ a){
    if(a<cero){
        return a*menos_1;
    }
    else{
        return a;
    }
}

ZZ Euclides_Binario(ZZ a,ZZ b){
    ZZ aux=uno,t;
    while((a&1)==0&&(b&1)==0){
        a=a/dos;
        b=b/dos;
        aux=aux*dos;
    }
    while (a!=cero){
        while((a&1)==0){
            a=a/dos;
        }
        while((b&1)==0){
            b=b/dos;
        }
        t=(Valor_Absoluto(a-b))/dos;
        if(a>=b){a = t;}
        else {b = t;}
    }
    return aux*b;
}

ZZ Euclides_Extendido(ZZ a, ZZ b){
    ZZ q,r,r1,r2,s,s1,s2;
    s2=to_ZZ("0");
    s1=to_ZZ("1");
    r1=to_ZZ(a);
    r2=to_ZZ(b);
    while(r2>0){
        q=to_ZZ(r1/r2);

        r=to_ZZ(r1-q*r2);
        r1=to_ZZ(r2);
        r2=to_ZZ(r);

        s=to_ZZ(s1-q*s2);
        s1=to_ZZ(s2);
        s2=to_ZZ(s);
    }
    if(s1<0)
        return s1+abs(b);
    return s1;
}

ZZ Inversa(ZZ a,ZZ b){
    ZZ i=Euclides_Extendido(a,b);
    if(i<0){
        return Modulo_ZZ(i,b);
    }
    else{
        return i;
    }
}

ZZ Potencia(ZZ a,ZZ b,ZZ mod){
    ZZ resultado;
    resultado=1;
    ZZ temp;
    temp=1;
    while(b!=0){
        if((b&temp)==1){
            resultado = Multiplicacion_Modular(resultado,a, mod);
        }
        a = Multiplicacion_Modular(a, a, mod);
        b = b/2;
    }
    return resultado;
}

ZZ Multiplicacion_Modular(ZZ a,ZZ b,ZZ mod)
{
    return Modulo_ZZ((Modulo_ZZ(a, mod)*Modulo_ZZ(b,mod)), mod);
}

string zz_To_String(ZZ z) {
    stringstream buffer;
    buffer << z;
    return buffer.str();
}

ZZ String_To_zz(string p) {
    char oracion[10000];
    strcpy(oracion,p.c_str());
    return conv<ZZ>(oracion);
}

ZZ int_ZZ(int n){
	ZZ z;
	conv(z,n);
	return z;
}

int ZZ_int(ZZ z){
	int n;
	conv(n,z);
	return n;
}

bool miillerTest(ZZ d, ZZ n) {
	ZZ a = 2 + mod(rand(),(n-2));

	ZZ x = exp(a,d,n);

	if (x==1  or x==n-1)
		return true;

	while (d!=n-1) {
		x = mod((x*x),n);
		d<<=1;
		if(x==1) return false;
		if(x==n-1) return true;
	}
	return false;
}

bool isPrime(ZZ n, int k) {
	if (n<=1 or n==4)  return false;
	if (n<=3) return true;

	ZZ d = n-1;
	while((d&1)==0)
		d>>=1;

	for(int i=0; i<k; i++)
		if (miillerTest(d, n) == false)
			return false;
	return true;
}

/*
string AddZ(string bloque, int ndigit) {
	while(mod1(bloque.size(),ndigit) !=0) {
			bloque.insert(0,"0");
	}
	return bloque;
}

string AddW(string mensaje, int ndigit) {
	while(mod1(mensaje.size(),ndigit) !=0) {
			mensaje += "33";
	}
	return mensaje;
*/
