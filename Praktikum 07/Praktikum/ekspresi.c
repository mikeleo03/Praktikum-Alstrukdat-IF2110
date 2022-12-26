// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 22 Oktober 2022
// Topik pra-praktikum : ADT Stack
// Deskripsi : Aplikasi ADT Stack pada pemrosesan mesin kata pada penjumlahan dengan notasi postfix

#include "stack.h"
#include "wordmachine.h"
#include <stdio.h>
#include <math.h>

boolean isOperator () {
    /* KAMUS */

    /* ALGORITMA */
    return (currentWord.TabWord[0] == '+' || currentWord.TabWord[0] == '-' || currentWord.TabWord[0] == '*' ||currentWord.TabWord[0] == '/' || currentWord.TabWord[0] == '^');
}

int hitung (int m, int n, char ops) {
    /* KAMUS */

    /* ALGORITMA */
    int hasil;

    switch (ops) {
        case '+':
            hasil = m + n;
            break;
        case '-':
            hasil = m - n;
            break;
        case '*':
            hasil = m * n;
            break;
        case '/':
            hasil = m / n;
            break;
        case '^':
            hasil = pow(m,n);
            break;
    }

    return hasil;
}

int main() {
    /* KAMUS LOKAL */
    Stack S;
    infotype N1, N2;
    int total, i;

    /* ALGORITMA */
    CreateEmpty(&S);

    STARTWORD();

    if (endWord) {
        printf("Ekspresi kosong\n");
    } else {
        do {
            if (!isOperator()) {
                total = 0;
                for (i = 0; i < currentWord.Length; i++) {
                    total += (currentWord.TabWord[i] - 48) * pow(10,currentWord.Length-i-1);
                }
                Push(&S,total);

                printf("%d\n",total);
            }
            else {
                Pop(&S, &N2);
                Pop(&S, &N1);
                Push(&S, hitung(N1, N2, currentWord.TabWord[0]));

                printf("%d %c %d\n", N1, currentWord.TabWord[0], N2);
                printf("%d\n", hitung(N1, N2, currentWord.TabWord[0]));
            }
            ADVWORD();
        } while (!endWord);

        printf("Hasil=%d\n",InfoTop(S));
    }
}

