// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 23 September 2022
// Topik Praktikum : ADT Array
// Deskripsi : Penambahan ADT Array untuk operasi per baris

#include <stdio.h>
#include "matrix.h"

/* Operasi berbasis baris dan per kolom */

float AvgRow(Matrix M, IdxType i) {
    /* Menghasilkan rata-rata dari elemen pada baris ke-i */
    /* Prekondisi: i adalah indeks baris efektif dari M */
    // KAMUS
    float sum = 0;
    IdxType j;

    // ALGORITMA
    for (j = 0; j < COL_EFF(M); j += 1) {
        sum += (float) ELMT(M,i,j);
    }

    return sum / ((float) COL_EFF(M));
}

float AvgCol(Matrix M, IdxType j) {
    /* Menghasilkan rata-rata dari elemen pada kolom ke-j */
    /* Prekondisi: j adalah indeks kolom efektif dari M */
    // KAMUS
    float sum = 0;
    IdxType i;

    // ALGORITMA
    for (i = 0; i < ROW_EFF(M); i += 1) {
        sum += (float) ELMT(M,i,j);
    }

    return sum / ((float) ROW_EFF(M));
}

void MinMaxRow(Matrix M, IdxType i, ElType *max, ElType *min) {
    /* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
    /* F.S. max berisi elemen maksimum pada baris i dari M
    min berisi elemen minimum pada baris i dari M */
    // KAMUS
    IdxType j;
    *max = ELMT(M,i,0);
    *min = ELMT(M,i,0);

    // ALGORITMA
    for (j = 1; j < COL_EFF(M); j += 1) {
        if (ELMT(M,i,j) > *max) {
            *max = ELMT(M,i,j);
        }
        if (ELMT(M,i,j) < *min) {
            *min = ELMT(M,i,j);
        }
    }
}

void MinMaxCol(Matrix M, IdxType j, ElType *max, ElType *min) {
    /* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
    /* F.S. max berisi elemen maksimum pada kolom j dari M
    min berisi elemen minimum pada kolom j dari M */
    // KAMUS
    IdxType i;
    *max = ELMT(M,0,j);
    *min = ELMT(M,0,j);

    // ALGORITMA
    for (i = 1; i < ROW_EFF(M); i += 1) {
        if (ELMT(M,i,j) > *max) {
            *max = ELMT(M,i,j);
        }
        if (ELMT(M,i,j) < *min) {
            *min = ELMT(M,i,j);
        }
    }
}

int CountNumRow(Matrix M, IdxType i, ElType X) {
    /* Menghasilkan banyaknya kemunculan X pada baris i dari M */
    // KAMUS
    IdxType j;
    int count = 0;

    // ALGORITMA
    for (j = 0; j < COL_EFF(M); j+= 1) {
        if (ELMT(M,i,j) == X) {
            count += 1;
        }
    }
    return count;
}

int CountNumCol(Matrix M, IdxType j, ElType X) {
    /* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
    // KAMUS
    IdxType i;
    int count = 0;

    // ALGORITMA
    for (i = 0; i < ROW_EFF(M); i+= 1) {
        if (ELMT(M,i,j) == X) {
            count += 1;
        }
    }
    return count;
}

void RotateMat(Matrix *m) {
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-rotasi" searah jarum jam
   untuk semua "lapisan" elemen mulai dari yang terluar
   Contoh matrix 3x3 sebelum dirotasi:
   1 2 3
   4 5 6
   7 8 9

   Contoh matrix 3x3 setelah dirotasi:
   4 1 2
   7 5 3
   8 9 6

   Contoh matrix 4x4 sebelum dirotasi:
   1 2 3 4
   5 6 7 8
   9 10 11 12
   13 14 15 16

   Contoh matrix 4x4 setelah dirotasi:
   5 1 2 3
   9 10 6 4
   13 11 7 8
   14 15 16 12
*/
    // KAMUS
    IdxType i,j;
    int count;
    int baris, kolom;
    Matrix mathasil;

    // ALGORITMA
    baris = ROW_EFF(*m);
    kolom = COL_EFF(*m);
    // Assign elemen efektif dari mathasil
    ROW_EFF(mathasil) = baris;
    COL_EFF(mathasil) = kolom;
    // Looping muter ringwise rotation
    for (i = 0; i < baris; i += 1) {
        for (j = 0; j < kolom; j += 1) {
            count = 0;
            while (count <= ROW_EFF(*m)/2) {
                if (i == count && j >= count+1 && j < kolom-count) {
                    ELMT(mathasil,i,j) = ELMT(*m,i,j-1);
                }
                else if (i >= count+1 && i < baris-count && j == kolom-1-count) {
                    ELMT(mathasil,i,j) = ELMT(*m,i-1,j);
                }
                else if (i == baris-1-count && j >= count && j < kolom-1-count) {
                    ELMT(mathasil,i,j) = ELMT(*m,i,j+1);
                }
                else if (i >= count && i < baris-1-count && j == count) {
                    ELMT(mathasil,i,j) = ELMT(*m,i+1,j);
                }
                count += 1;
            }
            // Handling kalo elemennya ganjil, karena tengahnya pasti nol
            // Makanya nyari tengahnya
            if (baris % 2 != 0) {
                ELMT(mathasil,baris/2,baris/2) = ELMT(*m,baris/2,baris/2);
            }
        }
    }
    *m = mathasil;
}
