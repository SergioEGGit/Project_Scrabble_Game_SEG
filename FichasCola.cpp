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
	#include "FichasCola.h"
	#include "Metodos.h"
	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------M�todos--------------------------------------

	void InsertarColaFichas(ColaFichas &Cabeza, ColaFichas &Cola, string Letra, int Punteo)
	{
		ColaFichas aux = new(struct Fichas);

		aux -> Letra = Letra;
		aux -> Punteo = Punteo;
		aux -> sgte = NULL;

		if(Cabeza == NULL)
		{
			Cabeza = aux;
		}
		else
		{
			Cola -> sgte = aux;
		}
		Cola = aux;
	}

	void InsertarInicioColaFichas(ColaFichas &Cabeza, string Letra, int Punteo)
	{
		ColaFichas aux = new(struct Fichas);

		aux -> Letra = Letra;
		aux -> Punteo = Punteo;

		if(Cabeza == NULL)
		{
			Cabeza = aux;
			aux -> sgte = NULL;
		}
		else
		{
			aux -> sgte = Cabeza;
			Cabeza = aux;
		}
	}

	void InsertarFinalColaFichas(ColaFichas &Cabeza, string Letra, int Punteo)
	{
		ColaFichas auxT, auxQ = new(struct Fichas);
		auxQ -> Letra = Letra;
		auxQ -> Punteo = Punteo;
		auxQ -> sgte = NULL;

		if(Cabeza == NULL)
		{
			Cabeza = auxQ;
		}
		else
		{
			auxT = Cabeza;

			while(auxT -> sgte != NULL)
			{
				auxT = auxT -> sgte;
			}
			auxT -> sgte = auxQ;
		}
    }

	void InsertarEnMedioColaFichas(ColaFichas &Cabeza, int Posicion, string Letra, int Punteo)
	{
		ColaFichas aux = new(struct Fichas);

		aux -> Letra = Letra;
		aux -> Punteo = Punteo;
		aux -> sgte = NULL;

		if(Cabeza == NULL)
		{
			Cabeza = aux;
		}
		else
		{
			if(Posicion == 1)
			{
				InsertarInicioColaFichas(Cabeza, Letra, Punteo);
			}
			else if(Posicion == CantidadColaFichas(Cabeza) + 1)
			{
				InsertarFinalColaFichas(Cabeza, Letra, Punteo);
			}
			else if(Posicion > 1 && Posicion < CantidadColaFichas(Cabeza) + 1)
			{
				ColaFichas aux1 = Cabeza;
				ColaFichas aux2 = new(struct Fichas);

				for(int i = 1; i < Posicion; i++)
				{
					aux2 = aux1;
					aux1 = aux1 -> sgte;
				}
				aux2 -> sgte = aux;
				aux -> sgte = aux1;
			}
			else
			{
				cout<< "Posicion No Encontrada" << endl;
            }
        }
	}

	bool EstaVaciaColaFichas(ColaFichas &Cabeza)
	{
		if(Cabeza == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
    }

	void ImprimirColaFichas(ColaFichas &Cabeza)
	{
		ColaFichas aux = Cabeza;

		int Contador = 1;

		while(aux != NULL)
		{
			cout<< Contador << ". " << " Ficha: "<< aux -> Letra << " Punteo: " << aux -> Punteo <<endl;
			aux = aux -> sgte;
            Contador++;
		}
    }

	int CantidadColaFichas(ColaFichas &Cabeza)
	{
		int Cant = 0;
		ColaFichas aux = Cabeza;

		while(aux != NULL)
		{
			aux = aux -> sgte;
			Cant++;
        }

		return Cant;
    }

	void EliminarColaFichas(ColaFichas &Cabeza, ColaFichas &Cola)
	{
		 ColaFichas aux = Cabeza;

		 Variables::LetraColaFichas = aux -> Letra;
		 Variables::PunteoColaFichas = aux -> Punteo;

		 if(Cabeza == NULL)
		 {
			 Variables::ColaVacia = true;
		 }
		 else
		 {
			 if(Cabeza == Cola)
			 {
				 Cabeza = NULL;
				 Cola = NULL;
			 }
			 else
			 {
				 Cabeza = Cabeza -> sgte;
			 }
			 delete(aux);
		 }
	}
