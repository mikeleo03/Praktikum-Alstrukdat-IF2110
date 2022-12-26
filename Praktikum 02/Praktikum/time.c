/* File : time.c */
/* Body ADT Time */
#include <stdio.h>
#include "time.h"
#include "boolean.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S)
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{   /* Kamus Lokal */
    /* Algoritma */
    return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59));
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME *T, int HH, int MM, int SS)
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
{   /* Kamus Lokal */
    /* Algoritma */
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME *T)
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
{   /* Kamus Lokal */
    int h, m, s;
    /* Algoritma */
    scanf("%d %d %d", &h, &m, &s);
    if (IsTIMEValid(h,m,s)) {
        CreateTime(T,h,m,s);
    } 
    else {
        while (!IsTIMEValid(h,m,s))
        {
            printf("Jam tidak valid\n");
            scanf("%d %d %d", &h, &m, &s);
        }
        CreateTime(T,h,m,s);
    }
}
   
void TulisTIME (TIME T)
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
{   /* Kamus lokal */
    /* Algoritma */
    printf("%02d:%02d:%02d",Hour(T),Minute(T),Second(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T)
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{   /* Kamus Lokal */
    /* Algoritma */
    return (3600*Hour(T) + 60*Minute(T) + Second(T));
}

TIME DetikToTIME (long N)
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
{   /* Kamus Lokal */
    int h,m,s,sisa; 
    TIME t1;
    /* Algoritma */
    N = N % 86400; // pastikan n detik berada dalam rentang 24 jam
    h = N / 3600;
    sisa = N % 3600;
    m = sisa / 60;
    s = sisa % 60;
    CreateTime(&t1,h,m,s);
    return t1;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1=T2, false jika tidak */
{   /* Kamus Lokal */
    int s1,s2;
    /* Algoritma */
    s1 = TIMEToDetik(T1);
    s2 = TIMEToDetik(T2);
    return (s1 == s2);
}

boolean TNEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1 tidak sama dengan T2 */
{   /* Kamus Lokal */
    /* Algoritma */
    return (!TEQ (T1,T2));
}

boolean TLT (TIME T1, TIME T2)
/* Mengirimkan true jika T1<T2, false jika tidak */
{   /* Kamus Lokal */
    int s1,s2;
    /* Algoritma */
    s1 = TIMEToDetik(T1);
    s2 = TIMEToDetik(T2);
    return (s1 < s2);
}

boolean TGT (TIME T1, TIME T2)
/* Mengirimkan true jika T1>T2, false jika tidak */
{   /* Kamus Lokal */
    /* Algoritma */
    return (!TLT(T1,T2) && TNEQ (T1,T2));
}

/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T)
/* Mengirim 1 detik setelah T dalam bentuk TIME */
{   /* Kamus Lokal */
    int s1, max;
    /* Algoritma */
    max = 23*3600 + 59*60 + 60;
    s1 = TIMEToDetik(T) + 1;
    if (s1 >= max) {
        s1 %= max;
    }
    return DetikToTIME (s1);
}

TIME NextNDetik (TIME T, int N)
/* Mengirim N detik setelah T dalam bentuk TIME */
{   /* Kamus Lokal */
    int s1, max;
    /* Algoritma */
    max = 23*3600 + 59*60 + 60;
    s1 = TIMEToDetik(T) + N;
    if (s1 >= max) {
        s1 %= max;
    }
    return DetikToTIME (s1);
}

TIME PrevDetik (TIME T)
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
{   /* Kamus Lokal */
    int s1, max;
    /* Algoritma */
    max = 23*3600 + 59*60 + 60;
    s1 = TIMEToDetik(T) - 1;
    if (s1 <= 0) {
        s1 += max;
    }
    return DetikToTIME (s1);
}

TIME PrevNDetik (TIME T, int N)
/* Mengirim N detik sebelum T dalam bentuk TIME */
{   /* Kamus Lokal */
    int s1, max;
    /* Algoritma */
    max = 23*3600 + 59*60 + 60;
    s1 = TIMEToDetik(T) - N;
    if (s1 <= 0) {
        s1 += max;
    }
    return DetikToTIME (s1);
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh)
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
{   /* Kamus Lokal */
    long sAw, sAkh, max, selisih;
    /* Algoritma */
    max = 23*3600 + 59*60 + 60;
    sAw = TIMEToDetik(TAw);
    sAkh = TIMEToDetik(TAkh);
    selisih = sAkh - sAw;
    if (sAw > sAkh) {
        selisih += max;
    }
    return selisih;
}