#ifndef sprzet_hpp
#define sprzet_hpp

#include "sklep_sportowy.hpp"
#include "klient.hpp"

#include<iostream>
#include <string>

using namespace std;

class Sklep_sportowy;
class Klient;

class Sprzet
{
  friend class Sklep_sportowy;
  private:
	string rodzaj_sprzetu;
	float cena;
	string nazwa;
	int ilosc;
public:
	Sprzet();
	Sprzet(string rodzaj_sprzetu, float cena, string nazwa, int ilosc);
	~Sprzet();
private:
	void Wprowadz_dane();
	void Modyfikuj();
	void Wyswietl();

	string f_nazwa_sprzetu();
	string f_rodzaj_sprzetu();
	int f_ilosc();
	int f_cena();
	



};



#endif