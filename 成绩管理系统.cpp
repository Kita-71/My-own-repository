#define _CRT_SECURE_NO_WARNINGS
#define name_len 64
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    char name[name_len];
    int number;
    float Chinese, Maths, English;
    float Sum ;
} Student;//学生成绩单
void get(Student* student)
{
    printf("姓名:\n");
    scanf("%s", &student->name);
    printf("学号:\n");
    scanf("%d", &student->number);
    printf("语文成绩:\n");
    scanf("%f", &student->Chinese);
    printf("英语成绩:\n");
    scanf("%f", &student->Maths);
    printf("数学成绩:\n");
    scanf("%f", &student->English);
}//成绩录入函数
void output1(Student* student)
{
    printf("姓名：%s\n", student->name);
    printf("学号：%d\n", student->number);
    printf("语文成绩 ：%.2f\n", student->Chinese);
    printf("数学成绩 ：%.2f\n", student->Maths);
    printf("英语成绩：%.2f\n", student->English);
}
void output2(Student* student)
{
    printf("姓名：%s ", student->name);
    printf("学号：%d ", student->number);
    printf("语文成绩 ：%.2f ", student->Chinese);
    printf("数学成绩 ：%.2f ", student->Maths);
    printf("英语成绩：%.2f ", student->English);
    (student->Sum) = (student->Chinese) + (student->Maths) + (student->English);
    printf("总分：%.2f \n", student->Sum);
}
void output_Chinese(Student* student,int i)
{
    printf("%d.",i);
    printf("%s ", student->name);
    printf("%.2f\n", student->Chinese);
}
void output_Maths(Student* student,int i)
{
    printf("%d.", i);
    printf("%s ", student->name);
    printf("%.2f\n", student->Maths);
}
void output_English(Student* student,int i)
{   
    printf("%d.", i);
    printf("%s ", student->name);
    printf("%.2f\n", student->English);
}
void checkname(Student* student, char s[name_len])
{
    if (strcmp(student->name, s) == 0)
        output1(student);
}//姓名查询函数
void checknumber(Student* student, int p)
{
    if (student->number==p)
        output1(student);
}//学号查询函数
void checksubject(Student* student, char s[name_len],int p)
{
    char Chinese[] ="语文";
    char Maths[] = "数学";
    char English[] = "英语";
    if (strcmp(Chinese, s) == 0)
        output_Chinese(student,p);
    if (strcmp(Maths, s) == 0)
        output_Maths(student,p);
    if (strcmp(English, s) == 0)
        output_English(student,p);
}//科目查询函数
void swap_Student(Student* x, Student* y)
{   
    Student temp = *x;
    *x = *y;
    *y = temp;
}
    
int main()
{
    Student* student = NULL;
    int i = 1, j, choice = 1;
    int n;//菜单选择变量
    int m = 1;//返回菜单选择变量
    int k, q;

    while (choice)
    {
        student = (Student*)realloc(student, i * sizeof(Student));
        if (student == NULL)
            exit(1);
        get(student + i - 1);
        i++;
        printf("是否继续录入成绩：输入任意数值继续 输入0退出\n");
        scanf("%d", &choice);
        putchar('\n');
    }

    char check_subject[name_len];
    char check_name[name_len];
    int check_number;
    float average_English=0;
    float average_Maths=0;
    float average_Chinese=0;
    float average_Sum = 0;

    char Chinese[] = "语文";
    char Maths[] = "数学";
    char English[] = "英语";

    while (m)

    {   
        printf("请选择功能，输入对应的数字：\n________________________________________________\n1：名称查询\n2：学号查询\n3：科目查询\n4：成绩遍历\n5:保存成绩单\6:打开成绩单\n0：退出\n");
        scanf("%d",&n);
        switch (n)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("你要查询的学生是：");
            scanf("%s",check_name);
            for (j = 1; j < i; j++)
            {
                checkname(student + j - 1,check_name);
            }
            printf("是否返回菜单?输入任意值返回 输入0退出");
            scanf("%d", &m);
            break;
        case 2:
            printf("你要查询的学生的学号是：");
            scanf("%d",&check_number);
            for (j = 1; j < i; j++)
            {
                checknumber(student + j - 1, check_number);
            }
            printf("是否返回菜单?输入任意值返回 输入0退出");
            scanf("%d", &m);
            break;
        case 3:
            printf("你要查询的科目是：");
            scanf("%s",check_subject);
            if (strcmp(Chinese, check_subject) == 0)
            {
                for (q = i - 1; q >= 0; q--)
                {
                    for (k = 1; k < q; k++)
                        {
                            if (((student + q - 1)->Chinese) < (student + k - 1)->Chinese)
                            {
                                swap_Student(student + q - 1, student + k - 1);
                            }
                        }
                }
            }
            if (strcmp(Maths, check_subject) == 0)
            {
                for (q = i - 1; q >= 0; q--)
                {
                    for (k = 1; k < q; k++)
                    {
                        if (((student + q - 1)->Maths) < (student + k - 1)->Maths)
                        {
                            swap_Student(student + q - 1, student + k - 1);
                        }
                    }
                }
            }
            if (strcmp(English, check_subject) == 0)
            {
                for (q = i - 1; q >= 0; q--)
                {
                    for (k = 1; k < q; k++)
                    {
                        if (((student + q - 1)->English) < (student + k - 1)->English)
                        {
                            swap_Student(student + q - 1, student + k - 1);
                        }
                    }
                }
            }
            
            for (j = 1; j < i; j++)
            {
                checksubject(student + j - 1, check_subject,j);
                average_Chinese = average_Chinese + ((student + j - 1)->Chinese) / (i-1);
                average_Maths = average_Maths + ((student + j - 1)->Maths) / (i - 1);
                average_English = average_English + ((student + j - 1)->English) / (i - 1);
            }
            if (strcmp(Chinese, check_subject) == 0)
                printf("语文平均分是：%f\n", average_Chinese);
            if (strcmp(Maths, check_subject) == 0)
                printf("数学平均分是：%f\n", average_Maths);
            if (strcmp(English, check_subject) == 0)
                printf("英语平均分是：%f\n",average_English);

            printf("是否返回菜单?输入任意值返回 输入0退出");
            scanf("%d", &m);
            break;
        case 4:
        
            for (q = i - 1; q >= 0; q--)
            {
                for (k = 1; k < q; k++)
                {
                    if (((student + q - 1)->Sum) < (student + k - 1)->Sum)
                    {
                        swap_Student(student + q - 1, student + k - 1);
                    }
                }
            }
            for (j = 1; j < i;j++)
            {
                output2(student + j - 1);
                average_Chinese = average_Chinese + ((student + j - 1)->Chinese) / (i - 1);
                average_Maths = average_Maths + ((student + j - 1)->Maths) / (i - 1);
                average_English = average_English + ((student + j - 1)->English) / (i - 1);
                average_Sum = average_Sum + ((student + j - 1)->Sum) / (i - 1);
            }
            printf("语文平均分：%.2f 数学平均分：%.2f 英语平均分：%.2f 总平均分：%.2f\n ", average_Chinese, average_Maths, average_English, average_Sum);
            break;
        default:
            break;
        }
    }
    free(student);
    return 0;
}
