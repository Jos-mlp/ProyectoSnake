#pragma once
class Ventana
{
private:
	int nivel=1;
	int puntos = 0;
	bool velocidad;
	int aleatorioX=0;
	int aleatorioY=0;
	int frutas = 0;
	int tipo_fruta = 1;
public:
	Ventana(int, int);
	//modificadores
	void ModificarNivel(int);
	void ModificarPuntos(int);
	void ModificarFrutas();
	void ModificarVelocidad(int);
	//accesores
	int ObtenerPuntos();
	int ObtenerAleatorioX();
	int ObtenerAleatorioY();
	int ObtenerCantFrutas();
	int ObtenerTipoFruta();
	int ObtenerVelocidad();
};

