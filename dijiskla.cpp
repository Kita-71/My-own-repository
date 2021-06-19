#include <stdio.h>
#include <windows.h>
#define MAX 100000000
typedef struct gragh
{
    char vertical;
    int weight;
    gragh *last;
    int mark;
} gragh;

int main()
{
    //6*verticals
    int matrix[6][6];
    for (int i = 0; i < 6; i++)
        for (int j = i + 1; j < 6; j++)
        {
            printf("%c->%c(if no routes, put in -1)", 'a' + i, 'a' + j);
            scanf_s("%d", &matrix[i][j]);
            if (matrix[i][j] == -1)
                matrix[i][j] = MAX;
            matrix[j][i] = matrix[i][j];
        }
    for (int i = 0; i < 6; i++)
        matrix[i][i] = 0;
    // matrix
    gragh dij[6];
    for (int i = 0; i < 6; i++)
    {
        dij[i].vertical = 'a' + i;
        dij[i].last = NULL;
        dij[i].weight = MAX;
        dij[i].mark = 0;
    }
    dij[0].weight = 0;
    //verticals
    int min_weight = MAX;
    int pos = 0;
    while (pos != 5)
    {
        int current = pos;
        dij[current].mark = 1;
        int min_weight = MAX;
        for (int j = 0; j < 6; j++)
        {
            if (dij[current].weight + matrix[current][j] < dij[j].weight && dij[j].mark != 1)
            {
                dij[j].last = &dij[current];
                dij[j].weight = dij[current].weight + matrix[current][j];
            }
            if (dij[j].weight < min_weight && dij[j].mark != 1)
            {
                min_weight = dij[j].weight;
                pos = j;
            }
        }
    }
    while (pos != 0)
    {
        printf("%c<-%c", dij[pos].vertical, dij[pos].last->vertical);
        pos = dij[pos].last->vertical - 'a';
    }
}