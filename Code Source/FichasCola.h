//------------------------------------------------------------------------------

	#ifndef FichasColaH
	#define FichasColaH

//------------------------------Librerias---------------------------------------

	#include <iostream>
	#include <stdio.h>
	#include <conio.h>
	#include <string>
	#include <windows.h>
	#include <fstream>
	#include <algorithm>
	#include <functional>
	#include <cctype>
	#include <locale>
	#include <cstring>
	using namespace std;

//-----------------------------Estructura---------------------------------------

	struct Fichas
	{
		string Letra;
		int Punteo;
		struct Fichas *sgte;
	};

	typedef struct Fichas *ColaFichas;


//-----------------------------M�todos------------------------------------------

	void InsertarColaFichas(ColaFichas &Cabeza, ColaFichas &Cola, string Letra, int Punteo);

	void InsertarInicioColaFichas(ColaFichas &Cabeza, string Letra, int Punteo);

    void InsertarFinalColaFichas(ColaFichas &Cabeza, string Letra, int Punteo);

	void InsertarEnMedioColaFichas(ColaFichas &Cabeza, int Posicion, string Letra, int Punteo);

	bool EstaVaciaColaFichas(ColaFichas &Cabeza);

	void ImprimirColaFichas(ColaFichas &Cabeza);

	int CantidadColaFichas(ColaFichas &Cabeza);

	void EliminarColaFichas(ColaFichas &Cabeza, ColaFichas &Cola);

//------------------------------------------------------------------------------

	#endif
