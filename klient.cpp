#include "klient.hpp"


Klient::Klient()
{
	ID = 0;
	Tablica_zakupow = NULL;
	liczba_transakcji = 0;
}

Klient:: ~Klient()
{
	delete [] Tablica_zakupow;
}

int Klient:: f_liczba_transakcji()
{
	return liczba_transakcji;
}