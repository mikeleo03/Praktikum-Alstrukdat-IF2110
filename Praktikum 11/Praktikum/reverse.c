// bil : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 17 November 2022
// Topik praktikum : ADT List Rekursif
// Deskripsi : Aplikasi ADT List Rekursif pada Reverse

#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

void printList(List l) {
    if (isOneElmt(l)) {
		printf("%d", INFO(l));
	} else {
		printf("%d ", INFO(l));
        printList(tail(l));
	}
}

void splitAtIdx(List l, int idx, int incr, List *lout) {
	if (length(l) < idx && incr == 0) {
		if (isEmpty(l)) {
            return; // tidak melakukan 
        } else {
			*lout = konso(*lout, INFO(l));
			return splitAtIdx(NEXT(l), idx, incr, lout);
		}
	} else {
    	if (incr < idx) {
    		*lout = konso(*lout, INFO(l));
    		return splitAtIdx(NEXT(l), idx, incr + 1, lout);	
    	} else {
    		return; // tidak melakukan apapun juga
    	}
    }
}

List skipTillIdx(List l, int idxStop) {
	if (idxStop == 0 || length(l) < idxStop) {
        return l;
    } else {
		return skipTillIdx(NEXT(l), idxStop - 1);
	}
}


int main() {
    // KAMUS LOKAL
	int jumlah, rec, i, bil;
    List l, l1, l2;
    boolean endLoop;

    // ALGORITMA 
    // Membuat List kosong
    l = NULL;
    l1 = NULL;
	l2 = NULL;

    // Mengambil nilai jumlah dan rec
	scanf("%d %d", &jumlah, &rec);

    // Mengambil input data urutan mahasiswa
	i = 0;
	while (i < jumlah) {
		scanf("%d", &bil);
		l = konsb(l, bil);
		i++;
	}

    // Pemrosesan data
	endLoop = false;
	while(!endLoop && !isEmpty(l)) {
		if (length(l) == rec || length(l) < rec) {
            endLoop = true;
        }
		splitAtIdx(l, rec, 0, &l1);
		printList(l1);  // Cetak hasil
		l1 = NULL;  // reset
		if (length(l) > rec) {
			printf(" ");
			l = skipTillIdx(l, rec);
		} else {
            l = NULL;
        }
	}

    // Templet olympia biasa
	printf("\n");
	return 0;
}