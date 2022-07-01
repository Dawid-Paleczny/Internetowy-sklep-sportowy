#include "sklep_sportowy.hpp"
#include <string>


Sklep_sportowy:: Sklep_sportowy( int s, int k) 
{   
		ID_kierownika_sklepu = 957699;
		aktualne_wypelnienie = 0;
		liczba_osob_ktora_odwiedzila_sklep = 0;

		dlugosc = s;
		Tablica_sprzetow = new Sprzet[dlugosc];

		max_klientow = k;
		Tablica_klientow = new Klient[max_klientow];

		

}

Sklep_sportowy::~Sklep_sportowy()
{	
	delete [] Tablica_sprzetow;
	delete [] Tablica_klientow;
}





void Sklep_sportowy::  Dodaj_klienta()
{
	
	int liczba_indeksu;

	ponowne_losowanie: // jesli klient jest ju¿ w bazie
	liczba_indeksu = rand() % 9000 + 1000;

	for (int k = 0; k < liczba_osob_ktora_odwiedzila_sklep; k++)
	{
		if (Tablica_klientow[k].ID == liczba_indeksu)
		{
			goto ponowne_losowanie;
		}
	}
	Tablica_klientow[liczba_osob_ktora_odwiedzila_sklep].ID = liczba_indeksu;
	Tablica_klientow[liczba_osob_ktora_odwiedzila_sklep].Tablica_zakupow = new string[dlugosc];
	liczba_osob_ktora_odwiedzila_sklep++;
	cout << endl << "Rejestracja powiodla sie Twoj numer identyfikacyjny to: " << liczba_indeksu;

}


void Sklep_sportowy:: Dokonaj_zakupu(int numer_klienta_w_bazie, int numer_ID_klienta)
{
	do
	{
	

		char wybor;
		cout << endl << "Dokonaj zakupu  --  d" << endl;
		cout << "Zakoncz  --   z" << endl;
		cout << "Wybierz opcje: ";
		

	wprowadz_ponownie4:
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

		case 'd':
		{
			int liczba_szt = 0;
			int indeks_produktu = 0;

			Wypisz();
			if (aktualne_wypelnienie != 0)
			{
				cout << endl << "Produkt o jakim indeksie chcesz kupic: ";
				cin.clear(); //resetuje flagi strumienia wejœciowego. Jeœli wczytanie zakoñczy siê niepowodzeniem, strumieñ jest zablokowany
						//póki nie zresetuje siê flag.
				cin.sync(); //opró¿nia bufor strumienia z pozosta³oœci, ale nie potrafi dzia³aæ na zablokowanym strumieniu
				cin >> indeks_produktu;
				if ((indeks_produktu - 1) > aktualne_wypelnienie)
				{
					cout << endl << "Produkt o takim indeksie nie istnieje." << endl;
					break;
				}
				else
				{
					cout << endl << "Wprowadz ile sztuk tego produktu chcesz kupic: ";
					cin.clear(); //resetuje flagi strumienia wejœciowego. Jeœli wczytanie zakoñczy siê niepowodzeniem, strumieñ jest zablokowany
						//póki nie zresetuje siê flag.
					cin.sync(); //opró¿nia bufor strumienia z pozosta³oœci, ale nie potrafi dzia³aæ na zablokowanym strumieniu
					cin >> liczba_szt;
					if (liczba_szt > Tablica_sprzetow[(indeks_produktu - 1)].f_ilosc())
					{
						cout << endl << "Nie ma w sklepie wystarczajacej liczby towarow";
						break;
					}
					else
					{

						string numer_transakcji = to_string((Tablica_klientow[numer_klienta_w_bazie].f_liczba_transakcji()) + 1);
						string s_numer_ID_klienta = to_string(numer_ID_klienta);
						Tablica_sprzetow[(indeks_produktu - 1)].ilosc = Tablica_sprzetow[(indeks_produktu - 1)].f_ilosc() - liczba_szt;
						string s_nazwa_sprzetu = Tablica_sprzetow[(indeks_produktu - 1)].f_nazwa_sprzetu();
						string s_rodzaj_sprzetu = Tablica_sprzetow[(indeks_produktu - 1)].f_rodzaj_sprzetu();
						string s_liczba_szt = to_string(liczba_szt);
						//dotyczy histori zakupow
						Tablica_klientow[numer_klienta_w_bazie].Tablica_zakupow[Tablica_klientow[numer_klienta_w_bazie].f_liczba_transakcji()] = "Numer transakcji: " + numer_transakcji + "--" + "Numer_ID_klienta: " + s_numer_ID_klienta + "--" + "nazwa_sprzetu: " + s_nazwa_sprzetu + "--" + "rodzaj_sprzetu: " + s_rodzaj_sprzetu + "--" + "ilosc: " + s_liczba_szt + "--";
						Tablica_klientow[numer_klienta_w_bazie].liczba_transakcji = Tablica_klientow[numer_klienta_w_bazie].f_liczba_transakcji() + 1;

						string s_zakupowy = "Zakupiono: ""nazwa_sprzetu: " + s_nazwa_sprzetu + "--" + "rodzaj_sprzetu: " + s_rodzaj_sprzetu + "--" + "ilosc: " + s_liczba_szt + "--";
						cout << endl << s_zakupowy << endl;
						
					}

				}



			}
			break;
		}
		default:
		{
			goto wprowadz_ponownie4;
			break;
		}

		}


		
		
	} while (1);




}

void Sklep_sportowy::Wypisz_historie_zakupow_klientow()
{
	if (liczba_osob_ktora_odwiedzila_sklep != 0)
	{
		for (int m = 0; m < liczba_osob_ktora_odwiedzila_sklep; m++)
		{
			int temp = Tablica_klientow[m].f_liczba_transakcji();
			if (temp > 0)
			{
				cout << endl << "            Klient NR: " << (m + 1) << endl;
			}
			for (int n = 0; n < temp; n++)
			{
				cout << endl << Tablica_klientow[m].Tablica_zakupow[n];
			}
		}
	}
	else
	{
		cout << endl << "NIKT NIE ODWIEDZIL NASZEGO SKLEPU!!!" << endl;
	}

}




void Sklep_sportowy:: Dodaj()
{
	Tablica_sprzetow[aktualne_wypelnienie].Wprowadz_dane();
	aktualne_wypelnienie++;
}

void Sklep_sportowy:: Modyfikuj()
{
	Wypisz();
	int modyfikowany_element;

	if(aktualne_wypelnienie!=0)
	{ 
	cout<<endl << "Wpisz numer indeksu sprzetu ktory chcesz modyfikowac: ";

	cin.clear(); //resetuje flagi strumienia wejœciowego. Jeœli wczytanie zakoñczy siê niepowodzeniem, strumieñ jest zablokowany
					//póki nie zresetuje siê flag.
	cin.sync(); //opró¿nia bufor strumienia z pozosta³oœci, ale nie potrafi dzia³aæ na zablokowanym strumieniu
	cin >> modyfikowany_element;
	if (modyfikowany_element <= aktualne_wypelnienie)
		Tablica_sprzetow[modyfikowany_element - 1].Modyfikuj();
	else
		cout << endl << "Nie ma sprzetu o takim indeksie" << endl;
	}
}


void Sklep_sportowy:: Wypisz()
{
	if (aktualne_wypelnienie == 0)
	{
		cout << endl << "Brak towarow" << endl;
	}

	for (int i = 0; i < aktualne_wypelnienie; i++)
	{
		cout << endl<< i+1 << ".  ";
			Tablica_sprzetow[i].Wyswietl();

	}


}

