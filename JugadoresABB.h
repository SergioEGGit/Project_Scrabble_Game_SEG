//------------------------------------------------------------------------------

	#ifndef JugadoresABBH
	#define JugadoresABBH

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

	struct Jugadores
	{
		string Nombre;
		struct Jugadores *RIGHT;
		struct Jugadores *LEFT;
	};

	typedef struct Jugadores *ArbolABB;


//-----------------------------M�todos------------------------------------------

	ArbolABB CrearNombreABB(string Nombre);

	void InsertarNombreABB(ArbolABB &Arbol, string Nombre);

	void ImprimirABB(ArbolABB &Arbol, int Contador);

	bool BusquedaABB(ArbolABB &Arbol, string Nombre);

    string RecorridoPreOrden(ArbolABB &Arbol);

//------------------------------------------------------------------------------

	#endif