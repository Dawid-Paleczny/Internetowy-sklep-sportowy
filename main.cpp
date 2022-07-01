#include "sprzet.hpp"
#include "sklep_sportowy.hpp"
#include "klient.hpp"
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<ctime>
#include <cstdio>
using namespace std;



int main()
{
	srand((time(NULL)));
	//ID_kierownika_sklepu to 957699
	Sklep_sportowy d1(10, 10);


	do
	{
		char wybor;

		cout << "Wlasciciel --   w" << endl;
		cout << "Klient --   k" << endl;
		cout << "Zakoncz  --   z" << endl;

	wprowadz_ponownie1:
		cin.clear(); //resetuje flagi strumienia wejœciowego. Jeœli wczytanie zakoñczy siê niepowodzeniem, strumieñ jest zablokowany
					//póki nie zresetuje siê flag.
		cin.sync(); //opró¿nia bufor strumienia z pozosta³oœci, ale nie potrafi dzia³aæ na zablokowanym strumieniu
		cin >> wybor;

		if (wybor == 'z')
		{
			break;
		}
		switch (wybor)
		{
		case 'w':
		{
			int temp_ID = 0;
			cout << "Podaj swoje ID : ";
			cin >> temp_ID;
			if (temp_ID == d1.ID_kierownika_sklepu)
			{
				do
				{
					char kierownik_decyzje;

					cout << endl << "Modyfikuj istniejacy sprzet --   m" << endl;
					cout << "Dodaj nowy sprzet --   n" << endl;
					cout << "Sprawdz historie zakupow klientow --   s" << endl;
					cout << "Zakoncz  --   z" << endl;

				wprowadz_ponownie2:
					cin.clear(); //resetuje flagi strumienia wejœciowego. Jeœli wczytanie zakoñczy siê niepowodzeniem, strumieñ jest zablokowany
								//póki nie zresetuje siê flag.
					cin.sync(); //opró¿nia bufor strumienia z pozosta³oœci, ale nie potrafi dzia³aæ na zablokowanym strumieniu
					cin >> kierownik_decyzje;

					if (kierownik_decyzje == 'z')
					{
						break;
					}
					switch (kierownik_decyzje)
					{
					case 'm':
					{
						d1.Modyfikuj();
						break;
					}


					case 'n':
					{
						d1.Dodaj();
						break;
					}

					case 's':
					{
						d1.Wypisz_historie_zakupow_klientow();
						break;
					}

					default:
					{
						goto wprowadz_ponownie2;
						break;
					}

					}
					} while (1);



				}
			else
				cout << endl << "Numer ID jest niepoprawny"<<endl<<endl;

			break;
			}




		case 'k':
		{
			do
			{
				char wybor_klienta;

			wprowadz_ponownie5:

				cout << endl << "Zaloguj sie --   l" << endl;
				cout << "Zarejestruj sie --   r" << endl;
				cout << "Zakoncz  --   z" << endl;
			
			wprowadz_ponownie3:
				cin.clear(); //resetuje flagi strumienia wejœciowego. Jeœli wczytanie zakoñczy siê niepowodzeniem, strumieñ jest zablokowany
							//póki nie zresetuje siê flag.
				cin.sync(); //opró¿nia bufor strumienia z pozosta³oœci, ale nie potrafi dzia³aæ na zablokowanym strumieniu
				cin >> wybor_klienta;


				if (wybor_klienta == 'z')
				{
					break;
				}
				switch (wybor_klienta)
				{
				case 'l':
				{
					int temp_ID = 0;
					cout << "Podaj swoj numer identyfikacyjny: ";
					cin >> temp_ID;
					for (int n = 0; n < d1.liczba_osob_ktora_odwiedzila_sklep; n++)
					{
						if (temp_ID == d1.Tablica_klientow[n].ID)
						{

							cout << "Twoj numer identyfikacyjny jest prawidlowy" << endl;
							d1.Dokonaj_zakupu(n, temp_ID);
							goto wprowadz_ponownie5;

						}
						else
						{
							cout << endl << "Twoj numer identyfikacyjny jest jest niepoprawny" << endl;
						}
					}
					break;
				}


				case 'r':
				{
					d1.Dodaj_klienta();
					break;
				}

				default:
				{
					goto wprowadz_ponownie3;
					break;
				}

				}
			} while (1);


			break;
		}
		default:
		{
			goto wprowadz_ponownie1;
			break;
		}

		}
		} while (1);


		
		
		return 0;
	}


