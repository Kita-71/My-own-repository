#include <stdio.h>
#include <windows.h>
typedef struct task
{
    int C; //任务完工时间
    int T; //工期
    int L; //超出工期时间,负数表示提前完成
} task;
int FCFS(task *data, int n);
int EDD(task *data, int n);
int find_max(int *l, int n);
int main()
{
    int n = 0;
    printf("please enter the number of jobs\n");
    scanf("%d", &n);
    puts("");
    task *data = (task *)calloc(n, sizeof(task));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i].C);
        scanf("%d", &data[i].T);
        puts("");
    }

    int min_Lmax_FSFC = FCFS(data, n); //先来先服务的总完成时间
    int min_Lmax_EDD = EDD(data, n);   //短作业优先的总完成时间
    printf("%d\n", min_Lmax_FSFC);
    printf("%d\n", min_Lmax_EDD);
    system("Pause");
    return 0;
}
int FCFS(task *data, int n)
{
    int *c = (int *)calloc(n, sizeof(int));
    int *l = (int *)calloc(n, sizeof(int));
    c[0] = 0;
    l[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            c[i] = data[i].C;
            l[i] = c[i] - data[i].T;
        }
        else
        {
            c[i] = data[i].C + c[i - 1];
            l[i] = c[i] - data[i].T;
        }
    }
    int l_max = find_max(l, n);
    free(c);
    free(l);
    return l_max;
} //先来先服务
int EDD(task *data, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (data[i].T > data[j].T)
            {
                task temp = data[j];
                data[j] = data[i];
                data[i] = temp;
            }
        }
    }                          //按最短周期进行排序
    int l_max = FCFS(data, n); //排序后等同于先来先服务
    return l_max;
} //最短工期优先
int find_max(int *l, int n)
{
    int l_max = l[0];
    for (int i = 1; i < n; i++)
    {
        if (l[i] > l_max)
            l_max = l[i];
    }
    return l_max;
}