//------------------------------------------------------------------------------

	#ifndef MatrizDispersaH
	#define MatrizDispersaH

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
	#include "MatrizDispersaNodo.h"
	using namespace std;

//-----------------------------Estructura---------------------------------------

	template<class T>

	class MatrizDispersa
	{
		private:
		   MatrizDispersaNodo<T> *Raiz;

		   MatrizDispersaNodo<T> *BuscarColumna(int x);

		   MatrizDispersaNodo<T> *BuscarFila(int y);

		   MatrizDispersaNodo<T> *InsertarEnColumna(MatrizDispersaNodo<T> *Nodo, MatrizDispersaNodo<T> *HeaderFila);

		   MatrizDispersaNodo<T> *InsertarEnFila(MatrizDispersaNodo<T> *Nodo, MatrizDispersaNodo<T> *HeaderColumna);

		   MatrizDispersaNodo<T> *CrearColumna(int x);

		   MatrizDispersaNodo<T> *CrearFila(int y);

		public:
		   MatrizDispersa();

		   ~MatrizDispersa();

		   void InsertarMatrizDispersa(int x, int y, T object);

		   void ImprimirFilaHeaders();

		   void ImprimirColumnaHeaders();

		   void ImprimirFilas();

		   void ImprimirColumnas();

		   void ReporteMatrizDispersa();
	 };


	template<class T>

	MatrizDispersa<T>::MatrizDispersa()
	{
		Raiz = new MatrizDispersaNodo<T>(-1, -1);
	}

	template<class T>

	MatrizDispersa<T>::~MatrizDispersa()
	{

	}

	template<class T>

	MatrizDispersaNodo<T> *MatrizDispersa<T>::BuscarColumna(int x)
	{
		MatrizDispersaNodo<T> *Temp = Raiz;

		while(Temp != nullptr)
		{
			if(Temp -> getX() == x)
			{
				return Temp;
			}
			Temp = Temp -> getNextNode();
		}
		return nullptr;
	}

	template<class T>

	MatrizDispersaNodo<T> *MatrizDispersa<T>::BuscarFila(int y)
	{
		MatrizDispersaNodo<T> *Temp = Raiz;

		while(Temp != nullptr)
		{
			if(Temp -> getY() == y)
			{
				return Temp;
			}
			Temp = Temp -> getDownNode();
		}
		return nullptr;
	}

	template<class T>

	MatrizDispersaNodo<T> *MatrizDispersa<T>::InsertarEnColumna(MatrizDispersaNodo<T> *Nodo, MatrizDispersaNodo<T> *HeaderFila)
	{
		MatrizDispersaNodo<T> *Temp = HeaderFila;
		bool Bandera = false;

		while(true)
		{
			if(Temp -> getX() == Nodo -> getX())
			{
				Temp -> setY(Nodo -> getY());
				Temp -> setObject(Nodo -> getObject());
				return Temp;
			}
			else if(Temp -> getX() > Nodo->getX())
			{
				Bandera = true;
				break;
			}

			if(Temp -> getNextNode() != nullptr)
			{
				Temp = Temp -> getNextNode();
			}
			else
			{
				// flag = false;
				break;
			}
		}

		if(Bandera)
		{
			Nodo -> setNextNode(Temp);
			Temp -> getPreviousNode() -> setNextNode(Nodo);
			Nodo -> setPreviousNode(Temp -> getPreviousNode());
			Temp -> setPreviousNode(Nodo);
		}
		else
		{
			Temp -> setNextNode(Nodo);
			Nodo -> setPreviousNode(Temp);
		}
		return Nodo;
	}

	template<class T>

	MatrizDispersaNodo<T> *MatrizDispersa<T>::InsertarEnFila(MatrizDispersaNodo<T> *Nodo, MatrizDispersaNodo<T> *HeaderColumna)
	{
		MatrizDispersaNodo<T> *Temp = HeaderColumna;
		bool Bandera = false;

		while(true)
		{
			if(Temp -> getY() == Nodo -> getY())
			{
				Temp -> setX(Nodo -> getX());
				Temp -> setObject(Nodo -> getObject());
				return Temp;
			}
			else if(Temp -> getY() > Nodo -> getY())
			{
				Bandera = true;
				break;
			}

			if(Temp -> getDownNode() != nullptr)
			{
				Temp = Temp -> getDownNode();
			}
			else
			{
				Bandera = false;
				break;
			}
		}

		if(Bandera)
		{
			Nodo -> setDownNode(Temp);
			Temp -> getUpNode() -> setDownNode(Nodo);
			Nodo -> setUpNode(Temp -> getUpNode());
			Temp -> setUpNode(Nodo);
		}
		else
		{
			Temp -> setDownNode(Nodo);
			Nodo -> setUpNode(Temp);
		}
		return Nodo;
	}

	template<class T>

	MatrizDispersaNodo<T> *MatrizDispersa<T>::CrearColumna(int x)
	{
		MatrizDispersaNodo<T> *HeaderColumna = Raiz;
		MatrizDispersaNodo<T> *Columna = InsertarEnColumna(new MatrizDispersaNodo<T>(x, -1), HeaderColumna);
		return Columna;
	}

	template<class T>

	MatrizDispersaNodo<T> *MatrizDispersa<T>::CrearFila(int y)
	{
		MatrizDispersaNodo<T> *HeaderFila = Raiz;
		MatrizDispersaNodo<T> *Fila = InsertarEnFila(new MatrizDispersaNodo<T>(-1, y), HeaderFila);
		return Fila;
	}

	template<class T>

	void MatrizDispersa<T>::InsertarMatrizDispersa(int x, int y, T object)
	{
		MatrizDispersaNodo<T> *Nodo = new MatrizDispersaNodo<T>(x, y, object);
		MatrizDispersaNodo<T> *ColumnaNodo = BuscarColumna(x);
		MatrizDispersaNodo<T> *FilaNodo = BuscarFila(y);

		if(ColumnaNodo == nullptr && FilaNodo == nullptr)
		{
			ColumnaNodo = CrearColumna(x);
			FilaNodo = CrearFila(y);
			Nodo = InsertarEnColumna(Nodo, FilaNodo);
			Nodo = InsertarEnFila(Nodo, ColumnaNodo);
			return;
		}
		else if(ColumnaNodo == nullptr && FilaNodo != nullptr)
		{
			ColumnaNodo = CrearColumna(x);
			Nodo = InsertarEnColumna(Nodo, FilaNodo);
			Nodo = InsertarEnFila(Nodo, ColumnaNodo);
			return;
		}
		else if(ColumnaNodo != nullptr && FilaNodo == nullptr)
		{
			FilaNodo = CrearFila(y);
			Nodo = InsertarEnColumna(Nodo, FilaNodo);
			Nodo = InsertarEnFila(Nodo, ColumnaNodo);
			return;
		}
		else if(ColumnaNodo != nullptr && FilaNodo != nullptr)
		{
			Nodo = InsertarEnColumna(Nodo, FilaNodo);
			Nodo = InsertarEnFila(Nodo, ColumnaNodo);
			return;
		}
	}

	template<class T>

	void MatrizDispersa<T>::ImprimirFilaHeaders()
	{
		MatrizDispersaNodo<T> *Aux = Raiz;
		while(Aux != nullptr)
		{
			cout << "^" << endl << Aux -> getX() << "," << Aux -> getY() << endl;
			Aux = Aux -> getDownNode();
		}
	}

	template<class T>

	void MatrizDispersa<T>::ImprimirColumnaHeaders()
	{
		MatrizDispersaNodo<T> *Aux = Raiz;
		while(Aux != nullptr)
		{
			cout << Aux -> getX() << "," << Aux -> getY() << " -> ";
			Aux = Aux -> getNextNode();
		}
		cout << endl;
	}

	template<class T>

	void MatrizDispersa<T>::ImprimirFilas()
	{
		MatrizDispersaNodo<T> *AuxFila = Raiz -> getDownNode();
		MatrizDispersaNodo<T> *Aux = AuxFila;

		while(AuxFila != nullptr)
		{
			while(Aux != nullptr)
			{
				cout << Aux -> getObject() << " -> ";
				Aux = Aux -> getNextNode();
			}

			AuxFila = AuxFila -> getDownNode();
			Aux = AuxFila;
			cout << endl;
		}
		cout << endl;
	}

	template<class T>

	void MatrizDispersa<T>::ImprimirColumnas()
	{
		MatrizDispersaNodo<T> *AuxColumna = Raiz -> getNextNode();
		MatrizDispersaNodo<T> *Aux = AuxColumna;

		while(AuxColumna != nullptr)
		{
			while(Aux != nullptr)
			{
				cout << "^" << endl << Aux -> getObject() << endl;
				Aux = Aux -> getDownNode();
			}

			AuxColumna = AuxColumna -> getNextNode();
			Aux = AuxColumna;
			cout << endl;
		}
		cout << endl;
	}

	template<class T>

	void MatrizDispersa<T>::ReporteMatrizDispersa()
	{
		ofstream Archivo("C:\\GraficasE\\TableroMatrizDispersa.dot");

		if(Archivo.is_open())
		{
			if(Raiz != nullptr)
			{
				MatrizDispersaNodo<T> *FilaHeaders = Raiz -> getDownNode();
				MatrizDispersaNodo<T> *ColumnaHeaders = Raiz -> getNextNode();
				MatrizDispersaNodo<T> *AuxFila = Raiz -> getDownNode();
				MatrizDispersaNodo<T> *AuxColumna = Raiz -> getNextNode();
				MatrizDispersaNodo<T> *Aux;

				Archivo<< "digraph G {" << endl;
				Archivo<< "node [shape = box]" << endl;
				Archivo<< "Mt[ label = \"Matriz Dispersa\", width = 1.5, font = \"Times New Roman\", fontcolor = \"#0131D3\", style = filled, fillcolor = \"#6CFFA4\", group = 1 ];" << endl;

				while(FilaHeaders != nullptr)
				{
					Archivo<< "R" << FilaHeaders -> getY();
					Archivo<< "[label = \"" << FilaHeaders -> getY() << "\"";
					Archivo<< "width = 1.5, style = filled, fillcolor = \"#9DFF20\", fontcolor = \"#0131D3\", group = 1 ];" << endl;
					FilaHeaders = FilaHeaders -> getDownNode();
				}

				FilaHeaders = Raiz -> getDownNode();

				while(FilaHeaders->getDownNode() != nullptr)
				{
					Archivo<< "R" << FilaHeaders -> getY() << "-> R" << FilaHeaders -> getDownNode() -> getY() << ";" << endl;
					FilaHeaders = FilaHeaders -> getDownNode();
				}

				while(ColumnaHeaders != nullptr)
				{
					Archivo<< "C" << ColumnaHeaders -> getX();
					Archivo<< "[label = \"" << ColumnaHeaders -> getX() << "\"";
					Archivo<< "width = 1.5, style = filled, fillcolor = \"#9DFF20\", fontcolor = \"#0131D3\", group =" << ColumnaHeaders -> getX() + 2 << "];" << endl;
					ColumnaHeaders = ColumnaHeaders -> getNextNode();
				}

				ColumnaHeaders = Raiz -> getNextNode();

				while(ColumnaHeaders->getNextNode() != nullptr)
				{
					Archivo<< "C" << ColumnaHeaders ->getX() << "-> C" << ColumnaHeaders->getNextNode() -> getX() << ";" << endl;
					ColumnaHeaders = ColumnaHeaders -> getNextNode();
				}

				Archivo<< "Mt -> R" << Raiz -> getDownNode() -> getY() << ";" << endl;
				Archivo<< "Mt -> C" << Raiz -> getNextNode() -> getX() << ";" << endl;

				Archivo << "{ rank = same; Mt;";
				ColumnaHeaders = Raiz -> getNextNode();

				while(ColumnaHeaders != nullptr)
				{
					Archivo << "C" << ColumnaHeaders -> getX() << ";";
					ColumnaHeaders = ColumnaHeaders -> getNextNode();
				}

				Archivo<< "}" << endl;

				while(AuxFila != nullptr)
				{
					Aux = AuxFila -> getNextNode();

					while(Aux != nullptr)
					{
						Archivo<< "C" << Aux -> getX();
						Archivo<< "R" << Aux -> getY();
						Archivo<< " [label = \"" << Aux -> getObject() << "\" width = 1.5,";
						Archivo<< " group = " << Aux -> getX() + 2 << "];" << endl;
						Aux = Aux -> getNextNode();
					}
					AuxFila = AuxFila->getDownNode();
				}

				AuxFila = Raiz -> getDownNode();

				while(AuxFila != nullptr)
				{
					Aux = AuxFila;

					while(Aux -> getNextNode() != nullptr)
					{
						if(Aux -> getX() == -1)
						{
							Archivo<< "R" << Aux -> getY();
						}
						else
						{
							Archivo<< "C" << Aux -> getX();
							Archivo<< "R" << Aux -> getY();
						}
						Archivo<< " -> C" << Aux -> getNextNode() -> getX();
						Archivo<< "R" << Aux -> getNextNode() -> getY() << " [dir=\"both\"];" << endl;
						Aux = Aux -> getNextNode();
					}

					Archivo<< "{ rank = same; ";
					Aux = AuxFila;

					while(Aux != nullptr)
					{
						if(Aux -> getX() == -1)
						{
							Archivo<< " R" << Aux -> getY() << ";";
						}
						else
						{
							Archivo<< " C" << Aux -> getX();
							Archivo<< "R" << Aux -> getY() << ";";
						}
						Aux = Aux->getNextNode();
					}
					Archivo << "}" << endl;
					AuxFila = AuxFila -> getDownNode();
				}

				while(AuxColumna != nullptr)
				{
					Aux = AuxColumna;

					while(Aux -> getDownNode() != nullptr)
					{
						if(Aux -> getY() == -1)
						{
							Archivo<< "C" << Aux -> getX();
						}
						else
						{
							Archivo<< "C" << Aux -> getX();
							Archivo<< "R" << Aux -> getY();
						}
						Archivo<< " -> C" << Aux -> getDownNode() -> getX();
						Archivo<< "R" << Aux -> getDownNode() -> getY() << " [dir=\"both\"];" << endl;
						Aux = Aux -> getDownNode();
					}
					AuxColumna = AuxColumna->getNextNode();
				}

				Archivo << "}" << endl;
				Archivo.close();

                //Generar Imagen
				system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\GraficasE\\TableroMatrizDispersa.dot -o C:\\GraficasE\\TableroMatrizDispersa.png");
				//Abrir Imagen
				system("C:\\GraficasE\\TableroMatrizDispersa.png &" );
			}
			else
			{
				cout << "No Se Puede Abrir El Archivo";
			}
		}
	}

//------------------------------------------------------------------------------
#endif
