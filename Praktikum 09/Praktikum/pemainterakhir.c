// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 30 Oktober 2022
// Topik praktikum : ADT Variasi Linked List - List Sirkuler
// Deskripsi : Aplikasi ADT List Sirkuler Pada Permainan

#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	/* KAMUS LOKAL */
	List l;
	Address p;
	int n, k, count, i;
	ElType val;
	int idx, jumlah;

	/* ALGORITMA */
	// Membuat sebuah linked list
	CreateList(&l);

	// Memnita nilai n = jumlah pemain
	scanf("%d",&n);

	// Meminta nilai k sebagai angka ajaib
	scanf("%d",&k);

	// inisiasi linked list dengan elemen sebanyak  n
	for (i = 0; i < n; i++) {
		insertLast(&l, i+1);
	}

	// Melakukan skema seleksi
	// selama blm 1 elemen
	p = FIRST(l);
	count = 1;
	jumlah = 0;

	if (k == 1) {
		while (NEXT(FIRST(l)) != FIRST(l)) {
			deleteFirst(&l, &val);
			printf("%d\n",val);
		}
	} else {
		while (NEXT(FIRST(l)) != FIRST(l)) {
			if (count == k) {
				deleteFirst(&l, &val);
				printf("%d\n",val);
				count = 1;
			}
			deleteFirst(&l,&val);
			insertLast(&l,val);
			count++;
		}
	}

	deleteFirst(&l, &val);
	printf("Pemenang %d\n",val);
	return 0;
}