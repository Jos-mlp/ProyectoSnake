#pragma once
#include"Nodo.h"
class Ventana
{
private:
	Nodo* frente, * fondo;
	int tamanio;
	int nivel=1;
	int puntos = 0;
	double velocidad=0;
	int aleatorioX=0;
	int aleatorioY=0;
	int frutas = 0;
	int tipo_fruta = 1;
public:
	//constructor
	Ventana(int, int);
	//Insertar, obtener y eliminar
	void InsertarFondo(int, int);
	Nodo* ObtenerFrente();
	Nodo* Eliminar();
	//modificadores
	void ModificarNivel(int);
	void ModificarPuntos(int);
	void ModificarFrutas(int);
	void ModificarCordenadas(int, int);
	void ReiniciarTamanio();
	void ReiniciarLista();
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
	int ObtenerNivel();



};

