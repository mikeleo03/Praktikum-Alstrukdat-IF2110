// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 30 Oktober 2022
// Topik pra-praktikum : ADT Variasi Linked List - List Sirkuler
// Deskripsi : Implementasi ADT List Sirkuler

#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (FIRST(l) == NULL);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    FIRST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val)
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    p = (Address) malloc(sizeof(ElmtList));

    if (p != NULL) {  // Alokasi berhasil
        INFO(p) = val;
        NEXT(p) = NULL;
    }

    return p;
}

void deallocate(Address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val)
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
{
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    p = FIRST(l);

    if (!isEmpty(l)) {
        while ((NEXT(p) != FIRST(l)) && (INFO(p) != val)) {  // Kondisi list sirkuler dan blm ketemu
            p = NEXT(p);
        }

        if (INFO(p) != val) {  // Kalo gaada kirim NULL
            p = NULL;
        }
    }

    return p;
}

boolean addrSearch(List l, Address p)
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    /* KAMUS LOKAL */
    Address ptr;

    /* ALGORITMA */
    ptr = FIRST(l);

    if (!isEmpty(l)) {
        while ((NEXT(ptr) != FIRST(l)) && (ptr != p)) {
            ptr = NEXT(ptr);
        }
    }

    return (!isEmpty(l) && (ptr == p)); // Apakah ketemu dan list belum kosong?
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
/* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */
{
    /* KAMUS LOKAL */
    Address p, last;

    /* ALGORITMA */
    p = allocate(val); // Alokasi awal

    if (p != NULL) {
        if (isEmpty(*l)) { // Kalo kosong, tinggal tambahin di next nya
            NEXT(p) = p; 
        } else {
            last = FIRST(*l);  // Add from last
            while (NEXT(last) != FIRST(*l)) {
                last = NEXT(last);
            }
            NEXT(p) = FIRST(*l);
            NEXT(last) = p;
        }
        FIRST(*l) = p;
    }
}

void insertLast(List *l, ElType val)
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */
{
    /* KAMUS LOKAL */
    Address p, last;

    /* ALGORITMA */
    if (isEmpty(*l)) { // Kalo kosong, tinggal tambahin di next nya
        insertFirst(l,val);
    } else {
        p = allocate(val);
        if (p != NULL) {
            last = FIRST(*l);  // Add from last
            while (NEXT(last) != FIRST(*l)) {
                last = NEXT(last);
            }
            NEXT(last) = p;
            NEXT(p) = FIRST(*l);
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama List l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Jika list baru tidak kosong, Last element menunjuk ke First element baru */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen pertama list lama di-dealokasi */
{
    /* KAMUS LOKAL */
    Address p, last;

    /* ALGORITMA */
    p = FIRST(*l);
    *val = INFO(p);

    if (NEXT(FIRST(*l)) == FIRST(*l)) {  // Elemennya cuma 1, set aja jadi NULL
        FIRST(*l) = NULL;
    } else {
        last = FIRST(*l);
        while (NEXT(last) != FIRST(*l)) {
            last = NEXT(last);
        }
        FIRST(*l) = NEXT(FIRST(*l));
        NEXT(last) = FIRST(*l);
    }

    deallocate(p);
}

void deleteLast(List *l, ElType *val)
/* I.S. List l tidak kosong */
/* F.S. val adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen terakhir yg lama, jika ada */
/*      Jika list baru tidak kosong, Last element baru menunjuk ke First element */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen terakhir list lama di-dealokasi */
{
    /* KAMUS LOKAL */
    Address preclast, last;

    /* ALGORITMA */
    last = FIRST(*l);
    preclast = NULL;

    while (NEXT(last) != FIRST(*l)) {  // Biar sampe ke belakang
        preclast = last;
        last = NEXT(last);
    }

    if (preclast == NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(preclast) = FIRST(*l);  // Last nya ga dipake, preclast -> first
    }

    *val = INFO(last);

    deallocate(last);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    if (isEmpty(l)) {
        printf("[]");
    } else {
        printf("[");
        p = FIRST(l);
        do {
            if (NEXT(p) == FIRST(l)) {
                printf("%d", INFO(p));
            } else {
                printf("%d,", INFO(p));
            }
            p = NEXT(p);
        } while (p != FIRST(l));
        printf("]");
    }
}