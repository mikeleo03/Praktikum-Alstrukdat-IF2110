// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 5 Oktober 2022
// Topik praktikum : ADT Mesin Kata
// Deskripsi : Aplikasi pencarian kata terpanjang

#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

char currentChar;
boolean EOP;

boolean EndWord;
Word currentWord;

int main () {
	int max_len = 0;
	int temp = 0;
	int i;

	STARTWORD();  // mulai baca
	while(!EndWord){
		temp = currentWord.Length;  // assign maks sama kata pertama
		if (temp > max_len)  {
			max_len = temp;   // Panjang maks
		}
		ADVWORD();
	}

	printf("%d\n", max_len);
	return 0;
}