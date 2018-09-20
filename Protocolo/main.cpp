#include <iostream>

#include "Cesar.h"
#include "Enigma.h"
#include "Affin.h"
#include "Administrador.h"

using namespace std;

int main(){
    /*
    ///Cesar
    int clave;
	string M;
	Cesar E(clave);
	Cesar R(clave);
	cout<<"Mensaje: "<<endl;
	getline(cin,M);
	cout<<"Clave: "<<endl;
	cin>>clave;
	string C = E.cifrar(M,clave);
	string D = R.descifrar(C,clave);
	cout<<"Mensaje Cifrado: "<< C <<endl;
	cout<<"Mensaje Descifrado: "<< D <<endl;
	*/

	///Enigma
	string msn="GATOS";
    Enigma receptor(1,2,3,"AAA");
    string ci=receptor.cifrado(msn);
    string dc=receptor.descifrado(ci);

	///Affin
    /*
    affin aff;
    string mensaje="Cause you brought out the best of me, A part of me I'd never seen, You took my soul wiped it clean, Our love was made for movie screens......pq te fuiste? alv 162-10-38585 Inigo Diez Canseco";
    cout<<aff.cifrado(mensaje)<<endl;
    cout<<""<<endl;


    string mensaje_cifrada="TDn4 QWJcDap2Jj0SS4n J4nJSDr2JP2WJ62J DJnDHJTQ4FJj22S4n FJW20p4n J62JaUJN2p2JH2J DJnDHJkDHJ4jJFQ2JOD2FJ4WJS4B2JWQ4FJE4SSJcDaJODJ4WJS4B2JWQ0WJkDHJ4jJFQ2JWDayQ2FJS4B2JWQ4FJE4SSJcDaJWDayQJQ2pJS4B2JWQ0WJkDHJ4jJFQ2J6Dr2FJS4B2JWQ4FJE4SSJcDaJ6Dr2JQ2pJS4B2JWQ0WJvD62JDnJFQ0B2JFQ0B2JCQ0B2JFQ0B2JFQ0B2J4WJR0Wp4yBJV0r42pJ30p8a2tJvQD8a2JI_IbIsbdfZudJ62JF42nWDJUpDOayW4rDJODFJUanWDFJah2";
    int a=17;
    int b=56;
    Affin Aff2(a,b);
    cout<<Aff2.descifrado(mensaje_cifrada)<<endl;
    */

    return 0;
}
