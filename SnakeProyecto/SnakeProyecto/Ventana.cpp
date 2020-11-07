#include "Ventana.h"
#include <allegro5/allegro.h>

Ventana::Ventana(int ancho, int alto)
{
	ALLEGRO_DISPLAY* ventana = al_create_display(ancho, alto);
	al_set_window_title(ventana, "Snake Play");
}

void Ventana::ModificarNivel(int n)
{
	this->nivel = n;
}
