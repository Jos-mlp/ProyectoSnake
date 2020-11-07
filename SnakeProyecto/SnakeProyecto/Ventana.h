#pragma once
class Ventana
{
private:
	int nivel=1;
	int puntos = 0;
	bool velocidad;
public:
	Ventana(int, int);
	void ModificarNivel(int);
	void ModificarPuntos(int);
	int ObtenerPuntos();
};

