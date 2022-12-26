// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 22 Oktober 2022
// Topik pra-praktikum : ADT Stack
// Deskripsi : Aplikasi ADT Stack pada pengurangan big int

#include "stack.h"
#include <stdio.h>
#include <math.h>

int angka(char CC) {
    /* KAMUS */

    /* ALGORITMA */
    return CC - 48;
}

char karakter(int N) {
    /* KAMUS */

    /* ALGORITMA */
    return N + 48;
}

int main() {
    /* KAMUS */
    int NMAX = 200;
    Stack S1, S2, S3, S4, SMin, STemp1, STemp2, STemp;
    infotype NMin, N1, N2, K1, K2, dig1, dig2;
    char CC1[NMAX], CC2[NMAX];
    boolean minta, bukannol, lebihbesar;
    int digit1, digit2, k, m;

    /* ALGORITMA */
    /* Membuat 4 empty stack, siap masukin angka */
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&S3);
    CreateEmpty(&S4);
    CreateEmpty(&STemp);
    CreateEmpty(&STemp1);
    CreateEmpty(&STemp2);

    /* Meminta input 4 bilangan, masukin ke stack */
    scanf ("%s %s", CC1, CC2);
    k = 0;
    m = 0;
    while ((int) (CC1[k] - 48) >= 0) {
        Push(&S1,(int) CC1[k] - 48);
        Push(&S3,(int) CC1[k] - 48);
        k += 1;
    }

    while ((int) (CC2[m] - 48) >= 0) {
        Push(&S2,(int) CC2[m] - 48);
        Push(&S4,(int) CC2[m] - 48);
        m += 1;
    }

    /* Mau bandingin si 2 bilangan ini dulu */
    /* Bilangan 1 */
    digit1 = 0;
    while (!IsEmpty(S3)) {
        Pop(&S3, &K1);
        Push(&STemp1,K1);
        digit1 += 1;
    }

    /* Bilangan 2 */
    digit2 = 0;
    while (!IsEmpty(S4)) {
        Pop(&S4, &K2);
        Push(&STemp2,K2);
        digit2 += 1;
    }

    /* Cek yang lebih besar */
    if (digit1 > digit2) {
        lebihbesar = true;
    }
    else if (digit1 == digit2) {
        lebihbesar = true;
        while (!IsEmpty(STemp1)) {
            Pop(&STemp1,&dig1);
            Pop(&STemp2,&dig2);
            if (dig1 == dig2) {
                lebihbesar = true;
            }
            else if (dig1 > dig2) {
                lebihbesar = true;
                break;
            }
            else {
                lebihbesar = false;
                break;
            }
        }
    }
    else {
        lebihbesar = false;
    }

    /* Pindah supaya switch ke yang lebih besar */
    if (!lebihbesar) {
        /* Laksanakan prosedur copy stack */
        STemp = S2;
        S2 = S1;
        S1 = STemp;
    }

    /* Membuat stack penjumlahan kosong */
    CreateEmpty(&SMin);

    /* Proses pengurangan */
    minta = false;
    /* Kasus normal */
    while (!IsEmpty(S1) && !IsEmpty(S2)) {
        Pop(&S1, &N1);
        Pop(&S2, &N2);

        if (N1 < N2) {
            if (minta) {
                Push(&SMin, (10 + N1 - N2 - 1) % 10);
            } else {
                Push(&SMin, (10 + N1 - N2) % 10);
            }
            minta = true;
        } else if (N1 == N2) {
            if (minta) {
                Push(&SMin, 9);
                minta = true;
            } else {
                Push(&SMin, 0);
                minta = false;
            }
        } else {
            if (minta) {
                Push(&SMin, (N1 - N2 - 1) % 10);
            } else {
                Push(&SMin, (N1 - N2) % 10);
            }
            minta = false;
        }
    }

    /* Setealh normalisasi masih sisa di S1 */
    while (!IsEmpty(S1)) {
        Pop(&S1, &N1);

        if (minta && N1 == 0) {
            Push(&SMin, 9);
            minta = true;
        } else if (minta) {
            Push(&SMin, N1 - 1);
            minta = false;
        } else {
            Push(&SMin, N1);
        }
    }

    /* Cetak ke layar, handle kalo depannya 0 */
    /* Push simbol negatif */
    if (!lebihbesar) {
        printf("%c",45);
    }

    bukannol = false;
    while (!IsEmpty(SMin)) {
        Pop(&SMin, &NMin);
        if (NMin == 0 && !bukannol) {
            bukannol = false;
        } else  {
            printf("%c",karakter(NMin));
            // printf("%d", NMin);
            bukannol = true;
        }
    }
    if (!bukannol) {
        printf("%c",karakter(0));
    }
    printf("\n");
    return 0;
}