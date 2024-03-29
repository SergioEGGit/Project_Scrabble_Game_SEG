//------------------------------------------------------------------------------

	#pragma hdrstop

//---------------------------------Librerias------------------------------------

	#include <iostream>
	#include <stdio.h>
	#include <conio.h>
	#include <string>
	#include <cstdlib>
	#include <fstream>
	#include <windows.h>
	#include "JugadoresFichasLD.h"
	#include "Metodos.h"
	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------M�todos--------------------------------------

	void InsertarInicioLDJ(ListaLDJ &Cabeza, ListaLDJ &Cola, string Letra , int Punteo)
	{
		 ListaLDJ aux = new(struct FichasJugadores);
		 aux -> Letra = Letra;
		 aux -> Punteo = Punteo;

		 aux -> sgte = Cabeza;
		 aux -> ante = NULL;
		 if(Cabeza != NULL)
		 {
			 Cabeza -> ante = aux;
		 }
		 Cabeza = aux;
	}

	void InsertarFinalLDJ(ListaLDJ &Cabeza, ListaLDJ &Cola, string Letra, int Punteo)
	{
		ListaLDJ aux = new(struct FichasJugadores);
		aux -> Letra = Letra;
		aux -> Punteo = Punteo;
		aux -> sgte = NULL;
		aux -> ante = NULL;

		if(Cabeza == NULL)
		{
			Cabeza = aux;
			Cola = aux;
		}
		else
		{
			Cola -> sgte = aux;
			aux -> ante = Cola;
			Cola = aux;
		}
	}

	void InsertarEnMedioLDJ(ListaLDJ &Cabeza, ListaLDJ &Cola, string Letra, int Punteo, int Posicion)
	{
		ListaLDJ aux = new(struct FichasJugadores);
		aux -> Letra = Letra;
		aux -> Punteo = Punteo;
		aux -> sgte = NULL;
		aux -> ante = NULL;

		Posicion = Posicion - 1;

		if(Cabeza == NULL)
		{
			return;
		}
		if(Posicion == 0)
		{
			Cabeza -> ante = aux;
			aux -> sgte = Cabeza;
			aux -> ante = NULL;
			Cabeza = aux;
		}
		else
		{
			ListaLDJ Temp = Cabeza;

			for(int i = 0; i < Posicion - 1; i++)
			{
				Temp = Temp -> sgte;

				if(Temp == NULL)
				{
				   return;
				}
			}
		   if(Temp -> sgte != NULL)
		   {
			   Temp -> sgte -> ante = aux;
			   aux -> sgte = Temp -> sgte;
			   aux -> ante = Temp;
			   Temp -> sgte = aux;
		   }
		   else
		   {
			   Temp -> sgte = aux;
			   aux -> ante = Temp;
		   }
		}
	}

	int SizeLDJ(ListaLDJ &Cabeza)
	{
		ListaLDJ aux = Cabeza;
		int Contador = 0;

		while(aux != NULL)
		{
			Contador++;
			aux = aux -> sgte;
		}
		return Contador;
    }

	void EliminarLDJ(ListaLDJ &Cabeza, ListaLDJ &Cola, int Posicion)
	{
		Posicion = Posicion - 1;

		if(Cabeza == NULL || Posicion < 0)
		{
			return;
		}
		if(Posicion == 0)
		{
			if(SizeLDJ(Cabeza) == 1)
			{
                ListaLDJ aux = Cabeza;

				if(aux -> sgte != NULL)
				{
					while((aux -> sgte) -> sgte != NULL)
					{
						aux = aux -> sgte;
					}
					Variables::LetraColaFichas = aux -> sgte -> Letra;
					Variables::PunteoColaFichas = aux -> sgte -> Punteo;
					delete(aux -> sgte);
					aux -> sgte = NULL;
				}
				else
				{
					Variables::LetraColaFichas = Cabeza -> Letra;
					Variables::PunteoColaFichas = Cabeza -> Punteo;
					Cabeza = NULL;
				}
			}
			else
			{
				ListaLDJ Temp = Cabeza -> sgte;
				Variables::LetraColaFichas = Cabeza -> Letra;
				Variables::PunteoColaFichas = Cabeza -> Punteo;
				delete(Cabeza);
				Cabeza = Temp;
				Cabeza -> ante = NULL;
			}
		}
		else if(Posicion == SizeLDJ(Cabeza) - 1)
		{
			ListaLDJ aux = Cabeza;

			if(aux -> sgte != NULL)
			{
				while((aux -> sgte) -> sgte != NULL)
				{
					aux = aux -> sgte;
				}
				Variables::LetraColaFichas = aux -> sgte -> Letra;
				Variables::PunteoColaFichas = aux -> sgte -> Punteo;
				delete(aux -> sgte);
				aux -> sgte = NULL;
			}
			else
			{
				Cabeza = NULL;
			}
		}
		else
		{
			ListaLDJ Aux = Cabeza;

			for(int i = 0; i < Posicion; i++)
			{
			   Aux = Aux -> sgte;

			   if(Aux == NULL)
			   {
				   return;
			   }
			}
			Aux -> sgte -> ante = Aux -> ante;
			Aux -> ante -> sgte = Aux -> sgte;
			Variables::LetraColaFichas = Aux -> Letra;
			Variables::PunteoColaFichas = Aux -> Punteo;
			delete(Aux);
		}
	}
