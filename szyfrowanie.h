#pragma once
#include "permutacje.h"
#include "sboxy.h"

class  szyfr :public permutacje
{
	sboxy ciach;
	void dzielenie(bool tekst[8], bool c_1[4], bool c_2[4], bool c_2_copy[4]);
	void permutacjap4w8(bool c_2[4], bool cool[8]);
	void dodawanie_symetryczne(bool cool[8], bool klucz[8], int n);
	void dzielenie(bool tekst[8], bool c_1[4], bool c_2[4]);
	void funkcjesbox(bool c_2[4], bool sbox[4], sboxy ciach);
	void dziesietny(bool tiptip[4], int &a);
	void permutacjap4(bool sbox[4]);
	void laczenie(bool tekst[8], bool c_1[4], bool c_2_copy[4]);
public:
	void pwtekst(bool tekst[8]);
	void szyfrowanie(bool tekst[8], bool klucz[8]);
	void szyfrowanie2(bool tekst[8], bool klucz[8]);
	void permutacjaodw(bool tekst[8]);
	void permutujmy(bool tekst[10], bool tekst2[10], int permutacje[10], int n);
};

//komentarz do celów badawczych