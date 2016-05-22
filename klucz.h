#pragma once
#include"permutacje.h"
class kluczyk :public permutacje
{
public:
	void permutacjaklucza10(bool klucz[10]);
	void kluczpierwszejrundy(bool klucz[10], bool pom1[5], bool pom2[5]);
	void inline zamiana(bool klucz[5]);
	void permutacjap10w8(bool klucz[10], bool kl_sper[10])
	{
		for (int i = 0; i<8; i++)
			kl_sper[i] = klucz[p10w8[i]];
	}
	void kluczdrugiejrundy(bool klucz[10], bool pom1[5], bool pom2[5]);
};
