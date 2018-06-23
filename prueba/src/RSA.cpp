#include "RSA.h"

RSA::RSA(){
    int aleatorio=RandomBnd(1000);
    ZZ numero1 = to_ZZ(aleatorio);
    while(!verificar_primo(numero1)){
        ZZ numero1 = to_ZZ(aleatorio);
    }
    ZZ numero2 = to_ZZ(aleatorio);
    while(!verificar_primo(numero2)){
        ZZ numero2 = to_ZZ(aleatorio);
    }
    ZZ N = numero1 * numero2;
    ZZ clave_publica = to_ZZ(aleatorio);
    ZZ Phi = (numero1-1)*(numero2-1);
    while(Euclides_Binario(clave_publica,Phi) != 1 && Phi < clave_publica){
            clave_publica = to_ZZ(aleatorio);
    }
    ZZ clave_privada = Inversa(clave_publica,Phi);
}

RSA::RSA(ZZ clave_publica2,ZZ num_N2){
    clave_publica=clave_publica2;
    num_N=num_N2;
}

bool RSA::verificar_primo(ZZ a){
    int temp=0;
    for(int i=1;i<(a+1);i++){
        if(Modulo_ZZ(a,(ZZ)i)==0){
            temp++;
        }
    }
    if(temp!=2){
        return 0;
    }else{
        return 1;
    }
}

string RSA::Cifrar(string mensaje)
{
    string mensaje_C;
    int tamanio_alfabeto=alfabeto.size();
    int temp1;
    for(int i=0;i<=mensaje.size();i++){
            ZZ num=to_ZZ(alfabeto.find(mensaje[i]));
            string posicion= zz_To_String(to_ZZ(alfabeto.find(alfabeto.find(tamanio_alfabeto)-1)));
            int temp2=zz_To_String(num).size();
            if(temp2<posicion.size()){
                mensaje_C+="0";
                temp2++;
            }
            mensaje_C+=zz_To_String(num);
    }
    /*
    int l_M = M.size();
		string MF;

		string M1;
		for(int i=0; i<l_M; i++) {
			int M2 = alfabeto.find(M[i]);
			string M3 = int_string(M2);
			M3 = AddZ(M3,l_a);
			M1+=M3;
		}

		M1 = AddW(M1,(d_n)-1);
		for(int i=0; i<(M1.size()/(d_n-1)); i++) {
			string b_str = M1.substr(i*(d_n-1),d_n-1);
			ZZ b_ZZ = string_ZZ(b_str);
			ZZ M4 = exp(b_ZZ,e,n);
			string M5 = ZZ_string(M4);
			M5 = AddZ(M5,d_n);
			MF+=M5;
		}

    */

    return mensaje_C;
}

string RSA::Descifrar(string mensaje)
{
    string mensaje_D;
    /*
        string C1;
		for(int i=0; i<(C.size()/d_n); i++) {
			string C2 = C.substr(i*d_n,d_n);
			ZZ C3 = string_ZZ(C2);
			ZZ C4 = RC(C3);
			string C5 = ZZ_string(C4);
			C5 = AddZ(C5,d_n-1);
			C1+=C5;
		}

		string CF;
		for(int i=0; i<C1.size()/l_a; i++) {
			string C6 = C1.substr(l_a*i,l_a);
			ZZ C7 = string_ZZ(C6);
			int pos = ZZ_int(C7);
			CF+=alfabeto[pos];
		}
    */
    return mensaje_D;
}
/*
vector<int> RSA::cifrar(string mensaje){
    vector<int> rpta;
    for(int i = 0; i < mensaje.size(); i++){
        rpta.push_back(alfabeto.find(mensaje[i]));
    }
    for(int i = 0; i < rpta.size(); i++){
        rpta[i] = potencia_i(rpta[i],pub,N);
    }
    return rpta;
}

string RSA::descifrar(vector<int>mensaje){
    string rpta;
    for(int i = 0; i < mensaje.size(); i++){
        rpta+= alfabeto[potencia_i(mensaje[i],priv,N)];
    }
    return rpta;
}
*/
