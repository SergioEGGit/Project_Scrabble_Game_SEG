//------------------------------Librerias---------------------------------------

	#pragma hdrstop

	#include "Metodos.h"
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
	#include <typeinfo>
	#include <sstream>
	#include <ctime>
	#include <DiccionarioLDC.h>
	#include <FichasCola.h>
	#include <RecorridosLS.h>
	#include <JugadoresABB.h>
	#include <FichasLS.h>
	#include <sys/stat.h>
	#include <lib/rapidjson/document.h>
	#include <lib/rapidjson/prettywriter.h>
	#include <lib/rapidjson/stringbuffer.h>
	using namespace std;
	using namespace rapidjson;

//------------------------------------------------------------------------------

	#pragma package(smart_init)

//------------------------------Variables---------------------------------------

	int Variables::AnchoPantalla = 0;
	int Variables::AltoPantalla = 0;
	int Variables::OpcionMenu = 0;
	int Variables::OpcionJugar = 0;
	string Variables::RutaArchivo = "";
	int Variables::DimensionTablero = 0;
	int Variables::OpcionReporte = 0;
	string Variables::LetraColaFichas = "";
	int Variables::PunteoColaFichas = 0;
	string Variables::NombreJugador = "";
	int Variables::ContadorArbol = 0;
	string Variables::CadenaArbol = "";
	string Variables::Jugador1 = "";
    string Variables::Jugador2 = "";

//------------------------------Interfaz----------------------------------------


    //-----------------------------Colores----------------------------------

		void Color(int Background, int Text)
		{
			// Funci�n para cambiar el color del fondo y/o pantalla

			HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
			// Para cambiar el color, se utilizan n�meros desde el 0 hasta el 255.
			// Pero, para convertir los colores a un valor adecuado, se realiza el siguiente c�lculo.
			int    New_Color= Text + (Background * 16);
			SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
		}

	//---------------------------Fullscreen---------------------------------

		void Fullscreen()
		{
			keybd_event(VK_MENU,
						   0x38,
							  0,
							  0);
			keybd_event(VK_RETURN,
							 0x1c,
								0,
								0);
			keybd_event(VK_RETURN,
							 0x1c,
				  KEYEVENTF_KEYUP,
								0);
			keybd_event(VK_MENU,
						   0x38,
				KEYEVENTF_KEYUP,
							  0);
			return;
		}

	//---------------------Obtener Resoluci�n Pantalla----------------------

		void Resolucion()
		{
			Variables::AnchoPantalla = (GetSystemMetrics(SM_CXSCREEN) / 8) - 2;
			Variables::AltoPantalla = (GetSystemMetrics(SM_CYSCREEN) / 19) + 1;
		}

	//------------------------------Men�------------------------------------

		void MenuPrincipal()
		{
			//Informaci�n
			Color(0,4);
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 2);
			cout<< "Universidad De San Carlos De Guatemala" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 12, 4);
			cout<< "Facultad De Ingenieria" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 6);
			cout<< "Estructuras De Datos" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 6, 8);
			cout<< "Proyecto 1" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 17, 10);
			Color(0,1);
			cout<< "Sergio Alexander Echigoyen Gomez" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 6, 12);
			cout<< "201801628" <<endl;

			//Men�
			Color(0,6);
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 4, 20);
			cout<< "Menu" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 22);
			cout<< "1. Lectura De Archivo" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 24);
			cout<< "2. Juego" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 26);
			cout<< "3. Reportes" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 28);
			cout<< "4. Salir" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 30);
			cout<< "Elija Una Opcion: " <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 + 8, 30);

			cin>> Variables::OpcionMenu;
		}

		void MenuJugar()
		{
			//Men�
			Color(0,13);
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 4, 4);
			cout<< "Menu" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 6);
			cout<< "1. Nueva Partida" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 8);
			cout<< "2. Agregar Jugadores" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 10);
			cout<< "3. Agregar Fichas" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 12);
			cout<< "4. Salir" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 11, 14);
			cout<< "Elija Una Opcion: " <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 + 8, 14);

			cin>> Variables::OpcionJugar;
		}

		void MenuReporte()
		{
			//Men�
			Color(0, 11);
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 4);
			cout<< "                 Menu Reportes" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 6);
			cout<< "1. Reporte Diccionario Lista Doblemente Circular" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 8);
			cout<< "2. Reporte Fichas Cola" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 10);
			cout<< "3. Reporte Jugadores Arbol Binario De Busqueda" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 12);
			cout<< "4. Reporte Recorrido PreOrden Arbol Binario De Busqueda" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 14);
			cout<< "5. Reporte Recorrido InOrden Arbol Binario De Busqueda" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 16);
			cout<< "6. Reporte Recorrido PostOrden Arbol Binario De Busqueda" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 18);
			cout<< "7. Salir" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 20);
			cout<< "Elija Una Opcion: " <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 20);

			cin>> Variables::OpcionReporte;
		}

	//-----------------------------Marcos-----------------------------------

		void gotoxy(int x, int y)
		{
			COORD coord;
			coord.X = x;
			coord.Y = y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}

		void MarcoMenu(int Col1, int Col2, int Fil1, int Fil2)
		{
			Color(0,9);
			for(int Cols = Col1; Cols <= Col2; Cols++)
			{
				for(int Fils = Fil1; Fils <= Fil2; Fils++)
				{
					gotoxy(Cols,Fils);
					//Linea Vertical Derecha E Izquierda
					if((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
					{
						cout << (char)186;
					}
					//Linea Horizontal Superior E Inferior
					else if((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
					{
						cout << (char)205;
					}
				}
			}

			//Esquina Superior Izquierda
			gotoxy(Col1,Fil1);
			cout << (char)201;
			//Esquina Inferior Izquierda
			gotoxy(Col1,Fil2);
			cout << (char)200;
			//Esquina Superior Derecha
			gotoxy(Col2,Fil1);
			cout << (char)187;
			//Esquina Inferior Derecha
			gotoxy(Col2,Fil2);
			cout << (char)188;
		}

		void MarcoArchivo(int Col1, int Col2, int Fil1, int Fil2)
		{
			Color(0,9);
			for(int Cols = Col1; Cols <= Col2; Cols++)
			{
				for(int Fils = Fil1; Fils <= Fil2; Fils++)
				{
					gotoxy(Cols,Fils);
					//Linea Vertical Derecha E Izquierda
					if((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
					{
						cout << (char)186;
					}
					//Linea Horizontal Superior E Inferior
					else if((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
					{
						cout << (char)205;
					}

                    //Barra De T�tulo
					else if((Cols != Col1) && (Fils == Fil1 + 2))
					{
						cout << (char)205;
					}
				}
			}

			//Esquina Superior Izquierda
			gotoxy(Col1,Fil1);
			cout << (char)201;
			//Esquina Inferior Izquierda
			gotoxy(Col1,Fil2);
			cout << (char)200;
			//Esquina Superior Derecha
			gotoxy(Col2,Fil1);
			cout << (char)187;
			//Esquina Inferior Derecha
			gotoxy(Col2,Fil2);
			cout << (char)188;


			//Textos
			Color(0, 13);
			gotoxy((Variables::AnchoPantalla/2) - 18,Fil1 + 1);
			cout << "         Scrabble++ SEG";
			Color(0,12);
			gotoxy(Col1 + 50,Fil1 + 4);
			cout << "Si Desea Regresar Al Menu Principal Ingresa La Palabra Salir... ";
			Color(0,9);
			gotoxy(Col1 + 50,Fil1 + 6);
			cout << "Ingrese La Ruta Del Archivo: ";
			Color(0, 13);
			cin >> Variables::RutaArchivo;
		}

		void MarcoJugar(int Col1, int Col2, int Fil1, int Fil2)
		{
			Color(0,9);
			for(int Cols = Col1; Cols <= Col2; Cols++)
			{
				for(int Fils = Fil1; Fils <= Fil2; Fils++)
				{
					gotoxy(Cols,Fils);
					//Linea Vertical Derecha E Izquierda
					if((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
					{
						cout << (char)186;
					}
					//Linea Horizontal Superior E Inferior
					else if((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
					{
						cout << (char)205;
					}

                    //Barra De T�tulo
					else if((Cols != Col1) && (Fils == Fil1 + 2))
					{
						cout << (char)205;
					}

                    //Status Bar
					else if((Cols != Col1) && (Fils == Fil2 - 4))
					{
						cout << (char)205;
					}
				}
			}

			//Esquina Superior Izquierda
			gotoxy(Col1,Fil1);
			cout << (char)201;
			//Esquina Inferior Izquierda
			gotoxy(Col1,Fil2);
			cout << (char)200;
			//Esquina Superior Derecha
			gotoxy(Col2,Fil1);
			cout << (char)187;
			//Esquina Inferior Derecha
			gotoxy(Col2,Fil2);
			cout << (char)188;


			//Textos
			Color(0, 13);
			gotoxy((Variables::AnchoPantalla/2) - 18,Fil1 + 1);
			cout << "         Scrabble++ SEG";
		}

		void MarcoReportes(int Col1, int Col2, int Fil1, int Fil2)
		{
			Color(0,9);
			for(int Cols = Col1; Cols <= Col2; Cols++)
			{
				for(int Fils = Fil1; Fils <= Fil2; Fils++)
				{
					gotoxy(Cols,Fils);
					//Linea Vertical Derecha E Izquierda
					if((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
					{
						cout << (char)186;
					}
					//Linea Horizontal Superior E Inferior
					else if((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
					{
						cout << (char)205;
					}

                    //Barra De T�tulo
					else if((Cols != Col1) && (Fils == Fil1 + 2))
					{
						cout << (char)205;
					}
				}
			}

			//Esquina Superior Izquierda
			gotoxy(Col1,Fil1);
			cout << (char)201;
			//Esquina Inferior Izquierda
			gotoxy(Col1,Fil2);
			cout << (char)200;
			//Esquina Superior Derecha
			gotoxy(Col2,Fil1);
			cout << (char)187;
			//Esquina Inferior Derecha
			gotoxy(Col2,Fil2);
			cout << (char)188;


			//Textos
			Color(0, 13);
			gotoxy((Variables::AnchoPantalla/2) - 18,Fil1 + 1);
			cout << "              Scrabble++ SEG";
		}

		void MarcoSalir(int Col1, int Col2, int Fil1, int Fil2)
		{
			Color(0,9);
			for(int Cols = Col1; Cols <= Col2; Cols++)
			{
				for(int Fils = Fil1; Fils <= Fil2; Fils++)
				{
					gotoxy(Cols,Fils);
					//Linea Vertical Derecha E Izquierda
					if((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
					{
						cout << (char)186;
					}
					//Linea Horizontal Superior E Inferior
					else if((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
					{
						cout << (char)205;
					}

                    //Barra De T�tulo
					else if((Cols != Col1) && (Fils == Fil1 + 2))
					{
						cout << (char)205;
					}

					//Status Bar
					else if((Cols != Col1) && (Fils == Fil2 - 4))
					{
						cout << (char)205;
					}
				}
			}

			//Esquina Superior Izquierda
			gotoxy(Col1,Fil1);
			cout << (char)201;
			//Esquina Inferior Izquierda
			gotoxy(Col1,Fil2);
			cout << (char)200;
			//Esquina Superior Derecha
			gotoxy(Col2,Fil1);
			cout << (char)187;
			//Esquina Inferior Derecha
			gotoxy(Col2,Fil2);
			cout << (char)188;


			//Textos
			Color(0, 13);
			gotoxy(Col1 + 75,Fil1 + 1);
			cout << "Scrabble++ SEG";
			Color(0,13);
			gotoxy(Col1 + 66,Fil1 + 5);
			cout << "Gracias Por Jugar Vuelva Pronto..!";
		}

	//---------------------------Leer Archivos------------------------------

		void LeerArchivo(string RutaArchivo, ListaDLDC &ListaDiccionario, ListaFichas &ListaFichasDT)
		{
			stringstream Cadena;
			fstream Archivo(RutaArchivo, fstream::in);
			int Contador = 14;

			if(Archivo)
			{
				Cadena << Archivo.rdbuf();
				Archivo.close();
				Document JsonDocument;
				JsonDocument.Parse(Cadena.str().c_str());

				if(JsonDocument.IsObject())
				{
					if(JsonDocument.HasMember("dimension"))
					{
						Variables::DimensionTablero = JsonDocument["dimension"].GetInt();
						Color(0, 12);
						gotoxy((Variables::AnchoPantalla/2) - 20, 8);
						cout<< "Contenido Del Archivo:" <<endl;
						gotoxy((Variables::AnchoPantalla/2) - 20, 10);
						cout<< "Dimesion: " << Variables::DimensionTablero << "." << endl;
					}

					if(JsonDocument.HasMember("casillas"))
					{
						const Value& CasillasDoblesArray = JsonDocument["casillas"]["dobles"];
						assert(CasillasDoblesArray.IsArray());

						gotoxy((Variables::AnchoPantalla/2) - 20, 12);
						cout<< "Casillas Dobles:" << endl;

						for(SizeType i = 0; i < CasillasDoblesArray.Size(); i++)
						{
							const Value & Dobles = CasillasDoblesArray[i];
							int DoblesCoorX = 0;
							int DoblesCoorY = 0;

							if(Dobles.HasMember("x"))
							{
								const Value & DoblesX  = Dobles["x"];
								DoblesCoorX = DoblesX.GetInt();
							}

							if(Dobles.HasMember("y"))
							{
								const Value & DoblesY  = Dobles["y"];
								DoblesCoorY = DoblesY.GetInt();
							}
							gotoxy((Variables::AnchoPantalla/2) - 17, Contador);
							Contador++;
							cout<< i + 1 << ". " << "Coor X: " << DoblesCoorX << ".  " << "Coor Y: " << DoblesCoorY << "." <<endl;
							InsertarFinalListaFichas(ListaFichasDT, DoblesCoorX, DoblesCoorY, "Dobles");
						}

						const Value& CasillasTriplesArray = JsonDocument["casillas"]["triples"];
						assert(CasillasTriplesArray.IsArray());
						Contador = Contador + 1;
						gotoxy((Variables::AnchoPantalla/2) - 20, Contador);
						cout<< "Triples" << endl;

						for(SizeType i = 0; i < CasillasTriplesArray.Size(); i++)
						{
							const Value & Triples = CasillasTriplesArray[i];
							int TriplesCoorX = 0;
							int TriplesCoorY = 0;

							if(Triples.HasMember("x"))
							{
								const Value & TriplesX  = Triples["x"];
								TriplesCoorX = TriplesX.GetInt();
							}

							if(Triples.HasMember("y"))
							{
								const Value & TriplesY  = Triples["y"];
								TriplesCoorY = TriplesY.GetInt();
							}
							gotoxy((Variables::AnchoPantalla/2) - 17, Contador + 2);
							Contador++;
							cout<< i + 1 << ". " << "Coor X: " << TriplesCoorX << "  " << "Coor Y: " << TriplesCoorY <<endl;
							InsertarFinalListaFichas(ListaFichasDT, TriplesCoorX, TriplesCoorY, "Triples");
						}
					}

					if(JsonDocument.HasMember("diccionario"))
					{
						const Value& DiccionarioArray = JsonDocument["diccionario"];
						assert(DiccionarioArray.IsArray());

						gotoxy((Variables::AnchoPantalla/2) - 20, Contador + 3);
						cout<< "Diccionario: " << endl;

						for(SizeType i = 0; i < DiccionarioArray.Size(); i++)
						{
							const Value & PalabrasArray  = DiccionarioArray[i];
							string Palabra = "";

							if(PalabrasArray.HasMember("palabra"))
							{
								const Value & Palabras  = PalabrasArray["palabra"];
								Palabra = Palabras.GetString();
								InsertarUltimoPalabraDLDC(ListaDiccionario, Palabra);
							}
							gotoxy((Variables::AnchoPantalla/2) - 17, Contador + 5);
							Contador++;
							cout<< i + 1 << "." << Palabra <<endl;
						}
					}

					gotoxy((Variables::AnchoPantalla/2) - 20, Contador + 7);
					Color(0, 10);
					cout<< "Datos Agregados Con Exito." <<endl;
				}
				else
				{
					gotoxy((Variables::AnchoPantalla/2) - 5, 5);
					Color(0, 4);
					cout<< "Exite Un Error En La Estuctura Del Archivo." <<endl;
				}
			}
		   else
		   {
			   gotoxy((Variables::AnchoPantalla/2) - 5, 6);
			   Color(0, 4);
			   cout<< "No Se Encuentra El Archivo Seleccionado." <<endl;
		   }
		   getch();

		}

	//-------------------------Generar Fichas-------------------------------

		void GenerarFichas(ColaFichas &Cabeza, ColaFichas &Cola)
		{
			string Fichas[25][3];

			Fichas[0][0] = "A"; Fichas[0][1] = "1"; Fichas[0][2] = "12";
			Fichas[1][0] = "E"; Fichas[1][1] = "1"; Fichas[1][2] = "12";
			Fichas[2][0] = "O"; Fichas[2][1] = "1"; Fichas[2][2] = "9";
			Fichas[3][0] = "I"; Fichas[3][1] = "1"; Fichas[3][2] = "6";
			Fichas[4][0] = "S"; Fichas[4][1] = "1"; Fichas[4][2] = "6";
			Fichas[5][0] = "N"; Fichas[5][1] = "1"; Fichas[5][2] = "5";
			Fichas[6][0] = "L"; Fichas[6][1] = "1"; Fichas[6][2] = "4";
			Fichas[7][0] = "R"; Fichas[7][1] = "1"; Fichas[7][2] = "5";
			Fichas[8][0] = "U"; Fichas[8][1] = "1"; Fichas[8][2] = "5";
			Fichas[9][0] = "T"; Fichas[9][1] = "1"; Fichas[9][2] = "4";
			Fichas[10][0] = "D"; Fichas[10][1] = "2"; Fichas[10][2] = "5";
			Fichas[11][0] = "G"; Fichas[11][1] = "2"; Fichas[11][2] = "2";
			Fichas[12][0] = "C"; Fichas[12][1] = "3"; Fichas[12][2] = "4";
			Fichas[13][0] = "B"; Fichas[13][1] = "3"; Fichas[13][2] = "2";
			Fichas[14][0] = "M"; Fichas[14][1] = "3"; Fichas[14][2] = "2";
			Fichas[15][0] = "P"; Fichas[15][1] = "3"; Fichas[15][2] = "2";
			Fichas[16][0] = "H"; Fichas[16][1] = "4"; Fichas[16][2] = "2";
			Fichas[17][0] = "F"; Fichas[17][1] = "4"; Fichas[17][2] = "1";
			Fichas[18][0] = "V"; Fichas[18][1] = "4"; Fichas[18][2] = "1";
			Fichas[19][0] = "Y"; Fichas[19][1] = "4"; Fichas[19][2] = "1";
			Fichas[20][0] = "Q"; Fichas[20][1] = "5"; Fichas[20][2] = "1";
			Fichas[21][0] = "J"; Fichas[21][1] = "8"; Fichas[21][2] = "1";
			Fichas[22][0] = "�"; Fichas[22][1] = "8"; Fichas[22][2] = "1";
			Fichas[23][0] = "X"; Fichas[23][1] = "8"; Fichas[23][2] = "1";
			Fichas[24][0] = "Z"; Fichas[24][1] = "10"; Fichas[24][2] = "1";

			int Contador = 0;
			bool Salida = true;

			do
			{
				int AntesDespues = rand() % 2;
				int NumeroRandom = CantidadColaFichas(Cabeza);
				int Posicion;

				if(AntesDespues == 0)
				{
					AntesDespues = 0;
				}
				else if(AntesDespues == 1)
				{
					AntesDespues = -1;
                }

				if(NumeroRandom == 0)
				{
					Posicion = 1;
				}
				else
				{
					Posicion = rand() % NumeroRandom + 2 + AntesDespues;;
				}

				int Cantidad = stoi(Fichas[Contador][2]);

				Contador++;

				if(Cantidad != 0)
				{
					Contador = Contador - 1;
                    InsertarEnMedioColaFichas(Cabeza, Posicion, Fichas[Contador][0], stoi(Fichas[Contador][1]));
					Cantidad = Cantidad - 1;
					Fichas[Contador][2] = to_string(Cantidad);
				}

				if(Contador == 25)
				{
					Salida = false;
				}
			}
			while(Salida);
		}

	//-----------------------------Juego------------------------------------

		void AgregarJugadores()
		{
			Color(0,9);
			gotoxy((Variables::AnchoPantalla/2) - 18, 5);
			cout << "Ingrese Un Nombre: ";
			gotoxy((Variables::AnchoPantalla/2) + 1, 5);
			cin>> Variables::NombreJugador;
		}

		void Jugar(ArbolABB &Arbol, int Contador)
		{
            Color(0, 9);
			gotoxy((Variables::AnchoPantalla/2) - 10, 4);
			cout<< "Lista De Jugadores: " <<endl;
			ImprimirABB(Arbol, Contador);
			Color(0, 12);
			gotoxy((Variables::AnchoPantalla/2) - 15, Contador + 10);
			cout<< "Seleccione Jugador 1: " <<endl;
			gotoxy((Variables::AnchoPantalla/2) + 7, Contador + 10);
			cin>> Variables::Jugador1;
			gotoxy((Variables::AnchoPantalla/2) - 15, Contador + 12);
			cout<< "Seleccione Jugador 2: " <<endl;
			gotoxy((Variables::AnchoPantalla/2) + 7, Contador + 12);
			cin>> Variables::Jugador2;
        }

	//-----------------------------Reportes---------------------------------

		void ReporteDiccionario(ListaDLDC &ListaDiccionario)
		{
			ofstream ReporteDiccionario("C:\\GraficasE\\ReporteDiccionario.dot");
			ListaDLDC aux = ListaDiccionario;
			ReporteDiccionario<< "digraph G" <<endl;
			ReporteDiccionario<< "{" <<endl;
			ReporteDiccionario<< "node [shape = box, fontname = Arial, color = blue];" <<endl;

			int Contador = 0;
			string Temp[1000];
			string Same = "";
			string Asc = "";

			if(ListaDiccionario != NULL)
			{
				do
				{
					ReporteDiccionario<< "A" << Contador << " [label = " <<"\"" << aux -> Palabra <<"\"]" <<endl;
					Temp[Contador] = "A" + to_string(Contador);
					Contador++;
					aux = aux -> sgte;
				}
				while(aux != ListaDiccionario);

				for(int i = 0; i < Contador; i++)
				{
					Same = Same + Temp[i] + " ";
					if(i < Contador - 1)
					{
						Asc = Asc + Temp[i] + "->";
					}
					else
					{
						Asc = Asc + Temp[i];
					}
				}
				Asc = Asc + "->" + "A0" + "->" + "A" + to_string(Contador - 1);
				ReporteDiccionario<< "{ rank = same " << Same << "}" << endl;
				ReporteDiccionario<< Asc <<endl;
				ReporteDiccionario<< " " <<endl;
				ReporteDiccionario<< "}";
				ReporteDiccionario.close();

				//Generar Imagen
				system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\GraficasE\\ReporteDiccionario.dot -o C:\\GraficasE\\ReporteDiccionario.png");
				//Abrir Imagen
				system("C:\\GraficasE\\ReporteDiccionario.png &" );

				Color(0, 10);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 20);
				cout<< "Reporte Generado Con Exito..." <<endl;
			}
			else
			{
				Color(0, 4);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2 , 20);
				cout<< "No Se Puede Generar El Reporte La Lista Se Encuentra Vacia!" <<endl;
            }

		}

		void ReporteColaFichas(ColaFichas &Cabeza)
		{
			ofstream ReporteColaFichas("C:\\GraficasE\\ReporteColaFichas.dot");
			ColaFichas aux = Cabeza;
			ReporteColaFichas<< "digraph G" <<endl;
			ReporteColaFichas<< "{" <<endl;
			ReporteColaFichas<< "node [shape = plaintext]" <<endl;

			if(Cabeza != NULL)
			{
                ReporteColaFichas<< "some_node [" << endl;
				ReporteColaFichas<< "label =<" << endl;
				ReporteColaFichas<< "<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">" << endl;
				do
				{
					if(aux -> Letra == "�")
					{
						ReporteColaFichas<< "<tr><td bgcolor = \"lightblue\"><font color=\"#12377E\">" << "|" << " X " << aux -> Punteo << "Pts" << "</font></td></tr>" <<endl;
					}
					else
					{
                        ReporteColaFichas<< "<tr><td bgcolor = \"lightblue\"><font color=\"#12377E\">" << aux -> Letra << " X " << aux -> Punteo << "Pts" << "</font></td></tr>" <<endl;
                    }


					aux = aux -> sgte;
				}
				while(aux != NULL);
				ReporteColaFichas<< " </table>>" <<endl;
				ReporteColaFichas<< " " <<endl;
				ReporteColaFichas<< "]; " <<endl;
				ReporteColaFichas<< " " <<endl;
				ReporteColaFichas<< "}";
				ReporteColaFichas.close();

				//Generar Imagen
				system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\GraficasE\\ReporteColaFichas.dot -o C:\\GraficasE\\ReporteColaFichas.png");
				//Abrir Imagen
				system("C:\\GraficasE\\ReporteColaFichas.png &" );

				Color(0, 10);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 20);
				cout<< "Reporte Generado Con Exito..." <<endl;
			}
			else
			{
				Color(0, 4);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 20);
				cout<< "No Se Puede Generar El Reporte La Cola Se Encuentra Vacia!" <<endl;
			}
		}

		void ReporteArbolPreOrden(ListaLS &Lista)
		{
			ofstream ReporteArbolPreOrden("C:\\GraficasE\\ReporteArbolPreOrden.dot");
			ListaLS aux = Lista;
			ReporteArbolPreOrden<< "digraph G" <<endl;
			ReporteArbolPreOrden<< "{" <<endl;
			ReporteArbolPreOrden<< "node [shape = box, fontname = Arial, color = purple]" <<endl;

            int Contador = 0;
			string Temp[1000];
			string Same = "";
			string Asc = "";

			if(Lista != NULL)
			{
                do
				{
					ReporteArbolPreOrden<< "A" << Contador << " [label = " <<"\"" << aux -> Nombre <<"\"]" <<endl;
					Temp[Contador] = "A" + to_string(Contador);
					Contador++;
					aux = aux -> sgte;
				}
				while(aux != NULL);

				for(int i = 0; i < Contador; i++)
				{
					Same = Same + Temp[i] + " ";
					if(i < Contador - 1)
					{
						Asc = Asc + Temp[i] + "->";
					}
					else
					{
						Asc = Asc + Temp[i];
					}
				}
				ReporteArbolPreOrden<< "{ rank = same " << Same << "}" << endl;
				ReporteArbolPreOrden<< Asc <<endl;
				ReporteArbolPreOrden<< " " <<endl;
				ReporteArbolPreOrden<< "}";
				ReporteArbolPreOrden.close();

				//Generar Imagen
				system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\GraficasE\\ReporteArbolPreOrden.dot -o C:\\GraficasE\\ReporteArbolPreOrden.png");
				//Abrir Imagen
				system("C:\\GraficasE\\ReporteArbolPreOrden.png &" );

				Color(0, 10);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 20);
				cout<< "Reporte Generado Con Exito..." <<endl;
			}
			else
			{
				Color(0, 4);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 20);
				cout<< "No Se Puede Generar El Reporte El Arbol Se Encuentra Vacio!" <<endl;
			}
		}

		void ReporteArbolInOrden(ListaLS &Lista)
		{
			ofstream ReporteArbolInOrden("C:\\GraficasE\\ReporteArbolInOrden.dot");
			ListaLS aux = Lista;
			ReporteArbolInOrden<< "digraph G" <<endl;
			ReporteArbolInOrden<< "{" <<endl;
			ReporteArbolInOrden<< "node [shape = box, fontname = Arial, color = orange]" <<endl;

            int Contador = 0;
			string Temp[1000];
			string Same = "";
			string Asc = "";

			if(Lista != NULL)
			{
                do
				{
					ReporteArbolInOrden<< "A" << Contador << " [label = " <<"\"" << aux -> Nombre <<"\"]" <<endl;
					Temp[Contador] = "A" + to_string(Contador);
					Contador++;
					aux = aux -> sgte;
				}
				while(aux != NULL);

				for(int i = 0; i < Contador; i++)
				{
					Same = Same + Temp[i] + " ";
					if(i < Contador - 1)
					{
						Asc = Asc + Temp[i] + "->";
					}
					else
					{
						Asc = Asc + Temp[i];
					}
				}
				ReporteArbolInOrden<< "{ rank = same " << Same << "}" << endl;
				ReporteArbolInOrden<< Asc <<endl;
				ReporteArbolInOrden<< " " <<endl;
				ReporteArbolInOrden<< "}";
				ReporteArbolInOrden.close();

				//Generar Imagen
				system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\GraficasE\\ReporteArbolInOrden.dot -o C:\\GraficasE\\ReporteArbolInOrden.png");
				//Abrir Imagen
				system("C:\\GraficasE\\ReporteArbolInOrden.png &" );

				Color(0, 10);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 20);
				cout<< "Reporte Generado Con Exito..." <<endl;
			}
			else
			{
				Color(0, 4);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 20);
				cout<< "No Se Puede Generar El Reporte El Arbol Se Encuentra Vacio!" <<endl;
			}
		}

		void ReporteArbolPostOrden(ListaLS &Lista)
		{
			ofstream ReporteArbolPostOrden("C:\\GraficasE\\ReporteArbolPostOrden.dot");
			ListaLS aux = Lista;
			ReporteArbolPostOrden<< "digraph G" <<endl;
			ReporteArbolPostOrden<< "{" <<endl;
			ReporteArbolPostOrden<< "node [shape = box, fontname = Arial, color = brown]" <<endl;

            int Contador = 0;
			string Temp[1000];
			string Same = "";
			string Asc = "";

			if(Lista != NULL)
			{
                do
				{
					ReporteArbolPostOrden<< "A" << Contador << " [label = " <<"\"" << aux -> Nombre <<"\"]" <<endl;
					Temp[Contador] = "A" + to_string(Contador);
					Contador++;
					aux = aux -> sgte;
				}
				while(aux != NULL);

				for(int i = 0; i < Contador; i++)
				{
					Same = Same + Temp[i] + " ";
					if(i < Contador - 1)
					{
						Asc = Asc + Temp[i] + "->";
					}
					else
					{
						Asc = Asc + Temp[i];
					}
				}
				ReporteArbolPostOrden<< "{ rank = same " << Same << "}" << endl;
				ReporteArbolPostOrden<< Asc <<endl;
				ReporteArbolPostOrden<< " " <<endl;
				ReporteArbolPostOrden<< "}";
				ReporteArbolPostOrden.close();

				//Generar Imagen
				system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\GraficasE\\ReporteArbolPostOrden.dot -o C:\\GraficasE\\ReporteArbolPostOrden.png");
				//Abrir Imagen
				system("C:\\GraficasE\\ReporteArbolPostOrden.png &" );

				Color(0, 10);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 20);
				cout<< "Reporte Generado Con Exito..." <<endl;
			}
			else
			{
				Color(0, 4);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 20);
				cout<< "No Se Puede Generar El Reporte El Arbol Se Encuentra Vacio!" <<endl;
			}
		}

		void ReporteArbolBinarioBusqueda(ArbolABB &Arbol)
		{
			ofstream ReporteArbolBinarioBusqueda("C:\\GraficasE\\ReporteArbolBinarioBusqueda.dot");
			ReporteArbolBinarioBusqueda<< "digraph G" <<endl;
			ReporteArbolBinarioBusqueda<< "{" <<endl;
			ReporteArbolBinarioBusqueda<< "node [shape = circle, fontname = Arial, color = red];" <<endl;
			ReporteArbolBinarioBusqueda<< ReporteABB(Arbol) <<endl;
			ReporteArbolBinarioBusqueda<< "}" <<endl;
			ReporteArbolBinarioBusqueda.close();

			//Generar Imagen
			system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\GraficasE\\ReporteArbolBinarioBusqueda.dot -o C:\\GraficasE\\ReporteArbolBinarioBusqueda.png");
			//Abrir Imagen
			system("C:\\GraficasE\\ReporteArbolBinarioBusqueda.png &" );

			if(ReporteABB(Arbol) == "")
			{
                Color(0, 4);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 20);
			    cout<< "No Se Puede Generar El Reporte La Cola Se Encuentra Vacia!" <<endl;
			}
			else
			{
				Color(0, 10);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 20);
				cout<< "Reporte Generado Con Exito..." <<endl;
			}
		}



