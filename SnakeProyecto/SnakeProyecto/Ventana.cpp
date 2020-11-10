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
	this->puntos = pts;
}

void Ventana::ModificarFrutas()
{
	this->frutas++;
}

void Ventana::ModificarVelocidad(int vel)
{
	this->velocidad = vel;
}

int Ventana::ObtenerPuntos()
{
	return this->puntos;
}

int Ventana::ObtenerAleatorioX()
{
	srand(time(NULL));
	this->aleatorioX = (rand() % 1495) + 45;

	if (this->aleatorioX >= 45 && aleatorioX < 96) {
		this->aleatorioX = 45;
	}
	else if (this->aleatorioX >= 96 && aleatorioX < 146) {
		this->aleatorioX = 95;
	}
	else if (this->aleatorioX >= 146 && aleatorioX < 196) {
		this->aleatorioX = 145;
	}
	else if (this->aleatorioX >= 196 && aleatorioX < 246) {
		this->aleatorioX = 195;
	}
	else if (this->aleatorioX >= 246 && aleatorioX < 296) {
		this->aleatorioX = 245;
	}
	else if (this->aleatorioX >= 296 && aleatorioX < 346) {
		this->aleatorioX = 295;
	}
	else if (this->aleatorioX >= 346 && aleatorioX < 396) {
		this->aleatorioX = 345;
	}
	else if (this->aleatorioX >= 396 && aleatorioX < 446) {
		this->aleatorioX = 395;
	}
	else if (this->aleatorioX >= 446 && aleatorioX < 496) {
		this->aleatorioX = 445;
	}
	else if (this->aleatorioX >= 496 && aleatorioX < 546) {
		this->aleatorioX = 495;
	}
	else if (this->aleatorioX >= 546 && aleatorioX < 596) {
		this->aleatorioX = 545;
	}
	else if (this->aleatorioX >= 596 && aleatorioX < 646) {
		this->aleatorioX = 595;
	}
	else if (this->aleatorioX >= 646 && aleatorioX < 696) {
		this->aleatorioX = 645;
	}
	else if (this->aleatorioX >= 696 && aleatorioX < 746) {
		this->aleatorioX = 695;
	}
	else if (this->aleatorioX >= 746 && aleatorioX < 796) {
		this->aleatorioX = 745;
	}
	else if (this->aleatorioX >= 796 && aleatorioX < 846) {
		this->aleatorioX = 795;
	}
	else if (this->aleatorioX >= 846 && aleatorioX < 896) {
		this->aleatorioX = 845;
	}
	else if (this->aleatorioX >= 896 && aleatorioX < 946) {
		this->aleatorioX = 895;
	}
	else if (this->aleatorioX >= 946 && aleatorioX < 996) {
		this->aleatorioX = 945;
	}
	else if (this->aleatorioX >= 996 && aleatorioX < 1046) {
		this->aleatorioX = 995;
	}
	else if (this->aleatorioX >= 1046 && aleatorioX < 1096) {
		this->aleatorioX = 1045;
	}
	else if (this->aleatorioX >= 1096 && aleatorioX < 1146) {
		this->aleatorioX = 1095;
	}
	else if (this->aleatorioX>= 1146 && aleatorioX < 1196) {
		this->aleatorioX = 1145;
	}
	else if (this->aleatorioX >= 1196 && aleatorioX < 1246) {
		this->aleatorioX = 1195;
	}
	else if (this->aleatorioX >= 1246 && aleatorioX < 1296) {
		this->aleatorioX = 1245;
	}
	else if (this->aleatorioX >= 1296 && aleatorioX < 1346) {
		this->aleatorioX = 1295;
	}
	else if (this->aleatorioX >= 1346 && aleatorioX < 1396) {
		this->aleatorioX = 1345;
	}
	else if (this->aleatorioX >= 1396 && aleatorioX < 1446) {
		this->aleatorioX = 1395;
	}
	else if (this->aleatorioX >= 1446 && aleatorioX < 1496) {
		this->aleatorioX = 1445;
	}


	return this->aleatorioX;
}

int Ventana::ObtenerAleatorioY()
{
	srand(time(NULL));
	this->aleatorioY = (rand() % 970) + 170;
	if (this->aleatorioY >= 170 && aleatorioY < 221) {
		this->aleatorioY = 170;
	}
	else if (this->aleatorioY >= 221 && aleatorioY < 271) {
		this->aleatorioY = 220;
	}
	else if (this->aleatorioY >= 271 && aleatorioY < 321) {
		this->aleatorioY = 270;
	}
	else if (this->aleatorioY >= 321 && aleatorioY < 371) {
		this->aleatorioY = 320;
	}
	else if (this->aleatorioY >= 371 && aleatorioY < 421) {
		this->aleatorioY = 370;
	}
	else if (this->aleatorioY >= 421 && aleatorioY < 471) {
		this->aleatorioY = 420;
	}
	else if (this->aleatorioY >= 471 && aleatorioY < 521) {
		this->aleatorioY = 470;
	}
	else if (this->aleatorioY >= 521 && aleatorioY < 571) {
		this->aleatorioY = 520;
	}
	else if (this->aleatorioY >= 571 && aleatorioY < 621) {
		this->aleatorioY = 570;
	}
	else if (this->aleatorioY >= 621 && aleatorioY < 671) {
		this->aleatorioY = 620;
	}
	else if (this->aleatorioY >= 671 && aleatorioY < 721) {
		this->aleatorioY = 670;
	}
	else if (this->aleatorioY >= 721 && aleatorioY < 771) {
		this->aleatorioY = 720;
	}
	else if (this->aleatorioY >= 771 && aleatorioY < 821) {
		this->aleatorioY = 770;
	}
	else if (this->aleatorioY >= 821 && aleatorioY < 871) {
		this->aleatorioY = 820;
	}
	else if (this->aleatorioY >= 871 && aleatorioY < 921) {
		this->aleatorioY = 870;
	}
	else if (this->aleatorioY >= 921 && aleatorioY < 971) {
		this->aleatorioY = 921;
	}


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

double Ventana::ObtenerVelocidad()
{
	return this->velocidad;
}
