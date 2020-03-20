//------------------------------------------------------------------------------

	#ifndef MetodosH
	#define MetodosH

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
	#include <DiccionarioLDC.h>
	#include <FichasCola.h>
	#include <RecorridosLS.h>
    #include <JugadoresABB.h>
	using namespace std;
//------------------------------------------------------------------------------

	#endif

//-------------------------Definici�n Variables---------------------------------

	namespace Variables
	{
		extern int AnchoPantalla;
		extern int AltoPantalla;
		extern int OpcionMenu;
		extern int OpcionJugar;
		extern int OpcionReporte;
		extern string RutaArchivo;
		extern int DimensionTablero;
		extern string LetraColaFichas;
		extern int PunteoColaFichas;
		extern string NombreJugador;
		extern int ContadorArbol;
		extern string CadenaArbol;
	};

//--------------------------Definici�n M�todos----------------------------------

//-----------------------------Colores----------------------------------

		void Color(int Background, int Text);

	//---------------------------Fullscreen---------------------------------

		void Fullscreen();

	//---------------------Obtener Resoluci�n Pantalla----------------------

		void Resolucion();

	//------------------------------Men�------------------------------------

		void MenuPrincipal();

		void MenuJugar();

		void MenuReporte();

	//-----------------------------Marcos-----------------------------------

		void gotoxy(int x, int y);

		void MarcoMenu(int Col1, int Col2, int Fil1, int Fil2);

		void MarcoArchivo(int Col1, int Col2, int Fil1, int Fil2);

        void MarcoJugar(int Col1, int Col2, int Fil1, int Fil2);

		void MarcoReportes(int Col1, int Col2, int Fil1, int Fil2);

		void MarcoSalir(int Col1, int Col2, int Fil1, int Fil2);

	//---------------------------Leer Archivos------------------------------

		void LeerArchivo(string RutaArchivo, ListaDLDC &ListaDiccionario);

	//-------------------------Generar Fichas-------------------------------

		void GenerarFichas(ColaFichas &Cabeza, ColaFichas &Cola);

	//--------------------------Agregar Jugadores---------------------------

		void AgregarJugadores();

	//-----------------------------Reportes---------------------------------

		void ReporteDiccionario(ListaDLDC &ListaDiccionario);

		void ReporteColaFichas(ColaFichas &Cabeza);

		void ReporteArbolPreOrden(ListaLS &Lista);

		void ReporteArbolInOrden(ListaLS &Lista);

		void ReporteArbolPostOrden(ListaLS &Lista);

		void ReporteArbolBinarioBusqueda(ArbolABB &Arbol);

