#include "szyfrowanie.h"
#include "klucz.h"
#include <iostream>
#include <cmath>

void szyfr::pwtekst(bool tekst[8])
{
	bool p[8];
	for (int i = 0; i<8; i++)
		p[i] = tekst[pw[i]];
	for (int i = 0; i<8; i++)
		tekst[i] = p[i];
}
void szyfr::dzielenie(bool tekst[8], bool c_1[4], bool c_2[4], bool c_2_copy[4])
{
	for (int i = 0; i<4; i++)
		c_1[i] = tekst[i];
	for (int i = 0; i<4; i++)
		c_2[i] = c_2_copy[i] = tekst[i + 4];
}

void szyfr::dzielenie(bool tekst[8], bool c_1[4], bool c_2[4])
{
	for (int i = 0; i<4; i++)
		c_1[i] = tekst[i];
	for (int i = 0; i<4; i++)
		c_2[i] = tekst[i + 4];
}

void inline szyfr::permutacjap4w8(bool c_2[4], bool cool[8])
{
	for (int i = 0; i<8; i++)
		cool[i] = c_2[p4w8[i]];
}

void inline szyfr::dodawanie_symetryczne(bool cool[8], bool klucz[8], int n)
{
	for (int i = 0; i<n; i++)
	{
		if (cool[i] == 1 && klucz[i] == 1)
			cool[i] = 0;
		else
			cool[i] += klucz[i];
	}

}
void szyfr::dziesietny(bool tiptip[4], int &a)
{
	for (int i = 0, j = 3; i<4; i++, j--) {
		a += tiptip[j] * pow(2, i);

	}

}
void szyfr::funkcjesbox(bool c_2[4], bool sbox[4], sboxy ciach)
{
	bool sbox1[2], sbox2[2];
	int a = 0;
	dziesietny(c_2, a);

	sbox1[0] = ciach.sbox1[a][0];
	sbox1[1] = ciach.sbox1[a][1];
	a = 0;
	dziesietny(sbox, a);

	sbox2[0] = ciach.sbox2[a][0];
	sbox2[1] = ciach.sbox2[a][1];
	sbox[0] = sbox1[0];
	sbox[1] = sbox1[1];
	sbox[2] = sbox2[0];
	sbox[3] = sbox2[1];

}
void szyfr::permutacjap4(bool sbox[4])
{
	bool tia[4];
	for (int i = 0; i<4; i++)
		tia[i] = sbox[p4[i]];
	for (int i = 0; i<4; i++)
		sbox[i] = tia[i];
}

void szyfr::laczenie(bool tekst[8], bool c_1[4], bool c_2_copy[4])
{
	for (int i = 0; i<4; i++)
		tekst[i] = c_1[i];
	for (int i = 0; i<4; i++)
		tekst[i + 4] = c_2_copy[i];
}

void szyfr::szyfrowanie(bool tekst[8], bool klucz[8])
{
	// bool cool[8];
	bool c_1[4] = { 0 }, c_2[4] = { 0 }, c_2_copy[4] = { 0 }, sbox[4] = { 0 };
	dzielenie(tekst, c_1, c_2, c_2_copy);
	//permutacjap4w8(c_2,tekst);
	permutujmy(c_2, tekst, p4w8, 8);
	dodawanie_symetryczne(tekst, klucz, 8);
	dzielenie(tekst, c_2, sbox);
	funkcjesbox(c_2, sbox, ciach);

	//permutacjap4(sbox);

	permutujmy(sbox, sbox, p4, 4);
	dodawanie_symetryczne(c_1, sbox, 4);
	laczenie(tekst, c_2_copy, c_1);
	std::cout << "tekst po zaszyfrowaniu kluczem 1 rundy: ";
	for (int i = 0; i<8; i++)
		std::cout << tekst[i];
	std::cout << "\n";
}

void szyfr::szyfrowanie2(bool tekst[8], bool klucz[8])
{
	bool cool[8];
	bool c_1[4] = { 0 }, c_2[4] = { 0 }, c_2_copy[4] = { 0 }, sbox[4] = { 0 };
	dzielenie(tekst, c_1, c_2, c_2_copy);

	//permutacjap4w8(c_2,tekst);

	permutujmy(c_2, tekst, p4w8, 8);
	dodawanie_symetryczne(tekst, klucz, 8);
	dzielenie(tekst, c_2, sbox);
	funkcjesbox(c_2, sbox, ciach);
	//permutacjap4(sbox);
	permutujmy(sbox, sbox, p4, 4);
	dodawanie_symetryczne(c_1, sbox, 4);
	laczenie(tekst, c_1, c_2_copy);
	std::cout << "tekst po zaszyfrowaniu kluczem 2 rundy: ";
	for (int i = 0; i<8; i++)
		std::cout << tekst[i];
	std::cout << "\n";
}

void szyfr::permutacjaodw(bool tekst[8])
{
	bool cos[8];
	for (int i = 0; i<8; i++)
		cos[i] = tekst[po[i]];
	for (int i = 0; i<8; i++)
		tekst[i] = cos[i];
}


void szyfr::permutujmy(bool tekst[10], bool tekst2[10], int permutacje[10], int n)
{

	bool p[10];
	for (int i = 0; i<n; i++)
		p[i] = tekst[permutacje[i]];
	for (int i = 0; i<n; i++)
		tekst2[i] = p[i];
}