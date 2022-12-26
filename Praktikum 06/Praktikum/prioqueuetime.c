// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 13 Oktober 2022
// Topik praktikum : ADT Queue
// Deskripsi : Implementasi ADT Prioqueuetime

#include <stdio.h>
#include "prioqueuetime.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty(PrioQueueTime Q)
{
    /* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}

boolean IsFull(PrioQueueTime Q)
{
    /* Mengirim true jika tabel penampung elemen Q sudah penuh */
    /* yaitu mengandung elemen sebanyak MaxEl */
    return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt(PrioQueueTime Q)
{
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsEmpty(Q))
    {
        return 0;
    }
    else
    {
        if (Tail(Q) < Head(Q))
        {
            return (MaxEl(Q) - (Head(Q) - Tail(Q)) + 1);
        }
        else
        {
            return (Tail(Q) - Head(Q) + 1);
        }
    }
}

/* *** Kreator *** */
void MakeEmpty(PrioQueueTime *Q, int Max)
{
    /* I.S. sembarang */
    /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
    /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
    /* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
    /* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    Q->T = (PrioQueueTime*) malloc ((Max+1) * sizeof(PrioQueueTime));
    if (Q) {
        Q->MaxEl = Max; 
    } else {
        Q->MaxEl = 0;
    }
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime *Q)
{
    /* Proses: Mengembalikan memori Q */
    /* I.S. Q pernah dialokasi */
    /* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    free(Q->T);
    MaxEl(*Q) = 0;
}

/* *** Primitif Add/Delete *** */
void Enqueue(PrioQueueTime *Q, infotype X)
{
    /* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan time */
    /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
    /* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
            TAIL "maju" dengan mekanisme circular buffer; */
    if (IsEmpty(*Q))
    {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    }
    else
    {
    int i = Tail(*Q);
    boolean fit = false;
    if (Tail(*Q) < Head(*Q)){
        i = i + Q->MaxEl;
        i = i % Q->MaxEl;
    }
    while (i >= Head(*Q) && !fit)
    {
        if (Elmt(*Q, i).time > X.time)
        {
            Elmt(*Q, i + 1) = Elmt(*Q, i);
        }
        else
        {
            Elmt(*Q, i + 1) = X;
            fit = true;
        }
        i--;
    }
    if (fit == false)
    {
        Elmt(*Q, Head(*Q)) = X;
    }
    Tail(*Q)++;
    Tail(*Q) %= Q->MaxEl;
    }
}

void Dequeue(PrioQueueTime *Q, infotype *X)
{
    /* Proses: Menghapus X pada Q dengan aturan FIFO */
    /* I.S. Q tidak mungkin kosong */
    /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
            Q mungkin kosong */
    *X = InfoHead(*Q);
    if (NBElmt(*Q) == 1)
    {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else
    {
        Head(*Q)++;
        Head(*Q) %= Q->MaxEl;
    }
}

/* Operasi Tambahan */
void PrintPrioQueueTime(PrioQueueTime Q)
{
    /* Mencetak isi queue Q ke layar */
    /* I.S. Q terdefinisi, mungkin kosong */
    /* F.S. Q tercetak ke layar dengan format:
    <time-1> <elemen-1>
    ...
    <time-n> <elemen-n>
    #
    */
    int j;
    for (j = Head(Q); j < Head(Q) + NBElmt(Q); j++)
    {
        // infotype val;
        j %= Q.MaxEl;
        // Dequeue(&Q, &val);
        printf("%d %c\n", Q.T[j].time, Q.T[j].info);
    }
    printf("#\n");
}