// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 18 September 2022
// Topik pra-praktikum : ADT List Statik dan Dinamik
// Deskripsi : Aplikasi ADT List Dinamik

#include <stdio.h>
#include "listdin.h"
#include "boolean.h"

int main()
{
    // KAMUS LOKAL
    ListDin l1, l2, l3;
    int i, j, ctr = 0;
    // ALGORITMA
    CreateListDin(&l1, 200);
    CreateListDin(&l2, 200);
    CreateListDin(&l3, 400);
    readList(&l1);
    NEFF(l3) = NEFF(l1);
    readList(&l2);
    
    for (i = 0; i < listLength(l1); i++) {
        ELMT(l3, i) = ELMT(l1, i);
    }

    for (i = 0; i < listLength(l2); i++) {
        if (indexOf(l3, ELMT(l2, i)) == IDX_UNDEF){
            insertLast(&l3, ELMT(l2, i));
        } else  {
            ctr += 1;
        }
    }
    NEFF(l3) = NEFF(l1) + NEFF(l2) - ctr;
    sort(&l3, true);
    printf("%d", listLength(l3));
    printf("\n");
    printList(l3);
    printf("\n");
    return 0;
}