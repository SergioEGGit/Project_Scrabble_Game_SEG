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
	#include <MatrizDispersa.h>
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
	bool Variables::TerminarJuego = true;
	int Variables::ContadorReccorridos = 1;
	int Variables::OpcionOpcionesJuego = 0;
	string CadenaEliminarArray[8];
	string FichasAgregadasArray[50][2];
	int PosicionesArray[50][2];
	int ContadorArray = 0;
	int ContadorFichasArray = 0;
	int ContadorPosicionArray = 0;

//------------------------------Interfaz----------------------------------------


	//------------------------------Varios----------------------------------

		void Color(int Background, int Text)
		{
			// Funci�n para cambiar el color del fondo y/o pantalla

			HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
			// Para cambiar el color, se utilizan n�meros desde el 0 hasta el 255.
			// Pero, para convertir los colores a un valor adecuado, se realiza el siguiente c�lculo.
			int    New_Color= Text + (Background * 16);
			SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
		}

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

		void Resolucion()
		{
			Variables::AnchoPantalla = (GetSystemMetrics(SM_CXSCREEN) / 8) - 2;
			Variables::AltoPantalla = (GetSystemMetrics(SM_CYSCREEN) / 19) + 1;
		}

		void SepararCadenaEliminar(string CadenaEliminar)
		{
			char Cadena[10];
			char Delimitador[] = ",";

			strcpy(Cadena , CadenaEliminar.c_str());

			char *Tokens = strtok(Cadena, Delimitador);

			if(Tokens != NULL)
			{
				while(Tokens != NULL)
				{
					CadenaEliminarArray[ContadorArray] = Tokens;
					Tokens = strtok(NULL, Delimitador);
					ContadorArray++;
				}
			}
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
			cout<< "7. Reporte Historial De Puntaje Por Jugador Lista Simple Ordenada" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 20);
			cout<< "8. Reporte Scorboard Lista Simple Ordenada" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 22);
			cout<< "9. Reporte Tablero Matriz Dispersa" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 24);
			cout<< "10. Reporte Fichas Por Jugador Lista Doblemente Enlazada" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 26);
			cout<< "11. Salir" <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 20, 28);
			cout<< "Elija Una Opcion: " <<endl;
			gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);

			cin>> Variables::OpcionReporte;
		}

		void MenuOpcionesJuego()
		{
            Color(0, 11);
			gotoxy((Variables::AnchoPantalla/2) - 15, 8);
			cout<< "         Menu Juego" <<endl;
			gotoxy((Variables::AnchoPantalla/2) - 15, 10);
			cout<< "     1. Ingresar Ficha" << endl;
			gotoxy((Variables::AnchoPantalla/2) - 15, 12);
			cout<< "     2. Validar Turno" << endl;
			gotoxy((Variables::AnchoPantalla/2) - 15, 14);
			cout<< "     3. Cambiar Fichas" << endl;
			gotoxy((Variables::AnchoPantalla/2) - 15, 16);
			cout<< "     4. Terminar Turno" << endl;
			gotoxy((Variables::AnchoPantalla/2) - 15, 18);
			cout<< "     5. Terminar Partida" << endl;
			gotoxy((Variables::AnchoPantalla/2) - 15, 20);
			cout<< "    Ingrese Una Opcion:    " << endl;
			gotoxy((Variables::AnchoPantalla/2) + 9, 20);
			cin>> Variables::OpcionOpcionesJuego;
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

		void LeerArchivo(MatrizDispersa<string> &MatrizDispersaMD, string RutaArchivo, ListaDLDC &ListaDiccionario, ListaFichas &ListaFichasDT)
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
						int Centro = Variables::DimensionTablero / 2;
						MatrizDispersaMD.InsertarMatrizDispersa(Centro, Centro, "Centro");
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
							MatrizDispersaMD.InsertarMatrizDispersa(DoblesCoorX, DoblesCoorY, "Doble");
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
							MatrizDispersaMD.InsertarMatrizDispersa(TriplesCoorX, TriplesCoorY, "Triple");
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

		void Jugar(ArbolABB &Arbol, ListaLS &Lista, ListaLDJ &CabezaJugador1, ListaLDJ &CabezaJugador2, ListaLDJ &ColaJugador1, ListaLDJ &ColaJugador2,  ColaFichas &FichasColaCabeza, ColaFichas &FichasColaCola, MatrizDispersa<string> &MatrizDispersaMD, int Contador)
		{
			Color(0, 9);
			gotoxy((Variables::AnchoPantalla/2) - 10, 4);
			cout<< "Lista De Jugadores: " <<endl;
			Lista = NULL;
			RecorridoPreOrden(Arbol, Lista);
			ImprimirRecorridosLS(Lista, Contador);

			int BanderaNota = 0;
			int PosicionInsertar = rand() % CantidadColaFichas(FichasColaCabeza);
			string TerminarPartida = "";
			string CadenaEliminar = "";
			int LetraIngresar = 0;
			int PosicionX = Variables::DimensionTablero;
			int PosicionY = Variables::DimensionTablero;
			bool SalidaJugador1 = true;
			bool SalidaJugador2 = true;
			bool VerificarPosicionX = true;
			bool VerificarPosicionY = true;
			bool ValidarTurno = true;
			Variables::TerminarJuego = true;

			while(SalidaJugador1)
			{
                Color(0, 12);
				gotoxy((Variables::AnchoPantalla/2) - 15, Variables::ContadorReccorridos + 1);
				cout<< "Seleccione Jugador 1: " <<endl;
				gotoxy((Variables::AnchoPantalla/2) + 7, Variables::ContadorReccorridos + 1);
				cout<<"                                                " <<endl;
				gotoxy((Variables::AnchoPantalla/2) + 7, Variables::ContadorReccorridos + 1);
				cin>> Variables::Jugador1;
				if(BusquedaABB(Arbol, Variables::Jugador1) == true)
				{
					SalidaJugador1 = false;
				}
				else
				{
					Color(0, 4);
					gotoxy((Variables::AnchoPantalla/2) + 7, Variables::ContadorReccorridos + 1);
					cout<< "El Usuario Indicado No Existe En El Sistema" <<endl;
					system("pause > 0");
					SalidaJugador1 = true;
                }
			}

			while(SalidaJugador2)
			{
                Color(0, 12);
				gotoxy((Variables::AnchoPantalla/2) - 15, Variables::ContadorReccorridos + 3);
				cout<< "Seleccione Jugador 2: " <<endl;
				gotoxy((Variables::AnchoPantalla/2) + 7, Variables::ContadorReccorridos + 3);
				cout<<"                                                " <<endl;
				gotoxy((Variables::AnchoPantalla/2) + 7, Variables::ContadorReccorridos + 3);
				cin>> Variables::Jugador2;
				if(BusquedaABB(Arbol, Variables::Jugador2) == true)
				{
					SalidaJugador2 = false;
				}
				else
				{
					Color(0, 4);
					gotoxy((Variables::AnchoPantalla/2) + 7, Variables::ContadorReccorridos + 3);
					cout<< "El Usuario Indicado No Existe En El Sistema" <<endl;
					system("pause > 0");
					SalidaJugador2 = true;
				}
			}

			int JugadorComienzo = rand() % 2 + 1;



			for(int i = 0; i < 7; i++)
			{
				EliminarColaFichas(FichasColaCabeza, FichasColaCola);
				InsertarFinalLDJ(CabezaJugador1, ColaJugador1, Variables::LetraColaFichas, Variables::PunteoColaFichas);

				EliminarColaFichas(FichasColaCabeza, FichasColaCola);
				InsertarFinalLDJ(CabezaJugador2, ColaJugador2, Variables::LetraColaFichas, Variables::PunteoColaFichas);
			}

			while(Variables::TerminarJuego)
			{

				ContadorArray = 0;
				ContadorFichasArray = 0;
				ContadorPosicionArray = 0;

				system("cls");
				MarcoJugar(0, Variables::AnchoPantalla - 2, 0, Variables::AltoPantalla + 6);

				Color(0, 11);
				gotoxy((Variables::AnchoPantalla/2) - 15, 4);
				cout<< "Bienvenido Al Juego Scrable++:" <<endl;

				if(BanderaNota == 0)
				{
					Color(0, 14);
					gotoxy((Variables::AnchoPantalla/2) + 20, 4);
					cout<< "Nota: La Primera Palabra Debe Pasar Por El Centro" <<endl;
				}

				BanderaNota++;

				Color(0, 11);
				gotoxy((Variables::AnchoPantalla/2) - 13, 6);
				cout<< "Turno Del Jugador " << JugadorComienzo << ": ";

				if(JugadorComienzo == 1)
				{
					gotoxy((Variables::AnchoPantalla/2) + 8, 6);
					cout<< Variables::Jugador1 <<endl;
				}
				else if(JugadorComienzo == 2)
				{
					gotoxy((Variables::AnchoPantalla/2) + 8, 6);
					cout<< Variables::Jugador2 <<endl;
				}

				switch(JugadorComienzo)
				{
					case 1:
						MatrizDispersaMD.ReporteMatrizDispersa();
						ReporteJugadoresFichas1Juego(CabezaJugador1);
						MenuOpcionesJuego();
						while(Variables::OpcionOpcionesJuego != 5)
						{
							switch(Variables::OpcionOpcionesJuego)
							{
								case 1:
								   Color(0, 14);
								   gotoxy((Variables::AnchoPantalla/2) - 40, 22);
								   cout<< "Escriba El Indice De La Letra Que Desea Agregar Al Tablero: " <<endl;
								   gotoxy((Variables::AnchoPantalla/2) + 20, 22);
								   cin>> PosicionInsertar;
								   EliminarLDJ(CabezaJugador1, ColaJugador1, PosicionInsertar);
								   FichasAgregadasArray[ContadorFichasArray][0] = Variables::LetraColaFichas;
								   FichasAgregadasArray[ContadorFichasArray][1] = to_string(Variables::PunteoColaFichas);
								   ContadorFichasArray++;

								   VerificarPosicionX = true;

								   while(VerificarPosicionX)
								   {
									   Color(0, 14);
									   gotoxy((Variables::AnchoPantalla/2) - 10, 24);
									   cout<< "Posicion X:                                                     " <<endl;
									   gotoxy((Variables::AnchoPantalla/2) + 2, 24);
									   cin>> PosicionX;

									   if(PosicionX > Variables::DimensionTablero)
									   {
										   gotoxy((Variables::AnchoPantalla/2) + 2, 24);
										   Color(0, 4);
										   cout<< "La Posicion Indicada Excede Los Limites Del Tablero" <<endl;
                                           system("pause > 0");
										   VerificarPosicionX = true;
									   }
									   else if(PosicionX <= Variables::DimensionTablero)
									   {
										   VerificarPosicionX = false;
									   }
								   }

								   VerificarPosicionY = true;

                                   while(VerificarPosicionY)
								   {
                                       Color(0, 14);
									   gotoxy((Variables::AnchoPantalla/2) - 10, 26);
									   cout<< "Posicion Y:                                                         " <<endl;
									   gotoxy((Variables::AnchoPantalla/2) + 2, 26);
									   cin>> PosicionY;

									   if(PosicionY > Variables::DimensionTablero)
									   {
										   gotoxy((Variables::AnchoPantalla/2) + 2, 26);
										   Color(0, 4);
										   cout<< "La Posicion Indicada Excede Los Limites Del Tablero" <<endl;
										   system("pause > 0");
										   VerificarPosicionY = true;
									   }
									   else if(PosicionY <= Variables::DimensionTablero)
									   {
										   VerificarPosicionY = false;
									   }
								   }

								   PosicionesArray[ContadorPosicionArray][0] = PosicionX;
								   PosicionesArray[ContadorPosicionArray][1] = PosicionY;
								   ContadorPosicionArray++;

								   MatrizDispersaMD.InsertarMatrizDispersa(PosicionX, PosicionY, Variables::LetraColaFichas);
								   MatrizDispersaMD.ReporteMatrizDispersa();
								   ReporteJugadoresFichas1Juego(CabezaJugador1);

                                   gotoxy((Variables::AnchoPantalla/2) - 40, 22);
								   cout<< "                                                                      " <<endl;
								   gotoxy((Variables::AnchoPantalla/2) - 10, 24);
								   cout<< "                           " <<endl;
								   gotoxy((Variables::AnchoPantalla/2) - 10, 26);
								   cout<< "                                " <<endl;

								   MenuOpcionesJuego();
								   ValidarTurno = false;
								break;

								case 2:

									MatrizDispersaMD.EliminarMatrizDispersa(7, 7);

									MatrizDispersaMD.EliminarMatrizDispersa(1, 1);

									MatrizDispersaMD.ReporteMatrizDispersa();

                                    getch();
									/*for(int i = 0; i < ContadorFichasArray; i++)
									{
										cout << FichasAgregadasArray[i][0] << ". " << FichasAgregadasArray[i][1] <<endl;
									}

									for(int i = 0; i < ContadorPosicionArray; i++)
									{
										cout << PosicionesArray[i][0] << ". " << PosicionesArray[i][1] <<endl;
									}
									getch();       */
									MenuOpcionesJuego();

								break;

								case 3:
									if(ValidarTurno)
									{
										Color(0, 12);
										gotoxy((Variables::AnchoPantalla/2) - 50, 22);
										cout<< "Escriba El Indice Separado Por Coma De Las Fichas Que Desea Eliminar: " <<endl;
										gotoxy((Variables::AnchoPantalla/2) + 20, 22);
										cin>> CadenaEliminar;
										SepararCadenaEliminar(CadenaEliminar);

										for(int i = 0; i < ContadorArray; i++)
										{
											EliminarLDJ(CabezaJugador1, ColaJugador1, stoi(CadenaEliminarArray[i]));
											PosicionInsertar = rand() % CantidadColaFichas(FichasColaCabeza) + 1;
											InsertarEnMedioColaFichas(FichasColaCabeza, PosicionInsertar, Variables::LetraColaFichas, Variables::PunteoColaFichas);
											EliminarColaFichas(FichasColaCabeza, FichasColaCola);
											InsertarEnMedioLDJ(CabezaJugador1, ColaJugador1, Variables::LetraColaFichas, Variables::PunteoColaFichas, stoi(CadenaEliminarArray[i]));
										}
										Color(0, 10);
										gotoxy((Variables::AnchoPantalla/2) - 50, 22);
										cout<< "                                                                                                      " <<endl;
										gotoxy((Variables::AnchoPantalla/2) - 20, 22);
										cout<< "Fichas Cambiadas Con Exito! Turno Jugador 2";
										system("pause > 0");
										JugadorComienzo = 2;
										Variables::OpcionOpcionesJuego = 5;
									}
									else
									{
										Color(0, 4);
										gotoxy((Variables::AnchoPantalla/2) + 9, 20);
									}
								break;

								case 4:
									if(ValidarTurno == true)
									{
										JugadorComienzo = 2;
										Variables::OpcionOpcionesJuego = 5;
									}
									else
									{
										Color(0, 4);
										gotoxy((Variables::AnchoPantalla/2) - 20, 22);
										cout<< "Debe De Validar Su Turno Antes De Terminarlo";
										system("pause > 0");
										MenuOpcionesJuego();
                                        gotoxy((Variables::AnchoPantalla/2) + 9, 20);
										cout<< "     ";
										gotoxy((Variables::AnchoPantalla/2) - 20, 22);
										cout<< "                                                       ";
									}
								break;

								case 5:
									gotoxy((Variables::AnchoPantalla/2) - 20, 22);
                                    Color(0, 12);
									cout<< "Seguro Que Desea Terminar La Partida S/N: ";
									cin>> TerminarPartida;
									if(TerminarPartida == "S")
									{
										Variables::TerminarJuego = false;
										Variables::OpcionOpcionesJuego = 5;
									}
									else
									{
										gotoxy((Variables::AnchoPantalla/2) + 9, 20);
										cout<< "     ";
										gotoxy((Variables::AnchoPantalla/2) - 20, 22);
										cout<< "                                                       ";
										MenuOpcionesJuego();
                                    }
								break;
							}
						}
					break;

					case 2:
						cout<< "soy Jugador 2";
						getch();
						Variables::TerminarJuego = false;
					break;
				}
			}
		}

	//-----------------------------Reportes---------------------------------

		void ReporteDiccionario(ListaDLDC &ListaDiccionario)
		{
			ofstream ReporteDiccionario("C:\\GraficasE\\ReporteDiccionario.dot");
			ListaDLDC aux = ListaDiccionario;
			ReporteDiccionario<< "digraph G" <<endl;
			ReporteDiccionario<< "{" <<endl;
			ReporteDiccionario<< "graph [charset=latin1]" <<endl;
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
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);
				cout<< "Reporte Generado Con Exito..." <<endl;
			}
			else
			{
				Color(0, 4);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2 , 28);
				cout<< "No Se Puede Generar El Reporte La Lista Se Encuentra Vacia!" <<endl;
			}

		}

		void ReporteColaFichas(ColaFichas &Cabeza)
		{
			ofstream ReporteColaFichas("C:\\GraficasE\\ReporteColaFichas.dot");
			ColaFichas aux = Cabeza;
			ReporteColaFichas<< "digraph G" <<endl;
			ReporteColaFichas<< "{" <<endl;
			ReporteColaFichas<< "graph [charset=latin1]" <<endl;
			ReporteColaFichas<< "node [shape = plaintext]" <<endl;

			if(Cabeza != NULL)
			{
                ReporteColaFichas<< "some_node [" << endl;
				ReporteColaFichas<< "label =<" << endl;
				ReporteColaFichas<< "<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">" << endl;
				do
				{
					ReporteColaFichas<< "<tr><td bgcolor = \"lightblue\"><font color=\"#12377E\">" << aux -> Letra << " X " << aux -> Punteo << "Pts" << "</font></td></tr>" <<endl;
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
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);
				cout<< "Reporte Generado Con Exito..." <<endl;
			}
			else
			{
				Color(0, 4);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);
				cout<< "No Se Puede Generar El Reporte La Cola Se Encuentra Vacia!" <<endl;
			}
		}

		void ReporteArbolPreOrden(ListaLS &Lista)
		{
			ofstream ReporteArbolPreOrden("C:\\GraficasE\\ReporteArbolPreOrden.dot");
			ListaLS aux = Lista;
			ReporteArbolPreOrden<< "digraph G" <<endl;
			ReporteArbolPreOrden<< "{" <<endl;
			ReporteArbolPreOrden<< "graph [charset=latin1]" <<endl;
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
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);
				cout<< "Reporte Generado Con Exito..." <<endl;
			}
			else
			{
				Color(0, 4);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);
				cout<< "No Se Puede Generar El Reporte El Arbol Se Encuentra Vacio!" <<endl;
			}
		}

		void ReporteArbolInOrden(ListaLS &Lista)
		{
			ofstream ReporteArbolInOrden("C:\\GraficasE\\ReporteArbolInOrden.dot");
			ListaLS aux = Lista;
			ReporteArbolInOrden<< "digraph G" <<endl;
			ReporteArbolInOrden<< "{" <<endl;
			ReporteArbolInOrden<< "graph [charset=latin1]" <<endl;
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
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);
				cout<< "Reporte Generado Con Exito..." <<endl;
			}
			else
			{
				Color(0, 4);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);
				cout<< "No Se Puede Generar El Reporte El Arbol Se Encuentra Vacio!" <<endl;
			}
		}

		void ReporteArbolPostOrden(ListaLS &Lista)
		{
			ofstream ReporteArbolPostOrden("C:\\GraficasE\\ReporteArbolPostOrden.dot");
			ListaLS aux = Lista;
			ReporteArbolPostOrden<< "digraph G" <<endl;
			ReporteArbolPostOrden<< "{" <<endl;
			ReporteArbolPostOrden<< "graph [charset=latin1]" <<endl;
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
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);
				cout<< "Reporte Generado Con Exito..." <<endl;
			}
			else
			{
				Color(0, 4);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);
				cout<< "No Se Puede Generar El Reporte El Arbol Se Encuentra Vacio!" <<endl;
			}
		}

		void ReporteArbolBinarioBusqueda(ArbolABB &Arbol)
		{
			ofstream ReporteArbolBinarioBusqueda("C:\\GraficasE\\ReporteArbolBinarioBusqueda.dot");
			ReporteArbolBinarioBusqueda<< "digraph G" <<endl;
			ReporteArbolBinarioBusqueda<< "{" <<endl;
			ReporteArbolBinarioBusqueda<< "graph [charset=latin1]" <<endl;
			ReporteArbolBinarioBusqueda<< "node [shape = circle, fontname = Arial, color = red];" <<endl;
			ReporteArbolBinarioBusqueda<< ReporteABB(Arbol) <<endl;
			ReporteArbolBinarioBusqueda<< "}" <<endl;
			ReporteArbolBinarioBusqueda.close();

			if(ReporteABB(Arbol) == "")
			{
                Color(0, 4);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);
				cout<< "No Se Puede Generar El Reporte El Arbol Se Encuentra Vacio!" <<endl;
			}
			else
			{
            	//Generar Imagen
				system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\GraficasE\\ReporteArbolBinarioBusqueda.dot -o C:\\GraficasE\\ReporteArbolBinarioBusqueda.png");
				//Abrir Imagen
				system("C:\\GraficasE\\ReporteArbolBinarioBusqueda.png &" );

				Color(0, 10);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);
				cout<< "Reporte Generado Con Exito..." <<endl;
			}
		}

		void ReporteJugadoresFichas1Reportes(ListaLDJ &Lista)
		{
			ofstream ReporteJugadoresFichas1("C:\\GraficasE\\ReporteJugadoresFichas1Reportes.dot");
			ListaLDJ aux = Lista;
			ReporteJugadoresFichas1<< "digraph G" <<endl;
			ReporteJugadoresFichas1<< "{" <<endl;
			ReporteJugadoresFichas1<< "graph [charset=latin1]" <<endl;
			ReporteJugadoresFichas1<< "node [shape = box, fontname = Arial, color = purple];" <<endl;

			int Contador = 0;
			string Temp[1000];
			string Same = "";
			string Asc = "";
			string Desc = "";

			if(Lista != NULL)
			{
				do
				{
					ReporteJugadoresFichas1<< "A" << Contador << " [label = " <<"\"" << aux -> Letra <<"\"]" <<endl;
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
						Desc = Desc + Temp[Contador - i - 1] + "->";
					}
					else
					{
						Asc = Asc + Temp[i];
						Desc = Desc + Temp[Contador - i - 1];
					}
				}
				ReporteJugadoresFichas1<< "{ rank = same " << Same << "}" << endl;
				ReporteJugadoresFichas1<< Asc <<endl;
				ReporteJugadoresFichas1<< " " <<endl;
                ReporteJugadoresFichas1<< Desc <<endl;
				ReporteJugadoresFichas1<< " " <<endl;
				ReporteJugadoresFichas1<< "}";
				ReporteJugadoresFichas1.close();

				//Generar Imagen
				system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\GraficasE\\ReporteJugadoresFichas1Reportes.dot -o C:\\GraficasE\\ReporteJugadoresFichas1Reportes.png");
				//Abrir Imagen
				system("C:\\GraficasE\\ReporteJugadoresFichas1Reportes.png &" );

				Color(0, 10);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);
				cout<< "Reporte Generado Con Exito..." <<endl;
			}
			else
			{
				Color(0, 4);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2 , 28);
				cout<< "No Se Puede Generar El Reporte La Lista Se Encuentra Vacia!" <<endl;
			}
		}

		void ReporteJugadoresFichas1Juego(ListaLDJ &Lista)
		{
			ofstream ReporteJugadoresFichas1("C:\\GraficasE\\ReporteJugadoresFichas1Juegos.dot");
			ListaLDJ aux = Lista;
			ReporteJugadoresFichas1<< "digraph G" <<endl;
			ReporteJugadoresFichas1<< "{" <<endl;
			ReporteJugadoresFichas1<< "graph [charset=latin1]" <<endl;
			ReporteJugadoresFichas1<< "node [shape = box, fontname = Arial, color = purple];" <<endl;

			int Contador = 1;
			string Temp[1000];
			string Same = "";
			string Asc = "";
			string Desc = "";

			ReporteJugadoresFichas1<< "A0" << " [label = " <<"\"Jugador 1: " << "\\l" << Variables::Jugador1 <<"\"]" <<endl;
			Temp[0] = "A0";
			do
			{
				ReporteJugadoresFichas1<< "A" << Contador << " [label = " <<"\"" << Contador << ". " << aux -> Letra <<"\"]" <<endl;
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
					Desc = Desc + Temp[Contador - i - 1] + "->";
				}
				else
				{
					Asc = Asc + Temp[i];
					Desc = Desc + Temp[Contador - i - 1];
				}
			}
			ReporteJugadoresFichas1<< "{ rank = same " << Same << "}" << endl;
			ReporteJugadoresFichas1<< Asc <<endl;
			ReporteJugadoresFichas1<< " " <<endl;
			ReporteJugadoresFichas1<< Desc <<endl;
			ReporteJugadoresFichas1<< " " <<endl;
			ReporteJugadoresFichas1<< "}";
			ReporteJugadoresFichas1.close();

			//Generar Imagen
			system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\GraficasE\\ReporteJugadoresFichas1Juegos.dot -o C:\\GraficasE\\ReporteJugadoresFichas1Juegos.png");
			//Abrir Imagen
			system("C:\\GraficasE\\ReporteJugadoresFichas1Juegos.png &" );
		}

		void ReporteJugadoresFichas2Reportes(ListaLDJ &Lista)
		{
			ofstream ReporteJugadoresFichas2("C:\\GraficasE\\ReporteJugadoresFichas1Reportes.dot");
			ListaLDJ aux = Lista;
			ReporteJugadoresFichas2<< "digraph G" <<endl;
			ReporteJugadoresFichas2<< "{" <<endl;
			ReporteJugadoresFichas2<< "graph [charset=latin1]" <<endl;
			ReporteJugadoresFichas2<< "node [shape = box, fontname = Arial, color = orange];" <<endl;

			int Contador = 0;
			string Temp[1000];
			string Same = "";
			string Asc = "";
			string Desc = "";

			if(aux != NULL)
			{
				do
				{
					ReporteJugadoresFichas2<< "A" << Contador << " [label = " <<"\"" << aux -> Letra <<"\"]" <<endl;
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
						Desc = Desc + Temp[Contador - i - 1] + "->";
					}
					else
					{
						Asc = Asc + Temp[i];
						Desc = Desc + Temp[Contador - i - 1];
					}
				}
				ReporteJugadoresFichas2<< "{ rank = same " << Same << "}" << endl;
				ReporteJugadoresFichas2<< Asc <<endl;
				ReporteJugadoresFichas2<< " " <<endl;
				ReporteJugadoresFichas2<< Desc <<endl;
				ReporteJugadoresFichas2<< " " <<endl;
				ReporteJugadoresFichas2<< "}";
				ReporteJugadoresFichas2.close();

				//Generar Imagen
				system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\GraficasE\\ReporteJugadoresFichas2Reportes.dot -o C:\\GraficasE\\ReporteJugadoresFichas2Reportes.png");
				//Abrir Imagen
				system("C:\\GraficasE\\ReporteJugadoresFichas2Reportes.png &" );

				Color(0, 10);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2, 28);
				cout<< "Reporte Generado Con Exito..." <<endl;
			}
			else
			{
				Color(0, 4);
				gotoxy ((Variables::AnchoPantalla - 2)/2 - 2 , 28);
				cout<< "No Se Puede Generar El Reporte La Lista Se Encuentra Vacia!" <<endl;
			}
		}

		void ReporteJugadoresFichas2Juego(ListaLDJ &Lista)
		{
			ofstream ReporteJugadoresFichas2("C:\\GraficasE\\ReporteJugadoresFichas2Juegos.dot");
			ListaLDJ aux = Lista;
			ReporteJugadoresFichas2<< "digraph G" <<endl;
			ReporteJugadoresFichas2<< "{" <<endl;
			ReporteJugadoresFichas2<< "graph [charset=latin1]" <<endl;
			ReporteJugadoresFichas2<< "node [shape = box, fontname = Arial, color = purple];" <<endl;

			int Contador = 1;
			string Temp[1000];
			string Same = "";
			string Asc = "";
			string Desc = "";

			ReporteJugadoresFichas2<< "A0" << " [label = " <<"\"Jugador 2: " << "\\l" << Variables::Jugador2 <<"\"]" <<endl;
			Temp[0] = "A0";

			do
			{
				ReporteJugadoresFichas2<< "A" << Contador << " [label = " <<"\"" << aux -> Letra <<"\"]" <<endl;
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
					Desc = Desc + Temp[Contador - i - 1] + "->";
				}
				else
				{
					Asc = Asc + Temp[i];
					Desc = Desc + Temp[Contador - i - 1];
				}
			}
			ReporteJugadoresFichas2<< "{ rank = same " << Same << "}" << endl;
			ReporteJugadoresFichas2<< Asc <<endl;
			ReporteJugadoresFichas2<< " " <<endl;
			ReporteJugadoresFichas2<< Desc <<endl;
			ReporteJugadoresFichas2<< " " <<endl;
			ReporteJugadoresFichas2<< "}";
			ReporteJugadoresFichas2.close();

			//Generar Imagen
			system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng C:\\GraficasE\\ReporteJugadoresFichas2Juegos.dot -o C:\\GraficasE\\ReporteJugadoresFichas2Juegos.png");
			//Abrir Imagen
			system("C:\\GraficasE\\ReporteJugadoresFichas2Juegos.png &" );
		}


