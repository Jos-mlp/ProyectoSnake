#pragma once
#include<string>
using namespace std;
class Nodo2
{
private:
	int punteo;
	string nombre;
	Nodo2* siguiente;
public:
	//constructor
	Nodo2();
	//Modificadores
	void ModificarPunteo(int);
	void ModificarNombre(string);
	void ModificarSiguiente(Nodo2*);
	//accesores
	int ObtenerPunteo();
	string ObtenerNombre();
	Nodo2* ObtenerSiguiente();
};

