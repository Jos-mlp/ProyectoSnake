#pragma once
#include<string>
#include "Nodo2.h"

using namespace std;
class Lista
{
private:
	Nodo2* frente;
	Nodo2* fondo;
	int tamanio;
public:
	//constructor
	Lista();
	//Insertar
	void Insertar(string,int);
	//accesores
	string Recorrer();
};

