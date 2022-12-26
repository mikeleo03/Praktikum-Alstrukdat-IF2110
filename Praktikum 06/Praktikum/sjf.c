// NIM : 13521108
// Nama : Michael Leon Putra Widhi
// Tanggal : 13 Oktober 2022
// Topik praktikum : ADT Queue
// Deskripsi : Aplikasi ADT Prioqueuetime

#include <stdio.h>
#include "prioqueuetime.h"
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include "prioqueuetime.h"

int main()
{
    int n;
    scanf("%d", &n);

    PrioQueueTime stack2;
    MakeEmpty(&stack2, n);

    PrioQueueTime stack;
    MakeEmpty(&stack, n);

    infotype X;

    int time;
    char c;

    int currTime = 0;
    int clock = 0;

    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d %c", &time, &c);
        X.time = time;
        X.info = c;
        Enqueue(&stack2, X);
        if (currTime == 0)
        {
            Dequeue(&stack2, &X);
            int tempTime = X.time;
            X.time = clock;
            Enqueue(&stack, X);

            currTime = tempTime;
            clock += tempTime;
        }
        currTime--;
    }

    if (!IsEmpty(stack))
    {
        for (i = Head(stack); i <= Tail(stack); i++)
        {
            printf("%d %c\n", stack.T[i].time, stack.T[i].info);
        }
    }

    if (!IsEmpty(stack2))
    {
        for (i = Head(stack2); i <= Tail(stack2); i++)
        {
            printf("%d %c\n", clock, stack2.T[i].info);
            clock += stack2.T[i].time;
        }
    }

    return 0;
}