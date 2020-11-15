#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include "Ventana.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdlib.h>
#include <time.h>


using namespace std;
//teclas
bool arriba = false, abajo = true, izquierda = false, derecha = false;
//juego ejecutado
bool ejecucion = true, fruta_generada = false;
int tipo_fruta;
//menus
bool menu_inicio = true, menu_nivel = false, jugando = false;

void DesactivarComandos() {
	arriba = false;
	abajo = false;
	izquierda = false;
	derecha = false;

}



int main() {
	srand(time(NULL));
	//variables de movimiento
	int x = 0, y = 0, x1 = 45, y1 = 170, fx, fy;
	//inicia el interfza visual, el mouse, las imagenes,las figuras primitivas, el teclado
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();

	//Crea el lienzo y lo genera de color blanco
	Ventana menu = Ventana(1500, 1000);
	//carga la fuente para el texto
	ALLEGRO_FONT* mainkra = al_load_font("Recursos/mine.ttf", 100, 0);
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
	//del juego en ejecucion
	ALLEGRO_BITMAP* fondo_juego = al_load_bitmap("Recursos/juego_fondo.jpg");
	ALLEGRO_BITMAP* c_i = al_load_bitmap("Recursos/cabeza_izquierda.jpg");
	ALLEGRO_BITMAP* c_d = al_load_bitmap("Recursos/cabeza_derecha.jpg");
	ALLEGRO_BITMAP* c_b = al_load_bitmap("Recursos/cabeza_abajo.jpg");
	ALLEGRO_BITMAP* c_a = al_load_bitmap("Recursos/cabeza_arriba.jpg");
	ALLEGRO_BITMAP* cuerpo_Snake = al_load_bitmap("Recursos/cuerpo.jpg");
	//imagenes de las frutas
	ALLEGRO_BITMAP* manzana = al_load_bitmap("Recursos/Manzana.png");
	ALLEGRO_BITMAP* pinia = al_load_bitmap("Recursos/pinia.png");
	ALLEGRO_BITMAP* pera = al_load_bitmap("Recursos/Pera.png");
	ALLEGRO_BITMAP* fresa = al_load_bitmap("Recursos/fresa.png");
	ALLEGRO_BITMAP* banano = al_load_bitmap("Recursos/Banano.png");

	//mantiene en ejecucion el programa
	while (ejecucion == true) {
		//Inicializa la variable evento y le pasa el evento generado
		al_wait_for_event(event_queue, &evento);

		//funciones jugando
		if (jugando == true) {
			x = evento.mouse.x;
			y = evento.mouse.y;
			//se encarga de borrar la pantalla y sobreescribirla
			//sirve para la ejecucion del juego
			al_draw_bitmap(fondo_juego, 0, 0, 0);


			// se genera la fruta en una cordenada aleatoria
				if (fruta_generada == false) {
					fx = menu.ObtenerAleatorioX();
					fy = menu.ObtenerAleatorioY();
					tipo_fruta = menu.ObtenerTipoFruta();
					fruta_generada = true;
				}
			//se imprime el tipo de fruta generada aleatoriamente
			if (tipo_fruta == 1) {
				al_draw_bitmap(pinia, fx, fy, 0);
			}
			else if (tipo_fruta == 2) {
				al_draw_bitmap(pera, fx, fy, 0);
			}
			else if (tipo_fruta == 3) {
				al_draw_bitmap(banano, fx, fy, 0);
			}
			else if (tipo_fruta == 4) {
				al_draw_bitmap(fresa, fx, fy, 0);
			}
			else if (tipo_fruta == 5) {
				al_draw_bitmap(manzana, fx, fy, 0);
			}




			//timer evento
			if (evento.type == ALLEGRO_EVENT_TIMER) {
				if (evento.timer.source == segundosTimer) {
					if (abajo == true) {
						y1 = y1 + 50;
						//imprime la cabeza de la culebrita segun a donde avanze
						al_draw_bitmap(c_b, x1, y1, 0);
					}
					if (izquierda == true) {
						x1 = x1 - 50;
						//imprime la cabeza de la culebrita segun a donde avanze
						al_draw_bitmap(c_i, x1, y1, 0);
					}
					if (arriba == true) {
						y1 = y1 - 50;
						//imprime la cabeza de la culebrita segun a donde avanze
						al_draw_bitmap(c_a, x1, y1, 0);
					}
					if (derecha == true) {
						x1 = x1 + 50;
						//imprime la cabeza de la culebrita segun a donde avanze
						al_draw_bitmap(c_d, x1, y1, 0);
					}

				}
			}

			//imprime la puntuacion del juego
			al_draw_text(mainkra, al_map_rgb(0, 0, 0), 30, 30, NULL, ("SCORE: " + to_string(menu.ObtenerPuntos())).c_str());
			//imprime las manzanas consumidas
			al_draw_text(mainkra, al_map_rgb(0, 0, 0), 1310, 30, NULL, (to_string(menu.ObtenerCantFrutas())).c_str());

			if (evento.mouse.button & 1) {
				cout << "x:" << x << "  y:" << y << endl;
			}

			//eventos del teclado y controla el gusanito
			if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (evento.keyboard.keycode)
				{
				case ALLEGRO_KEY_UP:
					if (abajo == false) {
						DesactivarComandos();
						arriba = true;
						cout << "Fleacha arriba" << endl;
						
					}
					break;

				case ALLEGRO_KEY_DOWN:
					if (arriba == false) {
						DesactivarComandos();
						abajo = true;
						cout << "Fleacha abajo" << endl;
					}
					break;
				case ALLEGRO_KEY_LEFT:
					if (derecha == false) {
						DesactivarComandos();
						izquierda = true;
						cout << "Fleacha izquierda" << endl;
					}
					break;
				case ALLEGRO_KEY_RIGHT:
					if (izquierda == false) {
						DesactivarComandos();
						derecha = true;
						cout << "Fleacha derecha" << endl;
					}
					break;
				default:
					break;
				}
			}



			//esto determina si la serpiente topa con algun obstaculo o con el borde de la pantalla
				//estas variables ayudan a que se tome en cuenta el final del cubo
			int x2 = x1 + 55;
			int y2 = y1 + 55;
			//este if sirve para saber si toco alguna orilla
			if (x1 < 45 || y1 < 170 || x2>1495 || y2>970) {
				int button = al_show_native_message_box(NULL, "Perdiste", "BUENA SUERTE A LA PROXIMA", "Has perdido :(, �Quieres volver a jugar?", NULL, ALLEGRO_MESSAGEBOX_YES_NO);
				if (button == 1) {
					menu.ModificarNivel(0);
					DesactivarComandos();
					abajo = true;
					x1 = 45;
					y1 = 170;
				}
				else {
					jugando = false;
					menu_inicio = true;
				}

			}

			

				//esta condicion, evalua cuando la culebrita toca algun fruto
				if (x1 == fx && y1 == fy) {
					//actualiza las frutas y genera otra mandando el false
					menu.ModificarFrutas();
					fruta_generada == false;

				}


				//aca termina la ejecucion de jugando
		}








		//esto
		//ya
		//esta
		//t
		//e
		//r
		//m
		//i
		//n
		//a
		//d
		//o
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
			//sirve para elegir el tipo de nivel
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
