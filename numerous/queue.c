#include <stdio.h>
#include <windows.h>
typedef struct haha
{
    int number;
    int num;
    int first, end;
    int *q;
} queues;
queues *start(queues *zero)
{
    zero->q = (int *)calloc(zero->number, sizeof(int));
    return zero;
}
queues *pop(queues *two)
{
    int i;
    for (i = 0; i < two->number - 1; i++)
        two->q[i] = two->q[i + 1];
    two->first = two->number - two->num;
    two->end = two->number;
}
queues *append(queues *one)
{
    int i;
    if (one->end > one->number)
        pop(one);
    for (i = 0; i <= one->end - one->first - 1; i++)
    {
        printf("The %d memeber is", i + 1);
        scanf("%d", one->q + one->first + i);
    }
    return one;
}
int main()
{
    int i, num;
    int append_or_not = 1;
    queues cao;
    cao.first = 0;
    queues *p = &cao;
    puts("the length");
    scanf("%d", &cao.number);
    start(p); //创建队列
    while (append_or_not)
    {
        puts("append?yes--1,no--0");
        scanf("%d", &append_or_not);
        if (append_or_not == 1)
        {
            puts("how many");
            scanf("%d", &cao.num);
            cao.end = cao.first + cao.num;
            append(p);
            cao.first = cao.end;

            puts("Now the queue is:");
            for (i = 0; i < cao.end; i++)
                printf("%d ", cao.q[i]);
            printf("\n");
        }
    }
    free(p->q);
    system("Pause");
    return 0;
}