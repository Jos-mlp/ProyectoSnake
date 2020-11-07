#include <iostream>
#include <allegro5/allegro.h>
#include "Ventana.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>


using namespace std;
//teclas
bool arriba = false, abajo = true, izquierda = false, derecha = false;
//juego ejecutado
bool ejecucion = true;
//menus
bool menu_inicio = true, menu_nivel = false,jugando=false;

void DesactivarComandos() {
	arriba = false;
	abajo = false;
	izquierda = false;
	derecha = false;

}

int main() {
	int x = 0, y = 0, x1 = 0, y1 = 0;

	//inicia el interfza visual, el mouse, las imagenes,las figuras primitivas, el teclado
	al_init();
	al_install_mouse();
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();

	//Crea el lienzo y lo genera de color blanco
	Ventana menu = Ventana(1500, 1000);

	//evento del tiempo 
	ALLEGRO_TIMER* segundosTimer = al_create_timer(1.00);
	//Eventos del mouse y teclado y del timer
	ALLEGRO_EVENT evento;
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(segundosTimer));
	al_start_timer(segundosTimer);
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(segundosTimer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	//carga las imagenes
	ALLEGRO_BITMAP* borrador = al_load_bitmap("Recursos/Borrador.jpg");
	//menu principal
	ALLEGRO_BITMAP* menu_default = al_load_bitmap("Recursos/menu_principal.jpg");
	ALLEGRO_BITMAP* menu_jugar = al_load_bitmap("Recursos/menu_jugar.jpg");
	ALLEGRO_BITMAP* menu_salir = al_load_bitmap("Recursos/menu_salir.jpg");
	//menu niveles
	ALLEGRO_BITMAP* nivel_default = al_load_bitmap("Recursos/menu_niveles.jpg");
	ALLEGRO_BITMAP* nivel_facil = al_load_bitmap("Recursos/niveles_facil.jpg");
	ALLEGRO_BITMAP* nivel_intermedio = al_load_bitmap("Recursos/niveles_intermedio.jpg");
	ALLEGRO_BITMAP* nivel_dificil = al_load_bitmap("Recursos/niveles_dificil.jpg");
	ALLEGRO_BITMAP* nivel_dinamico = al_load_bitmap("Recursos/niveles_dinamico.jpg");

	//mantiene en ejecucion el programa
	while (ejecucion == true) {
		//Inicializa la variable evento y le pasa el evento generado
		al_wait_for_event(event_queue, &evento);
		
	//funciones jugando
		if (jugando == true) {

			//timer evento
			if (evento.type == ALLEGRO_EVENT_TIMER) {
				if (evento.timer.source == segundosTimer) {
					if (abajo == true) {
						y1 = y1 + 55;

					}
					if (izquierda == true) {
						x1 = x1 - 55;
					}
					if (arriba == true) {
						y1 = y1 - 55;
					}
					if (derecha == true) {
						x1 = x1 + 55;
					}

				}
			}
			//imprime las imagenes y borra la pantalla
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(borrador, x1, y1, 0);

			//eventos del teclado y controla el gusanito
			if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (evento.keyboard.keycode)
				{
				case ALLEGRO_KEY_UP:
					DesactivarComandos();
					arriba = true;
					cout << "Felacha arriba" << endl;
					break;
				case ALLEGRO_KEY_DOWN:
					DesactivarComandos();
					abajo = true;
					cout << "Felacha abajo" << endl;
					break;
				case ALLEGRO_KEY_LEFT:
					DesactivarComandos();
					izquierda = true;
					cout << "Felacha izquierda" << endl;
					break;
				case ALLEGRO_KEY_RIGHT:
					DesactivarComandos();
					derecha = true;
					cout << "Felacha derecha" << endl;
					break;
				default:
					break;
				}
			}
		//funciones del menu 1
		}
		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			x = evento.mouse.x;
			y = evento.mouse.y;
			if (menu_inicio == true) {
				//sirve para detectar cuando se mueve el mouse y cuando es presionado



					//imprime las imagenes
				if (x > 305 && y > 495 && x < 1127 && y < 640) {
					al_draw_bitmap(menu_jugar, 0, 0, 0);
					//si el boton izquierdo del mouse es presionado se ejecuta el if
					if (evento.mouse.button & 1) {
						menu_inicio = false;
						menu_nivel = true;
					}
				}
				else if (x > 305 && y > 698 && x < 1127 && y < 842) {
					al_draw_bitmap(menu_salir, 0, 0, 0);
					//si el boton izquierdo del mouse es presionado se ejecuta el if
					if (evento.mouse.button & 1) {
						ejecucion = false;
					}
				}
				else {
					al_draw_bitmap(menu_default, 0, 0, 0);
				}


				//si el boton izquierdo del mouse es presionado se ejecuta el if
				if (evento.mouse.button & 1) {
					cout << "x:" << x << "  y:" << y << endl;



				}

			}
			else if (menu_nivel == true) {
				//sirve para detectar cuando se mueve el mouse y cuando es presionado
				if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					x = evento.mouse.x;
					y = evento.mouse.y;


					//imprime las imagenes
					if (x > 278 && y > 98 && x < 1140 && y < 273) {
						al_draw_bitmap(nivel_facil, 0, 0, 0);
						//si el boton izquierdo del mouse es presionado se ejecuta el if
						if (evento.mouse.button & 1) {
							menu.ModificarNivel(1);
							menu_nivel = false;
							jugando = true;
						}
					}
					else if (x > 278 && y > 313 && x < 1140 && y < 490) {
						al_draw_bitmap(nivel_intermedio, 0, 0, 0);
						//si el boton izquierdo del mouse es presionado se ejecuta el if
						if (evento.mouse.button & 1) {
							menu.ModificarNivel(2);
							menu_nivel = false;
							jugando = true;
						}
					}
					else if (x > 278 && y > 539 && x < 1140 && y < 715) {
						al_draw_bitmap(nivel_dificil, 0, 0, 0);
						//si el boton izquierdo del mouse es presionado se ejecuta el if
						if (evento.mouse.button & 1) {
							menu.ModificarNivel(3);
							menu_nivel = false;
							jugando = true;
						}
					}
					else if (x > 278 && y > 759 && x < 1140 && y < 935) {
						al_draw_bitmap(nivel_dinamico, 0, 0, 0);
						//si el boton izquierdo del mouse es presionado se ejecuta el if
						if (evento.mouse.button & 1) {
							menu.ModificarNivel(4);
							menu_nivel = false;
							jugando = true;
						}
					}
					else {
						al_draw_bitmap(nivel_default, 0, 0, 0);
					}

					//si el boton izquierdo del mouse es presionado se ejecuta el if
					if (evento.mouse.button & 1) {
						cout << "x:" << x << "  y:" << y << endl;



					}
				}



			}
		}
		al_flip_display();
	}
	return 0;
}

