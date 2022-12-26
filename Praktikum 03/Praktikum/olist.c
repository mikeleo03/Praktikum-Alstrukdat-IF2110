// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 18 September 2022
// Topik pra-praktikum : ADT List Statik dan Dinamik
// Deskripsi : Aplikasi ADT List Statik

#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

int main()
{
    // KAMUS LOKAL
    int bil, idx, maks, min;
    int i, count;
    ListStatik l1;

    // ALGORITMA
    CreateListStatik(&l1);
    readList(&l1);
    scanf("%d", &bil);
    count = 0;
    for (i = 0; i < listLength(l1); i++) {
        if (ELMT(l1, i) == bil)
            count += 1;
    }
    printList(l1);
    printf("\n");
    printf("%d\n", count);
    if (count != 0) {
        for (i = listLength(l1) - 1; i >= 0; i--) {
            if (ELMT(l1, i) == bil) {
                idx = i;
                break;
            }
        }
        printf("%d\n", idx);
        extremeValues(l1, &maks, &min);
        if (bil == maks) {
            printf("maksimum\n");
        }
        if (bil == min) {
            printf("minimum\n");
        }
        sortList(&l1, true);
        if (listLength(l1) % 2 != 0) {
            if (bil == ELMT(l1, (listLength(l1) / 2)))
                printf("median\n");
        }
        else {
            if (bil == ELMT(l1, (listLength(l1) / 2) - 1))
                printf("median\n");
        }
    }
    else {
        printf("%d tidak ada\n", bil);
    }

    return 0;
}