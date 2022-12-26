// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 25 September 2022
// Topik pra-praktikum : ADT Mesin Kata
// Deskripsi : Implementasi ADT Mesin Kata

#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    // KAMUS LOKAL
    // ALGORITMA
    while (currentChar == BLANK && currentChar != MARK) {
        ADV();
    }
    // curentchar != MARK
}

void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    // KAMUS LOKAL
    // ALGORITMA
    START();
    IgnoreBlanks();

    if (currentChar == MARK) {
        endWord = true;
    }
    else { // artinya curentchar != MARK
        endWord = false;
        CopyWord();
    }
}

void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
    // KAMUS LOKAL
    // ALGORITMA
    IgnoreBlanks();

    if (currentChar == MARK) {
        endWord = true;
    }
    else { // artinya curentchar != MARK
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    // KAMUS LOKAL
    int i = 0; // Inisialisasi

    // ALGORITMA
    while ((currentChar != MARK) && (currentChar != BLANK)) {
        if (i < NMax) {
            currentWord.TabWord[i] = currentChar;
        }
        ADV();
        i += 1; // increment
    }

    // Handling kalo jumlah elemen yang masuk melebihi NMax jadi harus dipotong
    if (i < NMax) {
        currentWord.Length = i;
    }
    else { // Handling kasus ini
        currentWord.Length = NMax;
    }
}

void LowerCase()
/* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
/* F.S. currentword menjadi lowercase di setiap karakternya */
{
    int i;
    for (i = 0; i < currentWord.Length; i++){
        if (currentWord.TabWord[i] <= 90 && currentWord.TabWord[i] >= 65){
        currentWord.TabWord[i] = currentWord.TabWord[i] + 32;  
        }
    } 
}