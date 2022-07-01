#include "sprzet.hpp"

Sprzet:: Sprzet()
{
	rodzaj_sprzetu = "NIC";
	cena = 0;
	nazwa = "NIC";
	ilosc = 0;
	
}

Sprzet::Sprzet(string rodzaj_sprzetu, float cena, string nazwa, int ilosc)
{

	this->rodzaj_sprzetu = rodzaj_sprzetu;
	this->cena = cena;
	this->ilosc = ilosc;
	this->nazwa = nazwa;

}




Sprzet:: ~Sprzet()
{
}


void Sprzet:: Wyswietl()
{
	cout << rodzaj_sprzetu << "--" << nazwa << "--"<<"ilosc: "<< ilosc << "--"<<"cena: " << cena ;


}

void Sprzet:: Wprowadz_dane()

{
	

	cout << endl << "Podaj rodzaj sprzetu: ";
	
	cin.clear();
	cin.ignore(1000, '\n');
	getline(cin, rodzaj_sprzetu);
	cout << rodzaj_sprzetu;
	

	cout << endl << "Podaj nazwe sprzetu: ";
	
	getline(cin, nazwa);
	cout << nazwa;

	cout << endl << "Podaj cene sprzetu: ";
	cin.clear(); //resetuje flagi strumienia wej�ciowego. Je�li wczytanie zako�czy si� niepowodzeniem, strumie� jest zablokowany
					//p�ki nie zresetuje si� flag.
	cin.sync(); //opr�nia bufor strumienia z pozosta�o�ci, ale nie potrafi dzia�a� na zablokowanym strumieniu
	cin >> cena;

	cout << endl << "Podaj ilosc sprzetu: ";
	cin.clear(); //resetuje flagi strumienia wej�ciowego. Je�li wczytanie zako�czy si� niepowodzeniem, strumie� jest zablokowany
					//p�ki nie zresetuje si� flag.
	cin.sync(); //opr�nia bufor strumienia z pozosta�o�ci, ale nie potrafi dzia�a� na zablokowanym strumieniu
	cin >> ilosc;

}





void Sprzet::Modyfikuj()
{
	do
	{
		char wybor;

		cout << "Zmien cene --   c" << endl;
		cout << "Zmien rodzaj sprzetu --   r" << endl;
		cout << "Zmien ilosc --   i" << endl;
		cout << "Zmien nazwe --   n" << endl;
		cout << "Zakoncz  --   z" << endl;

	wprowadz_ponownie:
		cin.clear(); //resetuje flagi strumienia wej�ciowego. Je�li wczytanie zako�czy si� niepowodzeniem, strumie� jest zablokowany
					//p�ki nie zresetuje si� flag.
		cin.sync(); //opr�nia bufor strumienia z pozosta�o�ci, ale nie potrafi dzia�a� na zablokowanym strumieniu
		cin >> wybor;

		if (wybor == 'z')
		{
			break;
		}
		switch (wybor)
		{
		case 'c':
		{
			cout << "Podaj nowa cene: ";
			cin.clear(); //resetuje flagi strumienia wej�ciowego. Je�li wczytanie zako�czy si� niepowodzeniem, strumie� jest zablokowany
					//p�ki nie zresetuje si� flag.
			cin.sync(); //opr�nia bufor strumienia z pozosta�o�ci, ale nie potrafi dzia�a� na zablokowanym strumieniu
			cin >> cena;
			break;
		}


		case 'r':
		{
			cout << "Podaj rodzaj sprzetu : ";
			cin.clear(); //resetuje flagi strumienia wej�ciowego. Je�li wczytanie zako�czy si� niepowodzeniem, strumie� jest zablokowany
					//p�ki nie zresetuje si� flag.
			cin.ignore(1000, '\n');
			getline(cin, rodzaj_sprzetu);
			break;
		}
		case 'i':
		{
			cout << "Podaj ilosc sprzetu: ";
			cin.clear(); //resetuje flagi strumienia wej�ciowego. Je�li wczytanie zako�czy si� niepowodzeniem, strumie� jest zablokowany
					//p�ki nie zresetuje si� flag.
			cin.sync(); //opr�nia bufor strumienia z pozosta�o�ci, ale nie potrafi dzia�a� na zablokowanym strumieniu
			cin >> ilosc;
			break;
		}

		case 'n':
		{
			cout << "Podaj nazwe sprzetu : ";
			cin.clear(); //resetuje flagi strumienia wej�ciowego. Je�li wczytanie zako�czy si� niepowodzeniem, strumie� jest zablokowany
					//p�ki nie zresetuje si� flag.
			cin.ignore(1000, '\n');
			getline(cin, nazwa);
			break;
		}
		default:
		{
			goto wprowadz_ponownie;
			break;
		}

		}
	} while (1);

}



string Sprzet::f_nazwa_sprzetu() {

	return nazwa;

}




string Sprzet:: f_rodzaj_sprzetu()
{

	return rodzaj_sprzetu;

}



int Sprzet::f_ilosc()
{
	return ilosc;

}

int Sprzet::f_cena()
{

	return cena;

}