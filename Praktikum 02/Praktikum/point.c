/* File : point.c */
/* Body ADT Point */
#include <stdio.h>
#include "point.h"
#include "boolean.h"
#include <math.h>
#define _USE_MATH_DEFINES

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT *P, float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{   /* Kamus Lokal */
    /* Algoritma */
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT *P) 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{   /* Kamus Lokal */
    float x, y;
    /* Algoritma */
    scanf("%f %f",&x,&y);
    CreatePoint(P,x,y);
}

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{   /* Kamus lokal */
    /* Algoritma */
    printf("(%.2f,%.2f)",Absis(P),Ordinat(P));
}              

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{   /* Kamus lokal */
    /* Algoritma */
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{   /* Kamus lokal */
    /* Algoritma */
    return (!EQ(P1,P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{   /* Kamus lokal */
    /* Algoritma */
    return (Absis(P) == 0 && Ordinat(P) == 0);
}

boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{   /* Kamus lokal */
    /* Algoritma */
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{   /* Kamus lokal */
    /* Algoritma */
    return (Absis(P) == 0);
}

int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{   /* Kamus lokal */
    int x, y;
    /* Algoritma */
    x = Absis(P);
    y = Ordinat(P);
    if (x > 0 && y > 0) {
        return 1;
    } else if (x < 0 && y > 0) {
        return 2;
    } else if (x < 0 && y < 0) {
        return 3;
    } else {
        return 4;
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */ 
{   /* Kamus lokal */
    /* Algoritma */
    Absis(P) += 1;
    return P;
}

POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{   /* Kamus lokal */
    /* Algoritma */
    Ordinat(P) += 1;
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{   /* Kamus lokal */
    /* Algoritma */
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{   /* Kamus lokal */
    /* Algoritma */
    if (SbX && Ordinat(P) == 0) {
        Ordinat(P) *= (1);
    } else if (!SbX && Absis(P) == 0) {
        Absis(P) *= (1);
    } else if (SbX) {
        Ordinat(P) *= (-1);
    } else {
        Absis(P) *= (-1);
    }
    return P;
}

float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{   /* Kamus lokal */
    /* Algoritma */
    return sqrt(pow(Absis(P),2)+pow(Ordinat(P),2));
}

float Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
{   /* Kamus lokal */
    /* Algoritma */
    return sqrt(pow((Absis(P1)-Absis(P2)),2)+pow((Ordinat(P1)-Ordinat(P2)),2));
}

void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{   /* Kamus lokal */
    /* Algoritma */
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{   /* Kamus lokal */
    /* Algoritma */
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{   /* Kamus lokal */
    /* Algoritma */
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{   /* Kamus lokal */
    /* Algoritma */
    if (SbX && Ordinat(*P) == 0) {
        Ordinat(*P) *= (1);
    } else if (!SbX && Absis(*P) == 0) {
        Absis(*P) *= (1);
    } else if (SbX) {
        Ordinat(*P) *= (-1);
    } else {
        Absis(*P) *= (-1);
    }
}

void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
{   /* Kamus lokal */
    float x, y, m, n;
    /* Algoritma */
    if (Sudut >= 360) {
        m = ceil(Sudut / 360) - 1;
        Sudut -= m * 360;
    } else if (Sudut < 0 && Sudut >= -360) {
        Sudut += 360;
    } else if (Sudut < -360) {
        n = ceil(Sudut / 360) - 1;
        Sudut -= n * 360;
    }
    Sudut = (Sudut * M_PI) / 180;
    x = Absis(*P);
    y = Ordinat(*P);
    Absis(*P) = x*cos(Sudut) + y*sin(Sudut);
    Ordinat(*P) = y*cos(Sudut) - x*sin(Sudut);
}