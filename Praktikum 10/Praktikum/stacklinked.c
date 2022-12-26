// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 7 November 2022
// Topik pra-praktikum : ADT Variasi Linked List - Stack Linked List
// Deskripsi : Implementasi ADT Stack Linked List

#include "stacklinked.h"
#include <stdio.h>
#include <stdlib.h>

/* Prototype manajemen memori */
Address newNode(ElType x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */ 
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {  /* Berhasil teralokasi */
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
} 

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s)
/* Mengirim true jika Stack kosong: TOP(s) = NIL */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (ADDR_TOP(s) == NIL);
}

int length(Stack s)
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */
{
    /* KAMUS LOKAL */
    Address p;
    int N;

    /* ALGORITMA */
    N = 0;

    if (!isEmpty(s)) {
        p = ADDR_TOP(s);
        do {
            N++;
            p = NEXT(p);
        } while (p != NIL);
    }

    return N;
}

void CreateStack(Stack *s)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    ADDR_TOP(*s) = NULL;
}

void DisplayStack(Stack s)
/* Proses : Menuliskan isi Stack, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Stack kosong : menulis [] */
{
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    printf("[");
    p = ADDR_TOP(s);
    while (p != NIL) {
        if (NEXT(p) == NIL) {
            printf("%d", INFO(p));
        } else {
            printf("%d,", INFO(p));
        }
        p = NEXT(p);
    }
    printf("]");
}

void push(Stack *s, ElType x)
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */
{
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    p = newNode(x);
    if (p != NULL) {
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void pop(Stack *s, ElType *x)
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
{
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    *x = TOP(*s);
    p = ADDR_TOP(*s);
    ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
    NEXT(p) = NIL;
    free(p);
}