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
	#include <FichasLS.h>
	#include <JugadoresFichasLD.h>
    #include <MatrizDispersa.h>
	using namespace std;
//------------------------------------------------------------------------------

	#endif

//-------------------------Definición Variables---------------------------------

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
		extern string Jugador1;
		extern string Jugador2;
		extern bool TerminarJuego;
		extern int ContadorReccorridos;
		extern int OpcionOpcionesJuego;
	};

//--------------------------Definición Métodos----------------------------------

//-----------------------------------Varios----------------------------------

		void Color(int Background, int Text);

		void Fullscreen();

		void Resolucion();

		void SepararCadenaEliminar(string CadenaEliminar);

	//------------------------------Menú------------------------------------

		void MenuPrincipal();

		void MenuJugar();

		void MenuReporte();

        void MenuOpcionesJuego();

	//-----------------------------Marcos-----------------------------------

		void gotoxy(int x, int y);

		void MarcoMenu(int Col1, int Col2, int Fil1, int Fil2);

		void MarcoArchivo(int Col1, int Col2, int Fil1, int Fil2);

        void MarcoJugar(int Col1, int Col2, int Fil1, int Fil2);

		void MarcoReportes(int Col1, int Col2, int Fil1, int Fil2);

		void MarcoSalir(int Col1, int Col2, int Fil1, int Fil2);

	//---------------------------Leer Archivos------------------------------

		void LeerArchivo(MatrizDispersa<string> &MatrizDispersaMD, string RutaArchivo, ListaDLDC &ListaDiccionario, ListaFichas &ListaFichasDT);

	//-------------------------Generar Fichas-------------------------------

		void GenerarFichas(ColaFichas &Cabeza, ColaFichas &Cola);

	//-----------------------------Jugar------------------------------------

		void AgregarJugadores();

		void Jugar(ArbolABB &Arbol, ListaLS &Lista, ListaLDJ &CabezaJugador1, ListaLDJ &CabezaJugador2, ListaLDJ &ColaJugador1, ListaLDJ &ColaJugador2, ColaFichas &FichasColaCabeza, ColaFichas &FichasColaCola, MatrizDispersa<string> &MatrizDispersaMD, int Contador);

	//-----------------------------Reportes---------------------------------

		void ReporteDiccionario(ListaDLDC &ListaDiccionario);

		void ReporteColaFichas(ColaFichas &Cabeza);

		void ReporteArbolPreOrden(ListaLS &Lista);

		void ReporteArbolInOrden(ListaLS &Lista);

		void ReporteArbolPostOrden(ListaLS &Lista);

		void ReporteArbolBinarioBusqueda(ArbolABB &Arbol);

		void ReporteJugadoresFichas1Reportes(ListaLDJ &Lista);

		void ReporteJugadoresFichas1Juego(ListaLDJ &Lista);

		void ReporteJugadoresFichas2Reportes(ListaLDJ &Lista);

		void ReporteJugadoresFichas2Juego(ListaLDJ &Lista);


