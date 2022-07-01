#pragma once
#ifndef klient_hpp
#define klient_hpp

#include "sprzet.hpp"
#include "sklep_sportowy.hpp"
#include <string>
using namespace std;

class Sprzet;
class Sklep_sportowy;

class Klient
{
friend class Sklep_sportowy;
public:
	int ID;
private:
	string* Tablica_zakupow;
	int liczba_transakcji;
	int f_liczba_transakcji();
public:
	Klient();
	~Klient();
	
};





#endif
