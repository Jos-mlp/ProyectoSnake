#include "Nodo.h"

Nodo::Nodo()
{
	this->x = 0;
	this->y = 0;
	this->siguiente = nullptr;
}

void Nodo::ModificarSiguiente(Nodo* sig)
{
	this->siguiente = sig;
}

void Nodo::ModificarXyY(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Nodo::ObtenerX()
{
	return this->x;
}

int Nodo::ObtenerY()
{
	return this->y;
}

Nodo* Nodo::ObtenerSiguiente()
{
	return this->siguiente;
}