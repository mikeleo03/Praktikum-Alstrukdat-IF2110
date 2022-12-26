// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 8 September 2022
// Topik praktikum : ADT Sederhana
// Deskripsi : Soal 3

#include <stdio.h>
#include "time.h"
#include "boolean.h"

int main() {
    int i, banyak;
    TIME t1, t2, t3, t4, tawal, takhir, tawal1, takhir1, tawalmin, takhirmaks;
    scanf("%d",&banyak);
    printf("[1]\n");
    BacaTIME (&t1);
    BacaTIME (&t2);
    if (TLT(t1, t2))
    {
        tawal = t1;
        takhir = t2;
    }
    else
    {
        tawal = t2;
        takhir = t1;
    }
    tawalmin = tawal;
    takhirmaks = takhir;
    printf("%d\n",Durasi(tawal,takhir));
    /* Inisialisasi data */
    for (i = 0; i < banyak - 1; i += 1)
    {
        printf("[%d]\n",i + 2);
        BacaTIME (&t3);
        BacaTIME (&t4);
        /* Cond 1 waktu */
        if (TLT(t3, t4))
        {
            tawal1 = t3;
            takhir1 = t4;
        }
        else
        {
            tawal1 = t4;
            takhir1 = t3;
        }
        /* cond 2 - nentuin yang lebih awal dan akhir */
        if (TLT(tawal1, tawalmin))
        {
            tawalmin = tawal1;
        }
        /* cond 3 */
        if (TGT(takhir1, takhirmaks))
        {
            takhirmaks = takhir1;
        }
        printf("%d\n",Durasi(tawal1,takhir1));
    }
    TulisTIME (tawalmin);
    printf("\n");
    TulisTIME (takhirmaks);
    printf("\n");

    return 0;
}