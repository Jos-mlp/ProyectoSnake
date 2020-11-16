#include "Lista.h"

Lista::Lista()
{
	this->frente = nullptr;
	this->fondo = nullptr;
	this->tamanio = 0;
}

void Lista::Insertar(string nom, int pts)
{
	Nodo2 *nuevo = new Nodo2();
	nuevo->ModificarNombre(nom);
	nuevo->ModificarPunteo(pts);
	if (this->frente == nullptr && this->fondo == nullptr) {
		this->frente = nuevo;
		this->fondo = nuevo;
		nuevo->ModificarSiguiente(nullptr);
	}
	else if (this->fondo == this->frente) {
		if (nuevo->ObtenerPunteo() > this->frente->ObtenerPunteo()) {
			this->frente = nuevo;
			nuevo->ModificarSiguiente(this->fondo);
		}
		else {
			this->fondo = nuevo;
			this->frente->ModificarSiguiente(nuevo);
			nuevo->ModificarSiguiente(nullptr);
		}
	}
	else {
		Nodo2* aux = this->frente;
		Nodo2* aux2 = aux->ObtenerSiguiente();
		while (aux2 != nullptr)
		{
			if (aux->ObtenerPunteo()<=nuevo->ObtenerPunteo() && aux2->ObtenerPunteo()>nuevo->ObtenerPunteo()) {
				aux->ModificarSiguiente(nuevo);
				nuevo->ModificarSiguiente(aux2);
			}
			aux = aux->ObtenerSiguiente();
			aux2 = aux2->ObtenerSiguiente();
			if (aux2 == nullptr) {
				Nodo2* aux3 = this->fondo;
				this->fondo = nuevo;
				nuevo->ModificarSiguiente(nullptr);
				aux3->ModificarSiguiente(nuevo);
			}
		}
	}
}

string Lista::Recorrer()
{
	string res = "";
	Nodo2* aux3 = this->frente;
	int cont = 1;
	while (aux3 != nullptr && cont != 5)
		res = res + to_string(cont) + ". " + aux3->ObtenerNombre() + "  : " + to_string(aux3->ObtenerPunteo()) + '\n' ;
	aux3 = aux3->ObtenerSiguiente();
	cont++;
	return string();
}
