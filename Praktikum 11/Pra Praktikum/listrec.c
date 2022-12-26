// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 13 November 2022
// Topik pra-praktikum : ADT List Rekursif
// Deskripsi : Implementasi ADT List Rekursif

#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

/* Manajemen Memori */
Address newNode(ElType x)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */
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

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l)
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
{
    /* KAMUS */
    /* ALGORITMA */
    return (l == NULL);
}

boolean isOneElmt(List l)
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */
{
    /* KAMUS */
    /* ALGORITMA */
    return (!isEmpty(l) && tail(l) == NULL);
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l)
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
{
    /* KAMUS */
    /* ALGORITMA */
    return (INFO(l));
}

List tail(List l)
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
{
    /* KAMUS */
    /* ALGORITMA */
    return (NEXT(l));
}

List konso(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = newNode(e);
    if (p != NULL) {
        NEXT(p) = l;
        return p;
    } else {
        return l;
    }
}

List konsb(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l)) {
        return newNode(e);
    } else {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}

List copy(List l)
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (isEmpty(l)) {
        return NULL;
    } else {
        return (konso(copy(tail(l)), head(l)));
    }
}

List concat(List l1, List l2)
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (isEmpty(l1)) {
        return l2;
    } else {
        return (konso(concat(tail(l1), l2), head(l1)));
    }
}

/* Fungsi dan Prosedur Lain */
int length(List l)
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
{
    /* KAMUS */
    /* ALGORITMA */
    if (isEmpty(l)) {
        return 0;
    } else {
        return 1 + length(tail(l));
    }
}

boolean isMember(List l, ElType x)
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
{
    /* KAMUS */
    /* ALGORITMA */
    if (isEmpty(l)) {
        return false;
    } else if (head(l) == x) {
        return true;
    } else {
        return isMember(tail(l), x);
    }
}

void displayList(List l)
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
{
    /* KAMUS */
    /* ALGORITMA */
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}