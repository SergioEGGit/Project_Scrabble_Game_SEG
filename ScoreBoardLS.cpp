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
	#include "ScoreBoardLS.h"
	#include "Metodos.h"
	using namespace std;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------M�todos--------------------------------------

	void InsertarFinalScoreBoard(ScoreBoardLista &Lista, string Nombre, int Punteo)
	{
		ScoreBoardLista auxT, auxQ = new(struct ScoreBoardLS);
		auxQ -> Nombre = Nombre;
		auxQ -> Punteo = Punteo;
		auxQ -> sgte = NULL;

		if(Lista == NULL)
		{
			Lista = auxQ;
		}
		else
		{
			auxT = Lista;

			while(auxT -> sgte != NULL)
			{
				auxT = auxT -> sgte;
			}
			auxT -> sgte = auxQ;
		}
		OrdenarListaScoreBoard(Lista);
	}

	void OrdenarListaScoreBoard(ScoreBoardLista &Lista)
	{
		ScoreBoardLista Actual = Lista;
		ScoreBoardLista Indice;
		int TempPunteo;
		string TempNombre;

		while(Actual != nullptr)
		{
			Indice = Actual -> sgte;

			while(Indice != nullptr)
			{
				if(Actual -> Punteo < Indice -> Punteo)
				{
					TempPunteo = Actual -> Punteo;
					TempNombre = Actual -> Nombre;
					Actual -> Punteo = Indice -> Punteo;
					Actual -> Nombre = Indice -> Nombre;
					Indice -> Punteo = TempPunteo;
					Indice -> Nombre = TempNombre;
				}
				Indice = Indice -> sgte;
			}
			Actual = Actual -> sgte;
        }
	}


