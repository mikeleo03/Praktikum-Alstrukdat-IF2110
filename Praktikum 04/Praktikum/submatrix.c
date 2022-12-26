// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 23 September 2022
// Topik praktikum : ADT Array
// Deskripsi : Implementasi pada submtarix

#include <stdio.h>
#include "matrix.h"

// ELKSEKUSI
int jumlahnolSubMatrix(Matrix A, int M, IdxType idxRow, IdxType idxCol) {
    /* KAMUS */
    int jumlah;
    IdxType i, j;

    /* ALGORITMA */
    jumlah = 0;
    for (i = idxRow; i < idxRow + (IdxType) M; i++) {
        for (j = idxCol; j < idxCol + (IdxType) M; j++) {
            if (ELMT(A, i, j) != 0) {
                jumlah += 1;
            }
        }
    }
    return jumlah;
}

int main() {
    /* KAMUS */
    int N, M, posisi;
    Matrix sel;
    IdxType i, j;
    ElType max;

    /* ALGORITMA */
    scanf("%d %d", &N, &M);
    readMatrix(&sel, N, N);

    // Assign dengan maksimum pertama
    max = jumlahnolSubMatrix(sel, M, 0, 0);
    posisi = 1;

    // Nyari
    for (i = 0; i < (IdxType) N + M - 1; i++) {
        for (j = 0; j < (IdxType) N + M - 1; j++) {
            if (jumlahnolSubMatrix(sel, M, i, j) > max) {
                max = jumlahnolSubMatrix(sel, M, i, j);
                posisi = (N-M+1)*i+j+1;
            }
            else if (jumlahnolSubMatrix(sel, M, i, j) == max) {
                max = max;
                posisi = posisi;
            }
        }
    }


    // Keluar dari loops
    printf("%d\n", posisi);
    return 0;
}