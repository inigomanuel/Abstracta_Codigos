#include "Affin.h"

Affin::Affin(){
    int tamanio_alfabeto=alfabeto.size();
    srand(time(NULL));

    while(euclides(claveA,tamanio_alfabeto)!=1){
        claveA=rand();
    }
    claveB=rand()%tamanio_alfabeto;

    privada=euclides_extendido(claveA,tamanio_alfabeto);
    cout<<"Su primera clave publica es: "<<claveA<<endl;
    cout<<"Su clave privada es: "<<privada<<endl;
    cout<<"Su segunda clave publica es: "<<claveB<<endl;
    cout<<"La clave de encriptacion es: "<<claveB<<endl;
}

Affin::Affin(int a,int b){
    int tamanio_alfabeto=alfabeto.size();
    this -> claveA = a;
    this -> claveB = b;
    privada=euclides_extendido(claveA,tamanio_alfabeto);
    cout<<"Su primera clave publica es: "<<claveA<<endl;
    cout<<"Su clave privada es: "<<privada<<endl;
    cout<<"Su segunda clave publica es: "<<claveB<<endl;
}

string Affin::cifrado(string mensaje){
    string mensaje_C;
    int tamanio_alfabeto=alfabeto.size();
    int temp1;
    for(int i=0;i<=mensaje.size();i++){
            int num=alfabeto.find(mensaje[i]);
            temp1=modulo(claveA*num+claveB,tamanio_alfabeto);
                    if(temp1>tamanio_alfabeto){
                        int temp2=modulo(temp1,tamanio_alfabeto);
                        mensaje_C+=alfabeto[temp2];
                    }
                    else{
                        mensaje_C+=alfabeto[temp1];
                    }
    }
    return mensaje_C;
}

string Affin::descifrado(string mensaje_C){
    string mensaje_D;
    int tamanio_alfabeto=alfabeto.size();
    for(int i=0;i<mensaje_C.size();i++){
        int num=alfabeto.find(mensaje_C[i]);
        num = num - claveB;
        if(num<0){
            num = alfabeto.size()+num;
        }
        num = num*privada;
        num = modulo(num,alfabeto.length());
        mensaje_D+=alfabeto[num];
    }
    return mensaje_D;
}

int Affin::modulo(int a, int b){
    int q=a/b;
    int r=a-q*b;
    if(r<0){
        r+=b;
    }
    return r;
}

int Affin::euclides(int a, int b){
    int numero,resto;
    while(a!=0 && b!=0){
        //cout<<"a: "<<a<<" "<<"b: "<<b<<endl;
        if(a>b){
        numero=a/b;
        resto=a-(numero*b);
        //cout<<"num: "<<numero<<" "<<"resto: "<<resto<<endl;
        }
        else{
            numero=b/a;
            resto=b-(numero*a);
            //cout<<"num: "<<numero<<" "<<"resto: "<<resto<<endl;
            b=a;
            a=resto;
        }
        if(resto==0){
            break;
        }
        a=b;
        b=resto;
    }
    return b;
}

int Affin::euclides_extendido(int a, int b){
    int r1=a, r2=b;
    int s1=1, s2=0;
    int t1=0, t2=1;
    int q,r,s,t;
    while(r2>0){
        q=r1/r2;

        r=r1-q*r2;
        r1=r2;
        r2=r;

        s=s1-q*s2;
        s1=s2;
        s2=s;

        t=t1-q*t2;
        t1=t2;
        t2=t;
    }
    if(s1<0){
        return modulo(s1,b);
    }
    else{
        return s1;
    }
}
