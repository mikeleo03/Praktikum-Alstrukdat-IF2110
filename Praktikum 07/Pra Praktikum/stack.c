// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 18 Oktober 2022
// Topik pra-praktikum : ADT Stack
// Deskripsi : Implementasi ADT Stack

#include "stack.h"
#include <stdio.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    // KAMUS LOKAL
    // ALGORITMA
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    // KAMUS LOKAL
    // ALGORITMA
    return Top(S) == Nil;
}

boolean IsFull(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    // KAMUS LOKAL
    // ALGORITMA
    return Top(S) == MaxEl - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    // KAMUS LOKAL
    // ALGORITMA
    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, infotype *X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    // KAMUS LOKAL
    // ALGORITMA
    *X = InfoTop(*S);
    Top(*S)--;
}

// Q->T = (PrioQueueTime*) malloc ((Max+1) * sizeof(PrioQueueTime)); pake *Q alokasi Max
// free(Q->T); dealokasi *Q