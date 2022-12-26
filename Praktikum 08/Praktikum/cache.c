// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 28 Oktober 2022
// Topik praktikum : ADT Linked List
// Deskripsi : Aplikasi ADT Linked List pada cache

#include "listlinier.h"
#include <stdio.h>

int main() {
    /* KAMUS LOKAL */
    int N, Q, count, i, counthit;
    List l, l2;
    ElType val, x;
    int jumlah;

    /* ALGORITMA */
    // Membuat list baru
    CreateList(&l);

    // Inisiasi elemen list dari [1,N]
    scanf("%d",&N);

    // Meminta banyaknya perintah
    scanf("%d",&Q);
    count = 0;
    counthit = 0;
    jumlah = 0;
    while (count < Q) {
        scanf("%d",&x);
        if (N > 0) {
            if (isEmpty(l)) {
                insertFirst(&l,x);
                printf("miss ");
                displayList(l);
                jumlah++;
                printf("\n");
            } else {
                if (indexOf(l,x) != IDX_UNDEF) {
                    deleteAt(&l,indexOf(l,x),&val);
                    insertFirst(&l,val);
                    printf("hit ");
                    displayList(l);
                    printf("\n");
                    counthit++;
                } else if (indexOf(l,x) == IDX_UNDEF && jumlah < N) {
                    insertFirst(&l,x);
                    printf("miss ");
                    displayList(l);
                    jumlah++;
                    printf("\n");
                } else {
                    deleteLast(&l,&val);
                    insertFirst(&l,x);
                    printf("miss ");
                    displayList(l);
                    printf("\n");
                }
            }
        } else {
            printf("miss ");
            displayList(l);
            printf("\n");
        }
        count++;
    }

    /* Mengeluarkan hitratio */
    if (Q == 0 || N == 0) {
        printf("hit ratio: %.2f\n",0.00);
    } else {
        printf("hit ratio: %.2f\n",(float) counthit / (float) count);
    }
    return 0;
}