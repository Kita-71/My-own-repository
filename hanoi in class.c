#include <stdio.h>
#include <time.h>
#include <windows.h>
void hanoi(int *count, int n, char FIRST, char MID, char END);
void move(int *count, char FIRST, char END);
int main()
{
    int f;
    int *count = (int *)calloc(3, sizeof(int));
    printf("please input the floors of hanoi\n");
    scanf("%d", &f);
    count[0] = f;
    count[1] = 0;
    count[2] = 0;
    hanoi(count, f, 'A', 'B', 'C');
    system("Pause");
    free(count);
    return 0;
}
void hanoi(int *count, int n, char FIRST, char MID, char END)
{
    if (n == 1)
    {
        system("cls");
        printf("HANOI\n=================================================================\n");
        move(count, FIRST, END);
        Sleep(1000);
        return;
    }
    hanoi(count, n - 1, FIRST, END, MID);
    system("cls");
    printf("HANOI\n=================================================================\n");
    move(count, FIRST, END);
    Sleep(1000);
    hanoi(count, n - 1, MID, FIRST, END);
}
void move(int *count, char FIRST, char END)
{
    switch (FIRST)
    {
    case 'A':
        count[0]--;
        break;
    case 'B':
        count[1]--;
        break;
    case 'C':
        count[2]--;
        break;
    }
    switch (END)
    {
    case 'A':
        count[0]++;
        break;
    case 'B':
        count[1]++;
        break;
    case 'C':
        count[2]++;
        break;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            printf("-");
        }
        puts("");
    }
    puts("");
    printf("%c->%c\n", FIRST, END);
}
