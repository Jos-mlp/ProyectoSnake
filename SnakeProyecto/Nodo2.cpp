#include "Nodo2.h"

Nodo2::Nodo2()
{
	this->punteo = 0;
	this->nombre = "";
	this->siguiente = nullptr;
}

void Nodo2::ModificarPunteo(int pts)
{
	this->punteo = pts;
}

void Nodo2::ModificarNombre(string nom)
{
	this->nombre = nom;
}

void Nodo2::ModificarSiguiente(Nodo2* sig)
{
	this->siguiente = sig;
}

int Nodo2::ObtenerPunteo()
{
	return this->punteo;
}

string Nodo2::ObtenerNombre()
{
	return this->nombre;
}

Nodo2* Nodo2::ObtenerSiguiente()
{
	return this->siguiente;
}
