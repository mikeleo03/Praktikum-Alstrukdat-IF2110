// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 12 November 2022
// Topik praktikum : ADT Variasi Linked List - Queue Linked List
// Deskripsi : Implementasi ADT Queue Linked List pada Butak

#include "queuelinked.h"
#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>

boolean isElHomogen(Queue q) {
    /* KAMUS LOKAL */
    boolean sama;
    Address p;
    int nilai;

    /* ALGORITMA */
    sama = true;
    p = ADDR_HEAD(q);
    nilai = HEAD(q);
    while (p != NIL && sama) {
        if (INFO(p) != nilai) {
            sama = false;
        }
        p = NEXT(p);
    }

    return sama;
}

int main() {
    // KAMUS LOKAL
	Queue q1, q2, q3;
	CreateQueue(&q1);
	CreateQueue(&q2);
	CreateQueue(&q3);
	int N = 0;

    // ALGORITMA
	START();
	boolean switchSides = false;
	while (!EOP) {
		if (currentChar == ',') {
			switchSides = true;
			for (int i = 1; i <= N; i++) {
				enqueue(&q3, i);
			}
		} if (!switchSides) {
			if (currentChar == 'B') {
				enqueue(&q2, 0);
			} if (currentChar == 'K') {
				enqueue(&q2, 1);
			}
			N++;
		} else {
			if (currentChar == 'B') {
				enqueue(&q1, 0);
			} if (currentChar == 'K') {
				enqueue(&q1, 1);
			}
		}
		ADV();
	}
	int id, trash1, trash2;
	int first_id = HEAD(q2);
	int i = 0;
	while (!isEmpty(q1) && i < length(q3)) {
		if (HEAD(q1) == HEAD(q2)) {
			dequeue(&q1, &trash1);
			dequeue(&q2, &trash2);
			dequeue(&q3, &id);
			if (trash1 == 0) {
				printf("%d -> bulat\n", id);
			} else {
				printf("%d -> kotak\n", id);
			}
			i = 0;
		} else {
			i++;
			dequeue(&q2, &trash2);
			dequeue(&q3, &id);
			enqueue(&q2, trash2);
			enqueue(&q3, id);
		}
	}

	printf("%d\n", length(q2));

	return 0;
}