#pragma once
class Nodo
{
private:
	int x, y;
	Nodo* siguiente;

public:
	Nodo();
	void ModificarSiguiente(Nodo*);
	void ModificarXyY(int, int);
	int ObtenerX();
	int ObtenerY();
	Nodo* ObtenerSiguiente();
};
