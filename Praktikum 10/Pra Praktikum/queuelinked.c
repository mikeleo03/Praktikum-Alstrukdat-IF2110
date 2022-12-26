// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 7 November 2022
// Topik pra-praktikum : ADT Variasi Linked List - Queue Linked List
// Deskripsi : Implementasi ADT Queue Linked List

#include "queuelinked.h"
#include <stdio.h>
#include <stdlib.h>

/* Prototype manajemen memori */
Address newNode(ElType x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Address p = (Address) malloc(sizeof(Node));
    if (p != NIL) {  /* Berhasil teralokasi */
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}

boolean isEmpty(Queue q)
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NIL and ADDR_TAIL(q)=NIL */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return ((ADDR_HEAD(q) == NIL) && (ADDR_TAIL(q) == NIL));
}

int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
{
    /* KAMUS LOKAL */
    Address p;
    int N;

    /* ALGORITMA */
    N = 0;

    if (!isEmpty(q)) {
        p = ADDR_HEAD(q);
        do {
            N++;
            p = NEXT(p);
        } while (p != NIL);
    }

    return N;
}

/*** Kreator ***/
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}

void DisplayQueue(Queue q)
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    printf("[");
    p = ADDR_HEAD(q);
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

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x)
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
{
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    p = newNode(x);
    if (p != NIL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = p;
        } else {
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}

void dequeue(Queue *q, ElType *x)
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    *x = HEAD(*q);
    p = ADDR_HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    if (ADDR_HEAD(*q) == NIL) {
        ADDR_TAIL(*q) = NIL;
    }
    NEXT(p) = NIL;
    free(p);
}