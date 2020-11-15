#pragma once
#include"Nodo.h"
class Ventana
{
private:
	Nodo* frente, * fondo;
	int tamanio;
	int nivel=1;
	int puntos = 0;
	bool velocidad=0;
	int aleatorioX=0;
	int aleatorioY=0;
	int frutas = 0;
	int tipo_fruta = 1;
public:
	//constructor
	Ventana(int, int);
	//Insertar y obtener
	void InsertarFondo(int, int);
	Nodo* ObtenerFrente();
	//modificadores
	void ModificarNivel(int);
	void ModificarPuntos(int);
	void ModificarFrutas(int);
	void ModificarCordenadas(int, int);
	//accesores
	int Obtener_x(Nodo*);
	int Obtener_y(Nodo*);
	Nodo* ObtenerNodoSiguiente(Nodo*);
	int ObtenerTamanio();
	int ObtenerPuntos();
	int ObtenerAleatorioX();
	int ObtenerAleatorioY();
	int ObtenerCantFrutas();
	int ObtenerTipoFruta();
	double ObtenerVelocidad();




};

