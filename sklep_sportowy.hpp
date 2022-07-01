#pragma once
#ifndef sklep_sportowy_hpp
#define sklep_sportowy_hpp

#include "sprzet.hpp"
#include "klient.hpp"

#include<iostream>
#include <string>
using namespace std;

class Sprzet;
class Klient;

class Sklep_sportowy
{ 
friend class Klient;
public:
	long int ID_kierownika_sklepu;
private:
	Sprzet *Tablica_sprzetow;
	int dlugosc;
	int aktualne_wypelnienie;

public:
	Klient* Tablica_klientow;
private:
	int max_klientow;
public:
	int liczba_osob_ktora_odwiedzila_sklep;


	Sklep_sportowy(int d=50, int k= 100);
	~Sklep_sportowy();

	void Dodaj();
	void Modyfikuj();
	void Wypisz_historie_zakupow_klientow();
private:
	void Wypisz();


public:
	void Dodaj_klienta();
	void Dokonaj_zakupu(int numer_klienta_w_bazie, int numer_ID_klienta);

};

#endif