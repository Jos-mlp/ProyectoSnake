#pragma once
#include"Nodo.h"
class Ventana
{
private:
	Nodo* frente, * fondo;
	int tamanio;
	int nivel=1;
	int puntos = 0;
	double velocidad=1;
	int aleatorioX=0;
	int aleatorioY=0;
	int frutas = 0;
	int tipo_fruta = 1;
	//valores maximos
	int punteomax = 0;
	int frutasmax = 0;
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
	void ReiniciarPuntos();
	void ReiniciarCantFruta();
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
	double ObtenerYmodificarVelocidadN4();
	int ObtenerNivel();
	//Modificadores y accesores de los maximos
	void ModificarMaximos(int, int);
	int ObtenerPuntosMax();
	int ObtenerFrutosMax();
};

