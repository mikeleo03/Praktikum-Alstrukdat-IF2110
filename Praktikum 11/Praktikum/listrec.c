// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 17 November 2022
// Topik praktikum : ADT List Rekursif
// Deskripsi : Implementasi Tambahan ADT List Rekursif

#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

/* Manajemen Memori */
Address newNode(ElType x)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Address p = (Address) malloc(sizeof(Node));
    if (p != NIL) {  /* Berhasil teralokasi */
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l)
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
{
    /* KAMUS */
    /* ALGORITMA */
    return (l == NULL);
}

boolean isOneElmt(List l)
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */
{
    /* KAMUS */
    /* ALGORITMA */
    return (!isEmpty(l) && tail(l) == NULL);
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l)
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
{
    /* KAMUS */
    /* ALGORITMA */
    return (INFO(l));
}

List tail(List l)
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
{
    /* KAMUS */
    /* ALGORITMA */
    return (NEXT(l));
}

List konso(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = newNode(e);
    if (p != NULL) {
        NEXT(p) = l;
        return p;
    } else {
        return l;
    }
}

List konsb(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l)) {
        return newNode(e);
    } else {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}

List copy(List l)
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (isEmpty(l)) {
        return NULL;
    } else {
        return (konso(copy(tail(l)), head(l)));
    }
}

List concat(List l1, List l2)
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (isEmpty(l1)) {
        return l2;
    } else {
        return (konso(concat(tail(l1), l2), head(l1)));
    }
}

/* Fungsi dan Prosedur Lain */
int length(List l)
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
{
    /* KAMUS */
    /* ALGORITMA */
    if (isEmpty(l)) {
        return 0;
    } else {
        return 1 + length(tail(l));
    }
}

boolean isMember(List l, ElType x)
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
{
    /* KAMUS */
    /* ALGORITMA */
    if (isEmpty(l)) {
        return false;
    } else if (head(l) == x) {
        return true;
    } else {
        return isMember(tail(l), x);
    }
}

void displayList(List l)
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
{
    /* KAMUS */
    /* ALGORITMA */
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}

/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
ElType maxList (List l)
/* Mengirimkan nilai INFO(p) yang maksimum */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (isOneElmt(l)) {
        return head(l);
    } else {
        if (head(l) > maxList(tail(l))) {
            return head(l);
        } else {
            return maxList(tail(l));
        }
    }
}

ElType minList (List l)
/* Mengirimkan nilai INFO(p) yang minimum */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (isOneElmt(l)) {
        return head(l);
    } else {
        if (head(l) < minList(tail(l))) {
            return head(l);
        } else {
            return minList(tail(l));
        }
    }
}

ElType sumList (List l)
/* Mengirimkan total jumlah elemen List l */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (isEmpty(l)) {
        return 0;
    } else {
        return head(l) + sumList(tail(l));
    }
}

float averageList (List l)
/* Mengirimkan nilai rata-rata elemen list l */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (float) ((float) sumList(l) / (float) length(l));
}

/*** Operasi-Operasi Lain ***/
List inverseList (List l)
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (isEmpty(l)) {
        return NULL;
    } else {
        return konsb(inverseList(tail(l)),head(l));
    }
}

void splitPosNeg (List l, List *l1, List *l2)
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */ 
/* l1 berisi semua elemen l yang positif atau 0, sedangkan l2 berisi
semua elemen l yang negatif; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (isEmpty(l)) {
        *l1 = NULL;
        *l2 = NULL;
    } else {
        if (head(l) >= 0) {
            splitPosNeg(tail(l), l1, l2);
            *l1 = konso(*l1, head(l));
        } else {
            splitPosNeg(tail(l), l1, l2);
            *l2 = konso(*l2, head(l));
        }
    }
}

void splitOnX (List l, ElType x, List *l1, List *l2)
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang lebih kecil dari x, dengan urutan
kemunculan yang sama, l2 berisi semua elemen l yang tidak masuk ke
l1, dengan urutan kemunculan yang sama. */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (isEmpty(l)) {
        *l1 = NULL;
        *l2 = NULL;
    } else {
        if (head(l) < x) {
            splitOnX (tail(l), x, l1, l2);
            *l1 = konso(*l1, head(l));
        } else {
            splitOnX (tail(l), x, l1, l2);
            *l2 = konso(*l2, head(l));
        }
    }
}

int compareList (List l1, List l2)
/* Menghasilkan: -1 jika l1 < l2, 0 jika l1 = l2, dan 1 jika l1 > l2 */
/* Jika l[i] adalah elemen l pada urutan ke-i dan |l| adalah panjang l: */
/* l1 = l2: |l1| = |l2| dan untuk semua i, l1[i] = l2[i] */
/* l1 < l2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari l1 dan l2, l1[i]<l2[i] atau: Jika pada semua elemen pada
urutan i yang sama, l1[i]=l2[i], namun |l1|<|l2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* l1>l2: kebalikan dari l1<l2 */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l1) && isEmpty(l2)) {
        return 0;
    } else if (isEmpty(l1) && !isEmpty(l2)) {
        return -1;
    } else if (!isEmpty(l1) && isEmpty(l2)) {
        return 1;
    } else if (head(l1) < head(l2)) {
        return -1;
    } else if (head(l1) > head(l2)) {
        return 1;
    } else {
        return compareList(tail(l1), tail(l2));
    }
}

boolean isAllExist (List l1, List l2)
/* Menghasilkan true jika semua elemen dalam l1 terdapat dalam l2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika l1 kosong, maka hasilnya false. */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmpty(l1)) {
        return true;
    } else if (!isMember(l2, head(l1))) {
        return false;
    } else {
        return isAllExist(tail(l1), l2);
    }
}

void Extremes (List l, int *max, int *min)
/* { I.S. l terdefinisi, tidak kosong }
{ F.S. min berisi nilai minimum elemen l,max berisi nilai maksimum elemen l } */
{
    /* KAMUS LOKAL */
    int maxtemp, mintemp;

    /* ALGORITMA */
    if (isOneElmt(l)) {
        *max = head(l);
        *min = head(l);
    } else {
        Extremes(tail(l), &maxtemp,&mintemp);

        if (maxtemp >= head(l)) {
            *max = maxtemp;
        } else {
            *max = head(l);
        }

        if (mintemp < head(l)) {
            *min = mintemp;
        } else {
            *min = head(l);
        }
    }
}

void Listpos (List l1, List l2, List *l3)
/* { I.S. l terdefinisi, tidak kosong }
{ F.S. min berisi nilai minimum elemen l,max berisi nilai maksimum elemen l } */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (isEmpty(l1) && isEmpty(l2)) {
        // do nothing
    } else {
        *l3 = konsb(*l3,head(l1) + head(l2));
        Listpos(tail(l1),tail(l2),l3);
    }
}

