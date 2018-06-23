#include "RSA.h"
#include "Functions.h"
#include <NTL/ZZ.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <bitset>
#include <vector>

//#include<windows.h>
//#include<winuser.h>

using namespace std;
using namespace NTL;

/*
std::string correr(std::string texto,int pos){
	int x = (texto[texto.length()-1]+pos)%2;
	for (int i = 0; i < texto.length()-1; ++i){
		texto[i] = texto[i + 1];
	}
	texto.erase(texto.length() - 1);
	texto += static_cast<std::ostringstream*>(&(std::ostringstream() << x))->str();
	return texto;
}
std::string chocoelear(std::string semillas, int Npart, int Nvuel, int bits, int pos){
	int i = 0;
	while (semillas.length() < bits){
		int x=(semillas[i] + semillas[i + 1]) % 2;
		semillas += static_cast<std::ostringstream*>(&(std::ostringstream() << x))->str(); ++i;
	}
	//std::cout << "Exito en extender semillas " << semillas << std::endl;
	int tamofpart = semillas.length()/Npart;
	int limite = tamofpart*Npart;
	int tN = Npart;
	while (Nvuel>0){
		//std::cout << "En el while" << std::endl;
		Npart = tN;
		for (i = 0; i < limite; i += (2*tamofpart)){
			//std::cout << "Inicia corrimiento " <<i<<" "<<limite<<" "<<tamofpart<<" "<<Npart<< std::endl;
			std::string temp = correr(semillas.substr(i, tamofpart),semillas[pos]);
			//std::cout << "A mitad del corrimiento" << std::endl;
			std::string tmp;
			if (tamofpart + i < limite){
				tmp = correr(semillas.substr(tamofpart + i, tamofpart), semillas[pos]);
			}
			//std::cout << "Buen corrimiento con " <<temp<<" "<<tmp<<"f"<< std::endl;
			if (Npart > 1){
				semillas.replace(i, tamofpart, tmp);
				semillas.replace(tamofpart + i, tamofpart, temp);
			}
			Npart-=2;
		}
		--Nvuel;
	}
	return semillas;
}

ZZ PrimeRand(int bits){
	POINT cursor;
	GetCursorPos(&cursor);
	std::string number;
	std::bitset<11> foo;
	std::bitset<11> fee;
	while (number.length()<(bits/2)){
		foo = cursor.x;
		fee = cursor.y;
		std::bitset<11> text = foo ^ fee;
		number = number + text.to_string<char, std::string::traits_type, std::string::allocator_type>();
		number = number + text.to_string<char, std::string::traits_type, std::string::allocator_type>();
		foo.reset();
		fee.reset();
	}
	//std::cout << "Obtencion de la semilla con exito " <<number<< std::endl;
	number = chocoelear(number, 3, 2, bits, rand() % 3);
	//std::cout<< "Exito " <<number.length()<< std::endl;
	number[0] = '1'; number[bits] = '1';
	//std::cout << number << std::endl;
	ZZ aleatorio=ZZ(0);
	for (int i = bits; i > -1; --i){
		ZZ chiffre = ZZ(1);
		if (number[i] == '1'){
			chiffre <<= (bits - i);
			aleatorio += chiffre;
		}
	}
	return aleatorio;
}
*/

void menu(){
    int proceso=1,operacion;
    while(proceso!=0){
        cout<<endl;
        cout<<endl;
        cout<<"\t    ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"<<endl;
        cout<<"\t    บ                         Bienvenido                      บ"<<endl;
        cout<<"\t    บ       Presione '0' Generar claves                       บ"<<endl;
        cout<<"\t    บ       Presione '1' Cifrar                               บ"<<endl;
        cout<<"\t    บ       Presione '2' Descifrar                            บ"<<endl;
        cout<<"\t    บ       Presione '3' para salir                           บ"<<endl;
        cout<<"\t    ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"<<endl;
        cin>>operacion;
        switch(operacion){
        case (0):{
            system("cls");
            cout<<"Generar Aleatorios"<<endl;
            proceso--;
            break;}
        case (1):{
            system("cls");
            cout<<"Cifrado"<<endl;
            proceso--;
            break;}
        case (2):{
            system("cls");
            cout<<"Descifrado"<<endl;
            proceso--;
            break;}
        case (3):{
            cout<<"Salida"<<endl;
            proceso--;
            system("cls");
            break;}
        }
    }
}

ZZ generar_semilla(){
    ZZ semilla;

    semilla=010101011110101;
    return semilla;
}

ZZ generator_linear(ZZ seed, ZZ a, ZZ c, int num_vueltas){

    ZZ valor;
    for(int i=1;i<num_vueltas;i++){
        valor=(a*seed+c)%2;
        seed=valor;
    }

    return valor;
}
/*
ZZ particiones(pos_aleatorio){

}
*/
int main(){
    /*
    ZZ a,b,c,bits,pos_aleatorio;
    a=generar_semilla();
    b=11010101010101;
    c=110010101010101;
    cout<<generator_linear(a,b,c,9);
*/
    menu();


/*
string nombre;
cout << "ingrese el nombre a escribir en el blog de notas y presione enter" << endl;
cin >> nombre;
ofstream archivo;
archivo.open("Nombre.txt");
archivo << nombre;
cout << "El nombre se ha guardado satisfactoriamente, debe abrir el archivo Nombre.txt en la carpeta del programa para ver los resultados" << endl;
system("pause>>null");

string nombre;
string pass;
string correo;
int edad;
string web;
cout << "Ingrese su nombre de usuario" << endl;
cin >> nombre;
cout << "Ingrese la contrasena que desea para su cuenta" << endl;
cin >> pass;
cout << "Ingrese su correo electronico" << endl;
cin >> correo;
cout << "Ingrese su edad" << endl;
cin >> edad;
cout << "Ingrese su direccion web" << endl;
cin >> web;
ofstream archivo;
archivo.open("Registro.txt");
archivo << "Nombre de usuario: " <<  nombre << endl;
archivo << "Contrasena: " << pass << endl;
archivo << "Correo electronico: " << correo << endl;
archivo << "Edad: " << edad << endl;
archivo << "Direccion web: " << web << endl;
cout << "El registro de usuario se ha realizado satisfactoriamente, debe abrir el archivo Registro.txt en la carpeta del programa para ver los datos almacenados." << endl;
system("pause>>null");
*/
    return 0;
}
