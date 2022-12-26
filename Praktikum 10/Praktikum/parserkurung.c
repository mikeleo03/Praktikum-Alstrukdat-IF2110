// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 12 November 2022
// Topik praktikum : ADT Variasi Linked List - Stack Linked List
// Deskripsi : Aplikasi ADT Stack Linked List pada parser kurung

#include <stdio.h>
#include "charmachine.h"
#include "stacklinked.h"

char currentChar;
boolean EOP;

int main() {
    // KAMUS LOKAL
	Stack S;
    int i = 0, counterSpecTegak = 0, trash, max = 0;
	int checker = 0;
	int sum_0 = 0, sum_1 = 0, sum_2 = 0, sum_3 = 0, sum_4 = 0;

    // ALGORITMA 
    CreateStack(&S);
	START();
	while (!EOP) {
		if (currentChar == '[') {
			push(&S, 0);
			checker++;
			if (max < length(S))
				max = length(S);
		} if (currentChar == '(') {
			push(&S, 1);
			checker++;
			if (max < length(S))
				max = length(S);
		} if (currentChar == '|') {
			if(isEmpty(S)) {
				push(&S, 2);
				if (max < length(S))
				max = length(S);
			} else {
				if (TOP(S) == 2) {
					pop(&S, &trash);
					sum_2++;
				} else {
					push(&S, 2);
					if (max < length(S))
					max = length(S);
				}
			}
		} if (currentChar == '{') {
			push(&S, 3);
			checker++;
			if (max < length(S))
				max = length(S);
		} if (currentChar == '<') {
			push(&S, 4);
			checker++;
			if (max < length(S))
				max = length(S);
		} if (currentChar == ']') {
			if (!isEmpty(S))
			{
				if (TOP(S) == 0)
				{
					pop(&S, &trash);
					sum_0++;
				}
			}
			checker--;
		} if (currentChar == ')') {
			if (!isEmpty(S))
			{
				if (TOP(S) == 1)
				{
					pop(&S, &trash);
					sum_1++;
				}
			}
			checker--;
		} if (currentChar == '}') {
			if (!isEmpty(S))
			{
				if (TOP(S) == 3)
				{
					pop(&S, &trash);
					sum_3++;
				}
			}
			checker--;
		} if (currentChar == '>') {
			if (!isEmpty(S))
			{
				if (TOP(S) == 4)
				{
					pop(&S, &trash);
					sum_4++;
				}
			}
			checker--;
		} if (currentChar == '[' || currentChar == ']' || currentChar == '(' || currentChar == ')' || currentChar == '|' || currentChar == '{' || currentChar == '}' || currentChar == '<' || currentChar == '>') {
			DisplayStack(S);
			printf("\n");
		}
		ADV();
	}

	if (!isEmpty(S) || (isEmpty(S) && checker != 0)) {
		printf("kurung tidak valid\n");
	} else {
		printf("kurung valid\n");
		printf("[%d] (%d) |%d| {%d} <%d>\n", sum_0, sum_1, sum_2, sum_3, sum_4);
		printf("MAX %d\n", max);
	}

	return 0;
}