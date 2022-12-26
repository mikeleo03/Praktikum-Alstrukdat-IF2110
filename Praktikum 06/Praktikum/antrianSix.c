// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 13 Oktober 2022
// Topik praktikum : ADT Queue
// Deskripsi : Aplikasi ADT Queue pada antrian Six

#include <stdio.h>
#include "queue.h"

int main() {
    // KAMUS LOKAL
    int count, maks, min, sum;
    ElType menu, panjang;
    Queue Q;

    // ALGORITMA
    CreateQueue(&Q);
    count = 0;
    maks = -99999;
    min = 99999;
    sum = 0;

    do {
        scanf("%d",&menu);

        // Kondisional
        if (menu == 1) {
            scanf("%d",&panjang);
            if (isFull(Q)) {
                printf("Queue penuh\n");
            }
            else {
                enqueue(&Q,panjang);
            }
        }
        else if (menu == 2) {
            if (isEmpty(Q)) {
                printf("Queue kosong\n");
            }
            else {
                dequeue(&Q,&panjang);
                count += 1;
                sum += panjang;
                if (panjang >= maks) {
                    maks = panjang;
                }
                if (panjang <= min) {
                    min = panjang;
                }
            }
        }
    } while (menu != 0);

    // Keluar dari loop, artinya inputnya 0
    printf("%d\n",count);

    if (count == 0) {
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
    }
    else {
        printf("%d\n",min);
        printf("%d\n",maks);
        printf("%.2f\n",((float)sum / (float)count));
    }
    return 0;
}