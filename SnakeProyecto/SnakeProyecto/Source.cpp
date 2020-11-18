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
#include "Lista.h"


using namespace std;
//teclas
bool arriba = false, abajo = false, izquierda = false, derecha = false;
//juego ejecutado
bool ejecucion = true, fruta_generada = false, timer=false;
int tipo_fruta;
bool objetos_generados = false;
//menus
bool menu_inicio = true, menu_nivel = false, jugando = false, tabla_puntuaciones=false;
//objetos
int ox[5];
int oy[5];

void DesactivarComandos() {
	arriba = false;
	abajo = false;
	izquierda = false;
	derecha = false;

}



int main() {
	Lista facil = Lista();
	Lista intermedio = Lista();
	Lista dificil = Lista();
	Lista dinamico = Lista();
	srand(time(NULL));
	//variables de movimiento
	int x = 0, y = 0, x1 = 45, y1 = 170, fx=0, fy=0, x_aux = 1, y_aux = 1;
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
	

	//Eventos del mouse y teclado y del timer
	ALLEGRO_EVENT evento;
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	//eventos del tiempo
	ALLEGRO_TIMER* segundosTimer = al_create_timer(0.5);
	al_register_event_source(event_queue, al_get_timer_event_source(segundosTimer));

	//carga las imagenes
	//menu principal
	ALLEGRO_BITMAP* menu_default = al_load_bitmap("Recursos/menu_principal.jpg");
	ALLEGRO_BITMAP* menu_jugar = al_load_bitmap("Recursos/menu_jugar.jpg");
	ALLEGRO_BITMAP* menu_salir = al_load_bitmap("Recursos/menu_salir.jpg");
	ALLEGRO_BITMAP* menu_pts = al_load_bitmap("Recursos/fondo_puntuaciones.jpg");
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
	//imagenes de los objetos
	ALLEGRO_BITMAP* columnas = al_load_bitmap("Recursos/Columna.jpeg");
	ALLEGRO_BITMAP* ladrillo = al_load_bitmap("Recursos/Ladrillo.jpeg");
	ALLEGRO_BITMAP* paredes = al_load_bitmap("Recursos/Pared.jpeg");

	//mantiene en ejecucion el programa
	while (ejecucion == true) {
		int tamanio = menu.ObtenerTamanio();
		Nodo* aux = menu.ObtenerFrente();

		//Inicializa la variable evento y le pasa el evento generado
		al_wait_for_event(event_queue, &evento);

		//funciones jugando
		if (jugando == true) {
			x = evento.mouse.x;
			y = evento.mouse.y;
			//si el timer esta desactivado lo inicia
			if (timer == false) {
				al_stop_timer(segundosTimer);
				al_unregister_event_source(event_queue, al_get_timer_event_source(segundosTimer));
				al_destroy_timer(segundosTimer);
				segundosTimer = al_create_timer(menu.ObtenerVelocidad());
				al_register_event_source(event_queue, al_get_timer_event_source(segundosTimer));
				al_start_timer(segundosTimer);
				timer = true;
			}
			//se encarga de borrar la pantalla y sobreescribirla
			//sirve para la ejecucion del juego
			al_draw_bitmap(fondo_juego, 0, 0, 0);


			//ESTE ESPACIO
			//ESTA
			//DEDICADO
			//A LA COLOCACION DE OBSTACULOS
			if (objetos_generados == false) {
				for (int i = 0; i < 5; i++) {
					ox[i] = (rand() % 27) + 1;
					ox[i] = 45 + (ox[i] * 50);
					if (i < 2) {
						oy[i] = (rand() % 15) + 0;
						oy[i] = 170 + (oy[i] * 50);
					}
					else if (i > 1 && i < 4) {
						oy[i] = (rand() % 11) + 0;
						oy[i] = 170 + (oy[i] * 50);
					}
					else {
						oy[i] = (rand() % 9) + 0;
						oy[i] = 170 + (oy[i] * 50);
					}

				}
				objetos_generados = true;
			}
			//esto imprime las imagenes segun el nivel en el que se este
			if (menu.ObtenerNivel() == 1) {

			}
			else if (menu.ObtenerNivel() == 2) {
				al_draw_bitmap(ladrillo, ox[0], oy[0], 0);
				al_draw_bitmap(ladrillo, ox[1], oy[1], 0);
				al_draw_bitmap(columnas, ox[2], oy[2], 0);
			}
			else if (menu.ObtenerNivel() == 3 || menu.ObtenerNivel() == 4) {
				al_draw_bitmap(ladrillo, ox[0], oy[0], 0);
				al_draw_bitmap(ladrillo, ox[1], oy[1], 0);
				al_draw_bitmap(columnas, ox[2], oy[2], 0);
				al_draw_bitmap(columnas, ox[3], oy[3], 0);
				al_draw_bitmap(paredes, ox[4], oy[4], 0);
			}
			//aca termina la generacion de objetos


			//se genera la fruta en una cordenada aleatoria
			if (fruta_generada == false) {
				srand(time(NULL));
				fx = menu.ObtenerAleatorioX();
				fy = menu.ObtenerAleatorioY();
				tipo_fruta = menu.ObtenerTipoFruta();
				fruta_generada = true;
				//esto hace que si la fruta se genera sobre un bloque se vuelve a generar
				if (menu.ObtenerNivel() == 3 || menu.ObtenerNivel() == 4) {


					if (fx == ox[0] && fy == oy[0] || fx == ox[1] && fy == oy[1]) {
						fruta_generada = false;
					}
					else {
						for (int j = 2; j < 4; j++) {
							for (int i = 0; i < 4; i++) {
								if (fx == ox[j] && fy == (oy[j] + (i * 50))) {
									fruta_generada = false;
								}
							}
						}
					}
					for (int i = 0; i < 6; i++) {
						if (fx == ox[4] && fy == (oy[4] + (i * 50))) {
							fruta_generada = false;
						}
					}
				}
				else if (menu.ObtenerNivel() == 2) {
					if (fx == ox[0] && fy == oy[0] || fx == ox[1] && fy == ox[1]) {
						fruta_generada = false;
					}
					else {
						for (int i = 0; i < 4; i++) {
							if (fx == ox[2] && fy == (oy[2] + (i * 50))) {
								fruta_generada = false;
							}
						}
					}
				}
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
					//hace que el cuerpo se mueva con la cabeza
					menu.ModificarCordenadas(x1, y1);
					if (abajo == true) {
						y1 = y1 + 50;
					}
					if (izquierda == true) {
						x1 = x1 - 50;
					}
					if (arriba == true) {
						y1 = y1 - 50;
					}
					if (derecha == true) {
						x1 = x1 + 50;
					}
					/*esta condicion sirve para que al generar un nuevo elemento desde cero no 
					lo considere como topar con su cola*/
					if (tamanio > 0) {
						x_aux = 0;
						y_aux = 0;
					}
					else
					{
						x_aux = 1;
						y_aux = 1;
					}
				}
			}
			//imprime la cabeza de la culebrita
			//imprime el cuerpo
			cout << endl;
			cout << "Tamanio" << endl;
			cout << menu.ObtenerTamanio() << endl;
			while (aux != nullptr) {
				int x4 = menu.Obtener_x(aux);
				int y4 = menu.Obtener_y(aux);
				cout << "x4: " << x4 << " y4: " << y4 << endl;
				al_draw_bitmap(cuerpo_Snake, x4, y4, 0);
				aux = menu.ObtenerNodoSiguiente(aux);
			}

			if (abajo == true) {
				//imprime la cabeza de la culebrita segun a donde avanze
				al_draw_bitmap(c_b, x1, y1, 0);
			}
			if (izquierda == true) {
				//imprime la cabeza de la culebrita segun a donde avanze
				al_draw_bitmap(c_i, x1, y1, 0);
			}
			if (arriba == true) {
				//imprime la cabeza de la culebrita segun a donde avanze
				al_draw_bitmap(c_a, x1, y1, 0);
			}
			if (derecha == true) {
				//imprime la cabeza de la culebrita segun a donde avanze
				al_draw_bitmap(c_d, x1, y1, 0);
			}
			
			//termina de imprimir la cabeza y el cuerpo


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
				case ALLEGRO_KEY_W:
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
				case ALLEGRO_KEY_S:
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
				case ALLEGRO_KEY_A:
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
				case ALLEGRO_KEY_D:
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
				int button = al_show_native_message_box(NULL, "Perdiste", "SUERTE A LA PROXIMA", "Has perdido :(, �Quieres volver a jugar?", NULL, ALLEGRO_MESSAGEBOX_YES_NO);
				DesactivarComandos();
				x1 = 45;
				y1 = 170;
				menu.ReiniciarLista();
				menu.ReiniciarTamanio();
				menu.ReiniciarPuntos();
				menu.ReiniciarCantFruta();
				fruta_generada = false;
				objetos_generados = false;
				if (button == 1) {

				}
				else {
					jugando = false;
					menu_inicio = true;
				}

			}

			

			//esta condicion, evalua cuando la culebrita toca algun fruto
			if (x1 == fx && y1 == fy) {
				if (tipo_fruta == 1) {
					//pinia
					for (int i = 0; i < 5; i++) {
						menu.Eliminar();
						menu.ModificarPuntos(-50);
					}
				}
				else if (tipo_fruta == 2) {
					//pera
					menu.Eliminar();
					menu.ModificarPuntos(-25);
				}
				else if (tipo_fruta == 3) {
					//banano
					menu.ModificarFrutas(3);

					//Inserta tres nuevos elementos a la lista
					for (int i = 0; i < 3; i++) {
						menu.InsertarFondo(x1+1, y1+1);
					}
					menu.ModificarPuntos(275);
				}
				else if (tipo_fruta == 4) {
					//fresa
					menu.ModificarFrutas(2);

					//Inserta dos nuevos elementos a la lista
					menu.InsertarFondo(x1+1, y1+1);
					menu.InsertarFondo(x1+1, y1+1);
					menu.ModificarPuntos(150);
				}
				else {
					//manzana
					menu.ModificarFrutas(1);

					//Inserta un nuevo elemento a la lista
					menu.InsertarFondo(x1+1, y1+1);
					menu.ModificarPuntos(50);
				}
				//manda a generar una nueva fruta
				fruta_generada = false;

			}


			//esto evalua cuando la culebrita topa con algun block
			if (menu.ObtenerNivel() == 3 || menu.ObtenerNivel() == 4) {
				if (x1 == ox[0] && y1 == oy[0] || x1 == ox[1] && y1 == oy[1]) {
					int button = al_show_native_message_box(NULL, "Perdiste", "SUERTE A LA PROXIMA", "Has perdido :(, �Quieres volver a jugar?", NULL, ALLEGRO_MESSAGEBOX_YES_NO);
					DesactivarComandos();
					x1 = 45;
					y1 = 170;
					menu.ReiniciarLista();
					menu.ReiniciarTamanio();
					menu.ReiniciarCantFruta();
					fruta_generada = false;
					objetos_generados = false;
					if (button == 1) {
						
					}
					else {
						jugando = false;
						tabla_puntuaciones = true;
					}
					//
					if (menu.ObtenerNivel() == 1) {
						facil.Insertar("joss", menu.ObtenerPuntos());
					}
					else if (menu.ObtenerNivel() == 2) {
						intermedio.Insertar("joss", menu.ObtenerPuntos());
					}
					else if (menu.ObtenerNivel() == 3) {
						dificil.Insertar("joss", menu.ObtenerPuntos());
					}
					else if (menu.ObtenerNivel() == 4) {
						dinamico.Insertar("joss", menu.ObtenerPuntos());
					}
					//
					menu.ReiniciarPuntos();
				}
				else {
					for (int j = 2; j < 4; j++) {
						for (int i = 0; i < 4; i++) {
							if (x1 == ox[j] && y1 == (oy[j] + (i * 50))) {
								int button = al_show_native_message_box(NULL, "Perdiste", "SUERTE A LA PROXIMA", "Has perdido :(, �Quieres volver a jugar?", NULL, ALLEGRO_MESSAGEBOX_YES_NO);
								DesactivarComandos();
								x1 = 45;
								y1 = 170;
								menu.ReiniciarLista();
								menu.ReiniciarTamanio();
								menu.ReiniciarCantFruta();
								fruta_generada = false;
								objetos_generados = false;
								if (button == 1) {

								}
								else {
									jugando = false;
									tabla_puntuaciones = true;
								}
								//
								if (menu.ObtenerNivel() == 1) {
									facil.Insertar("joss", menu.ObtenerPuntos());
								}
								else if (menu.ObtenerNivel() == 2) {
									intermedio.Insertar("joss", menu.ObtenerPuntos());
								}
								else if (menu.ObtenerNivel() == 3) {
									dificil.Insertar("joss", menu.ObtenerPuntos());
								}
								else if (menu.ObtenerNivel() == 4) {
									dinamico.Insertar("joss", menu.ObtenerPuntos());
								}
								//
								menu.ReiniciarPuntos();
							}
						}
					}
				}
				for (int i = 0; i < 6; i++) {
					if (x1 == ox[4] && y1 == (oy[4] + (i * 50))) {
						int button = al_show_native_message_box(NULL, "Perdiste", "SUERTE A LA PROXIMA", "Has perdido :(, �Quieres volver a jugar?", NULL, ALLEGRO_MESSAGEBOX_YES_NO);
						DesactivarComandos();
						x1 = 45;
						y1 = 170;
						menu.ReiniciarLista();
						menu.ReiniciarTamanio();
						menu.ReiniciarCantFruta();
						fruta_generada = false;
						objetos_generados = false;
						if (button == 1) {

						}
						else {
							jugando = false;
							tabla_puntuaciones = true;
						}
						//
						if (menu.ObtenerNivel() == 1) {
							facil.Insertar("joss", menu.ObtenerPuntos());
						}
						else if (menu.ObtenerNivel() == 2) {
							intermedio.Insertar("joss", menu.ObtenerPuntos());
						}
						else if (menu.ObtenerNivel() == 3) {
							dificil.Insertar("joss", menu.ObtenerPuntos());
						}
						else if (menu.ObtenerNivel() == 4) {
							dinamico.Insertar("joss", menu.ObtenerPuntos());
						}
						//
						menu.ReiniciarPuntos();
					}
				}
			}
			else if (menu.ObtenerNivel() == 2) {
				if (x1 == ox[0] && y1 == oy[0] || x1 == ox[1] && y1 == oy[1]) {
					int button = al_show_native_message_box(NULL, "Perdiste", "SUERTE A LA PROXIMA", "Has perdido :(, �Quieres volver a jugar?", NULL, ALLEGRO_MESSAGEBOX_YES_NO);
					DesactivarComandos();
					x1 = 45;
					y1 = 170;
					menu.ReiniciarLista();
					menu.ReiniciarTamanio();
					menu.ReiniciarCantFruta();
					fruta_generada = false;
					objetos_generados = false;
					if (button == 1) {

					}
					else {
						jugando = false;
						tabla_puntuaciones = true;
					}
					//
					if (menu.ObtenerNivel() == 1) {
						facil.Insertar("joss", menu.ObtenerPuntos());
					}
					else if (menu.ObtenerNivel() == 2) {
						intermedio.Insertar("joss", menu.ObtenerPuntos());
					}
					else if (menu.ObtenerNivel() == 3) {
						dificil.Insertar("joss", menu.ObtenerPuntos());
					}
					else if (menu.ObtenerNivel() == 4) {
						dinamico.Insertar("joss", menu.ObtenerPuntos());
					}
					//
					menu.ReiniciarPuntos();
				}
				else {
					for (int i = 0; i < 4; i++) {
						if (x1 == ox[2] && y1 == (oy[2] + (i * 50))) {
							int button = al_show_native_message_box(NULL, "Perdiste", "SUERTE A LA PROXIMA", "Has perdido :(, �Quieres volver a jugar?", NULL, ALLEGRO_MESSAGEBOX_YES_NO);
							DesactivarComandos();
							x1 = 45;
							y1 = 170;
							menu.ReiniciarLista();
							menu.ReiniciarTamanio();
							menu.ReiniciarCantFruta();
							fruta_generada = false;
							objetos_generados = false;
							if (button == 1) {

							}
							else {
								jugando = false;
								tabla_puntuaciones = true;
							}
							//
							if (menu.ObtenerNivel() == 1) {
								facil.Insertar("joss", menu.ObtenerPuntos());
							}
							else if (menu.ObtenerNivel() == 2) {
								intermedio.Insertar("joss", menu.ObtenerPuntos());
							}
							else if (menu.ObtenerNivel() == 3) {
								dificil.Insertar("joss", menu.ObtenerPuntos());
							}
							else if (menu.ObtenerNivel() == 4) {
								dinamico.Insertar("joss", menu.ObtenerPuntos());
							}
							//
							menu.ReiniciarPuntos();
						}
					}
				}
			}
			//aca termina el criterio si topa con algun block


					//ese while sirve para saber si choco contra su cola
					int x_c, y_c;
					Nodo* aux2 = menu.ObtenerFrente();
					while (aux2 != nullptr) {
						x_c = menu.Obtener_x(aux2) + x_aux;
						y_c = menu.Obtener_y(aux2) + y_aux;
						//el if evalua si si toco
						if (x1 == x_c && y1 == y_c || x2 == x_c && y2 == y_c) {
							int button = al_show_native_message_box(NULL, "Perdiste", "SUERTE A LA PROXIMA", "Has perdido :(, �Quieres volver a jugar?", NULL, ALLEGRO_MESSAGEBOX_YES_NO);
							DesactivarComandos();
							x1 = 45;
							y1 = 170;
							menu.ReiniciarLista();
							menu.ReiniciarTamanio();
							menu.ReiniciarCantFruta();
							fruta_generada = false;
							objetos_generados = false;
							if (button == 1) {

							}
							else {
								jugando = false;
								menu_inicio = true;
							}
							//
							if (menu.ObtenerNivel() == 1) {
								facil.Insertar("joss", menu.ObtenerPuntos());
							}
							else if (menu.ObtenerNivel() == 2) {
								intermedio.Insertar("joss", menu.ObtenerPuntos());
							}
							else if (menu.ObtenerNivel() == 3) {
								dificil.Insertar("joss", menu.ObtenerPuntos());
							}
							else if (menu.ObtenerNivel() == 4) {
								dinamico.Insertar("joss", menu.ObtenerPuntos());
							}
							//
							menu.ReiniciarPuntos();
						}
						//aca termina el if que evalua la condicion
						aux2 = menu.ObtenerNodoSiguiente(aux2);

					}
					//aca termina de evaluar el while para ver si si topa con su cola

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




			//aca empieza la 
			//pantalla de los 
			//niveles
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
							timer = false;
						}
					}
					else if (x > 278 && y > 313 && x < 1140 && y < 490) {
						al_draw_bitmap(nivel_intermedio, 0, 0, 0);
						//si el boton izquierdo del mouse es presionado se ejecuta el if
						if (evento.mouse.button & 1) {
							menu.ModificarNivel(2);
							menu_nivel = false;
							jugando = true;
							timer = false;
						}
					}
					else if (x > 278 && y > 539 && x < 1140 && y < 715) {
						al_draw_bitmap(nivel_dificil, 0, 0, 0);
						//si el boton izquierdo del mouse es presionado se ejecuta el if
						if (evento.mouse.button & 1) {
							menu.ModificarNivel(3);
							menu_nivel = false;
							jugando = true;
							timer = false;
						}
					}
					else if (x > 278 && y > 759 && x < 1140 && y < 935) {
						al_draw_bitmap(nivel_dinamico, 0, 0, 0);
						//si el boton izquierdo del mouse es presionado se ejecuta el if
						if (evento.mouse.button & 1) {
							menu.ModificarNivel(4);
							menu_nivel = false;
							jugando = true;
							timer = false;
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


			//esto imprime la tabla de puntuaciones
			else if (tabla_puntuaciones == true) {
				al_draw_bitmap(menu_pts, 0, 0, 0);
				//imprime el nivel de la puntuacion
				al_draw_text(mainkra, al_map_rgb(0, 0, 0), 550, 30, NULL, ("NIVEL: " + to_string(menu.ObtenerNivel())).c_str());
				al_draw_text(mainkra, al_map_rgb(0, 0, 0), 550, 700, NULL, ("NIVEL: " + to_string(menu.ObtenerPuntos())).c_str());
				/*if (menu.ObtenerNivel() == 1) {
					al_draw_text(mainkra, al_map_rgb(0, 0, 0), 700, 30, NULL, (facil.Recorrer()).c_str());
				}
				else if (menu.ObtenerNivel() == 2) {
					al_draw_text(mainkra, al_map_rgb(0, 0, 0), 700, 30, NULL, (intermedio.Recorrer()).c_str());
				}
				else if (menu.ObtenerNivel() == 3) {
					al_draw_text(mainkra, al_map_rgb(0, 0, 0), 700, 30, NULL, (dificil.Recorrer()).c_str());
				}
				else if (menu.ObtenerNivel() == 4) {
					al_draw_text(mainkra, al_map_rgb(0, 0, 0), 700, 30, NULL, dinamico.Recorrer().c_str());
				}*/



				//este if sirve para que cuando se presione una tecla se salga de la tabla de puntuaciones
			//Inicializa la variable evento y le pasa el evento generado
				al_wait_for_event(event_queue, &evento);
				if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					tabla_puntuaciones = false;
					menu_inicio = true;
				}

			}
		}
		al_flip_display();
	}
	return 0;
}
