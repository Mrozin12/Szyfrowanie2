//szyfrowanie za pomoc¹ szyfru s-des
//link do materia³ów, z których korzysta³em: https://www.dropbox.com/sh/z12alncq5xjvg4v/AAAljDjBRWRG-iF8knopbfeVa/2?dl=0

#include <iostream>
#include "klucz.h"
#include "szyfrowanie.h"

using namespace std;

int main()
{
	bool tekst[] = { 0,0,1,0,0,0,1,1 };
	bool klucz[] = { 1,1,1,0,0,1,1,1,0,1 };
	bool pom1[5] = { 0 };
	bool pom2[5] = { 0 };
	bool kl_1_rundy[8] = { 0 };
	bool kl_2_rundy[8] = { 0 };
	kluczyk gerwazy;
	szyfr enigma;
	cout << "klucz poczatkowy: ";
	for (int i = 0; i<10; i++)
		cout << klucz[i];
	cout << endl;

	//budujemy klucz

	gerwazy.permutacjaklucza10(klucz);
	gerwazy.kluczpierwszejrundy(klucz, pom1, pom2);
	gerwazy.permutacjap10w8(klucz, kl_1_rundy);
	cout << "klucz pierwszej rundy: ";
	for (int i = 0; i<8; i++)
		cout << kl_1_rundy[i];
	cout << endl;
	gerwazy.kluczdrugiejrundy(klucz, pom1, pom2);
	gerwazy.permutacjap10w8(klucz, kl_2_rundy);
	cout << "klucz drugiej rundy: ";
	for (int i = 0; i<8; i++)
		cout << kl_2_rundy[i];
	cout << endl;
	//szyfrujemy
	cout << "tekst: ";
	for (int i = 0; i<8; i++)
		cout << tekst[i];
	cout << endl;
	enigma.pwtekst(tekst);
	enigma.szyfrowanie(tekst, kl_1_rundy);
	enigma.szyfrowanie2(tekst, kl_2_rundy);
	enigma.permutacjaodw(tekst);
	cout << "tekst po zaszyfrowaniu: ";
	for (int i = 0; i<8; i++)
		cout << tekst[i];
	cout << "\n\n\n";
	//deszyfrujemy
	enigma.pwtekst(tekst);
	enigma.szyfrowanie(tekst, kl_2_rundy);
	enigma.szyfrowanie2(tekst, kl_1_rundy);
	enigma.permutacjaodw(tekst);
	cout << "po odszyfrowaniu: ";
	for (int i = 0; i<8; i++)
		cout << tekst[i];
	cout << "\n";
	system("pause");
	return 0;
}
