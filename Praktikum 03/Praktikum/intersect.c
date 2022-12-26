// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 18 September 2022
// Topik pra-praktikum : ADT List Statik dan Dinamik
// Deskripsi : Aplikasi ADT List Statik

#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

int main () {
    ListStatik l1 , l2 , l3;
    CreateListStatik(&l1);
    CreateListStatik(&l2);
    CreateListStatik(&l3);
    readList(&l1);
    readList(&l2);
    int i, j;
    int k;
    k = listLength(l1);
    for (i = 0; i < k; i++){
        for (j = 0; j < k; j++){
            if (ELMT(l1, i) == ELMT(l2, j)) {
                insertLast(&l3, ELMT(l1, i));
            }
        }   
    }
    sortList(&l3, true);
    printf("%d\n", listLength(l3));
    printList(l3);
    printf("\n");
    return 0;
}