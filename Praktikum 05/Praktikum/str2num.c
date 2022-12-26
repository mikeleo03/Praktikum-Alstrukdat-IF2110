// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 5 Oktober 2022
// Topik praktikum : ADT Mesin Kata
// Deskripsi : Aplikasi konversi string to number

#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"

boolean isAda (char *word, Word kata) {
	int panjang = 0;
    while (word[panjang] != '\0') {
        panjang++;
    }
    if (panjang != kata.Length) {
        return false;
    }
    else {
        int i = 0;
        for (i; i < panjang; i++) {
            if (word[i] != kata.TabWord[i]) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    char nol[] = "nol";
    char satu[] = "satu";
    char dua[] = "dua";
    char tiga[] = "tiga";
    char empat[] = "empat";
    char lima[] = "lima";
    char enam[] = "enam";
    char tujuh[] = "tujuh";
    char delapan[] = "delapan";
    char sembilan[] = "sembilan";
    char sepuluh[] = "sepuluh";
    char sebelas[] = "sebelas";
	char seratus[] = "seratus";
    char belas[] = "belas";
    char puluh[] = "puluh";
    char ratus[] = "ratus";
    
    // Mulai baca
    STARTWORD();

    int nilai = 0;
    boolean isCurrentAngka = false;

    while (!endWord) {
        IgnoreBlanks(); // Abaikan blank
        if (isAda(sepuluh, currentWord)) {
            nilai += 10;
            isCurrentAngka = true;
        }
        else if (isAda(sebelas, currentWord)) {
            nilai += 11;
            isCurrentAngka = true;
        }
        else if (isAda(belas, currentWord)) {
            nilai += 10;
            isCurrentAngka = true;
        }
        else if (isAda(puluh, currentWord)) {
            nilai = nilai - (nilai % 100) + (nilai % 100) * 10;
            isCurrentAngka = true;
        }
        else if (isAda(ratus, currentWord)) {
            nilai *= 100;
            isCurrentAngka = true;
        }
        else if (isAda(seratus, currentWord)) {
            nilai += 100;
            isCurrentAngka = true;
        }
        else if (isAda(nol, currentWord)) {
            isCurrentAngka = true;
        }
        else if (isAda(satu, currentWord)) {
            nilai += 1;
            isCurrentAngka = true;
        }
        else if (isAda(dua, currentWord)) {
            nilai += 2;
            isCurrentAngka = true;
        }
        else if (isAda(tiga, currentWord)) {
            nilai += 3;
            isCurrentAngka = true;
        }
        else if (isAda(empat, currentWord)) {
            nilai += 4;
            isCurrentAngka = true;
        }
        else if (isAda(lima, currentWord)) {
            nilai += 5;
            isCurrentAngka = true;
        }
        else if (isAda(enam, currentWord)) {
            nilai += 6;
            isCurrentAngka = true;
        }
        else if (isAda(tujuh, currentWord)) {
            nilai += 7;
            isCurrentAngka = true;
        }
        else if (isAda(delapan, currentWord)) {
            nilai += 8;
            isCurrentAngka = true;
        }
        else if (isAda(sembilan, currentWord)) {
            nilai += 9;
            isCurrentAngka = true;
        }
        else {
            if (isCurrentAngka) {
                printf("%d ", nilai);
                nilai = 0;
                isCurrentAngka = false;
            }

            int i = 0;
            for (i; i < currentWord.Length; i++) {
                printf("%c", currentWord.TabWord[i]);
            }
        }

        ADVWORD();  // ganti kata

        if (!isCurrentAngka && !endWord) {
            printf(" ");
        }
    }

    if (isCurrentAngka) {
        printf("%d", nilai);
    }

    printf("\n");
    return 0;
}