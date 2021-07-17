#include <stdio.h>
#include <windows.h>
#include <time.h>
int FCFS(int *data, int n);
int SJF(int *data, int n);
int main()
{
    int n = 0;
    printf("please enter the number of jobs\n");
    scanf("%d", &n);
    srand(time(NULL));
    int *data = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        data[i] = rand() % 99 + 1;
        printf("%d ", data[i]);
    }
    int sum_FCFS = FCFS(data, n); //先来先服务的总完成时间
    int sum_SJF = SJF(data, n);   //短作业优先的总完成时间
    printf("\nFCFS:%d\n", sum_FCFS);
    printf("SJF:%d\n", sum_SJF);

    system("Pause");
    return 0;
}
int FCFS(int *data, int n)
{
    int *c = (int *)calloc(n, sizeof(int));
    int sum = data[0];
    c[0] = data[0];
    for (int i = 1; i < n; i++)
    {
        c[i] = data[i] + c[i - 1];
        sum = sum + c[i];
    }
    free(c);
    return sum;
} //先来先服务
int SJF(int *data, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (data[i] > data[j])
            {
                int temp = data[j];
                data[j] = data[i];
                data[i] = temp;
            }
        }
    }
    int sum_SJF = FCFS(data, n);
    return sum_SJF;
} //短作业优先