#include <stdio.h>
#include <windows.h>
#include <time.h>
#define wall 0
#define route 1
void creatwall(int** maze, int length);
void creat_in(int** maze);
void creat_out(int** maze);
void creatmaze(int length, int** maze);
void printfmaze(int** maze, int length);
int judgewall(int i, int j, int** maze);
int judgeend_2(int length, int** maze);
int main()
{
    int i;
    int length;
    int** maze;
    puts("please input n");
    scanf_s("%d", &length);
    maze = (int**)malloc((length + 2) * sizeof(int*));
    for (i = 0; i < length + 2; i++)
        maze[i] = (int*)calloc((length + 2), sizeof(int*));
    //创建迷宫二维数组(增加两列作为判断依据)，动态分配地址
    creatwall(maze, length);
    //填充迷宫
    creat_in(maze);
    //弄入口
    creatmaze(length, maze);
    //挖迷宫
    //creat_out(maze);
    //找出口
    printfmaze(maze, length);
    //打印迷宫
    free(maze);
    system("Pause");
    return 0;
}
void creatwall(int** maze, int length)
{
    int i, j;
    for (i = 0; i <= length + 1; i++)
    {
        maze[0][i] = route;
        maze[i][0] = route;
        maze[i][length + 1] = route;
        maze[length + 1][i] = route;
    }
    for (i = 1; i <= length; i++)
        for (j = 1; j <= length; j++)
            maze[i][j] = wall;
}
void printfmaze(int** maze, int length)
{
    int i, j;
    for (i = 0; i <= length + 1; i++)
        for (j = 0; j <= length + 1; j++)
        {
            if (maze[i][j] == wall)
                printf("■");
            else if (maze[i][j] == route)
                printf("□");
            if (j == length + 1)
                printf("\n");
        }
}
void creat_in(int** maze)
{
    maze[2][1] = route;
    maze[2][2] = route;
}
void creatmaze(int length, int** maze)
{
    int derection[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; //方向
    int x = 2, y = 2, n, dx = 2, dy = 2, i, j, deep, p = 1,count=0;
    deep = rand() % 4 + 2;
    while (deep)
    {
        if (deep != 1)
        {
            for (i = 0;; i++)
            {
                srand(time(NULL));
                n = rand() % 4;
                dx = x + derection[n][0];
                dy = y + derection[n][1];
                if (maze[x - 1][y] == route && maze[x][y - 1] == route && maze[x + 1][y] == route && maze[x][y + 1] == route)
                {
                    deep = 1;
                    break;
                } //防止十字路口陷入死循环
                if (judgewall(x + 1, y, maze) == 0 && judgewall(x, y + 1, maze) == 0 && judgewall(x - 1, y, maze) == 0 && judgewall(x, y - 1, maze) == 0)
                    break;
                if (maze[dx][dy] != route)
                {
                    if (derection[n][1] == 0) //上下挖的时候
                    {
                        if (maze[dx][dy - 1] == route || maze[dx][dy + 1] == route || maze[dx + derection[n][0]][dy] == route)
                        {
                            continue;
                        } //能不能挖
                        else
                        {
                            maze[dx][dy] = route;
                            x = dx, y = dy;
                            printfmaze(maze, length);
                            break;
                        } //能挖继续挖
                    }
                    else //左右挖的时候
                    {
                        if (maze[dx][dy + derection[n][1]] == route || maze[dx - 1][dy] == route || maze[dx + 1][dy] == route)
                        {
                            continue;
                        } //能不能挖
                        else
                        {
                            maze[dx][dy] = route;
                            x = dx, y = dy;
                            printfmaze(maze, length);
                            break;
                        }
                    }
                } //开挖
            }
        }
        else
        {
 
                deep = rand() % 4 + 2;
                for (int heihei = 1;; heihei++)
                {
                    x = rand() % length + 1;
                    y = rand() % length + 1;
                    if (maze[x][y] == route)
                        break;
                }
                if (count % 40 == 0)
                    if(judgeend_2(length, maze)==0)
                     return;
        }
        
        //判断还有没有墙可以挖，有就继续
        deep--;
        count++;
    }
}
//随机找个方向，判断是否能挖

int judgewall(int i, int j, int** maze)
{   
    if (maze[i][j] == route)
        return 0;
    int k, o = 0;
    int derection[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    for (k = 0; k <= 3; k++)
    {
        if (maze[i + derection[k][0]][j + derection[k][1]] == route)
            o++;
    }
    if (o >= 2)
        return 0; //不能挖
    else if (o == 0 && judgewall(i - 1, j, maze) == 0 && judgewall(i + 1, j, maze) == 0 && judgewall(i, j - 1, maze) == 0 && judgewall(i, j + 1, maze) == 0)
        return 0; //十字墙 挖不到
    else
        return 1; //还能挖
}

int judgeend_2(int length, int** maze)
{
    for (int haha = 3; haha < length; haha++)
        for (int xixi = 3; xixi < length; xixi++)
        {
            if (maze[haha][xixi] == wall && judgewall(haha, xixi, maze))
                return 1; //判断还有没有墙可以挖，有就继续
        }
    return 0;
}
