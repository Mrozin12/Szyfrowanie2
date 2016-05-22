#include "klucz.h"
#include"permutacje.h"
#include <iostream>
using namespace std;

void kluczyk::permutacjaklucza10(bool klucz[10])
{
	bool p[10];
	for (int i = 0; i<10; i++)
		p[i] = klucz[p10[i]];
	for (int i = 0; i<10; i++)
		klucz[i] = p[i];
}

void kluczyk::kluczpierwszejrundy(bool klucz[10], bool pom1[5], bool pom2[5])
{
	for (int i = 0; i<5; i++)
		pom1[i] = klucz[i];
	for (int i = 0; i<5; i++)
		pom2[i] = klucz[i + 5];
	zamiana(pom1);
	zamiana(pom2);
	for (int i = 0; i<5; i++)
		klucz[i] = pom1[i];
	for (int i = 0; i<5; i++)
		klucz[i + 5] = pom2[i];
}

void inline kluczyk::zamiana(bool klucz[5])
{
	bool p = klucz[0];
	for (int i = 1; i<5; i++) { klucz[i - 1] = klucz[i]; }
	klucz[4] = p;
}

void kluczyk::kluczdrugiejrundy(bool klucz[10], bool pom1[5], bool pom2[5])
{
	for (int i = 0; i<2; i++)
	{
		zamiana(pom1);
		zamiana(pom2);
	}
	for (int i = 0; i<5; i++)
		klucz[i] = pom1[i];
	for (int i = 0; i<5; i++)
		klucz[i + 5] = pom2[i];
}