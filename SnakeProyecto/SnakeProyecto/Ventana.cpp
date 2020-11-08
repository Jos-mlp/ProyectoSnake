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
}

void Ventana::ModificarPuntos(int pts)
{
	this->puntos = pts;
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
	this->aleatorioX = (rand() % 1445) + 45;
	return this->aleatorioX;
}

int Ventana::ObtenerAleatorioY()
{
	srand(time(NULL));
	this->aleatorioY = (rand() % 920) + 170;
	return aleatorioY;
}

int Ventana::ObtenerCantFrutas()
{
	return this->frutas;
}

int Ventana::ObtenerTipoFruta()
{
	return this->tipo_fruta;
}
