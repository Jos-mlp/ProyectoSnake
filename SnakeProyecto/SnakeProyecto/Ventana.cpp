#include "Ventana.h"
#include <allegro5/allegro.h>
#include <stdlib.h>
#include <time.h>



Ventana::Ventana(int ancho, int alto)
{
	ALLEGRO_DISPLAY* ventana = al_create_display(ancho, alto);
	al_set_window_title(ventana, "Snake Play");
}

void Ventana::ModificarNivel(int n)
{
	this->nivel = n;
	if (this->nivel == 1) {
		this->velocidad = 1.00;
	}
	else if (this->nivel == 2) {
		this->velocidad = 0.5;
	}
	else if (this->nivel == 3) {
		this->velocidad = 0.25;
	}
	else if (this->nivel == 4) {

	}
}

void Ventana::ModificarPuntos(int pts)
{
	this->puntos = this->puntos + pts;
}

void Ventana::ModificarFrutas()
{
	this->frutas++;
}


int Ventana::ObtenerPuntos()
{
	return this->puntos;
}

int Ventana::ObtenerAleatorioX()
{
	srand(time(NULL));
	this->aleatorioX = (rand() % 28) + 0;
	this->aleatorioX = 45 + (this->aleatorioX * 50);
	
	return this->aleatorioX;
}

int Ventana::ObtenerAleatorioY()
{
	srand(time(NULL));
	this->aleatorioY = (rand() % 15) + 0;
	this->aleatorioY = 170 + (this->aleatorioY * 50);

	return aleatorioY;
}

int Ventana::ObtenerCantFrutas()
{
	return this->frutas;
}

int Ventana::ObtenerTipoFruta()
{
	srand(time(NULL));
	this->tipo_fruta = (rand() % 20) + 1;
	//pinia [1 - 5]=1
	if (this->tipo_fruta == 1) {
		return 1;
	}
	//pera [6-15]
	if (this->tipo_fruta >=6 && this->tipo_fruta<=15) {
		return 2;
	}
	//Banano [16-35]
	if (this->tipo_fruta >= 16 && this->tipo_fruta <= 35) {
		return 3;
	}
	//fresa[36-60]
	if (this->tipo_fruta >= 36 && this->tipo_fruta <= 60) {
		return 4;
	}
	//Manzana[61-100]
	this->tipo_fruta = 5;
		
	return this->tipo_fruta;
}

double Ventana::ObtenerVelocidad()
{
	return this->velocidad;
}
