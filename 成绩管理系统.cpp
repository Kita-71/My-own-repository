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
} Student;//ѧ���ɼ���
void get(Student* student)
{
    printf("����:\n");
    scanf("%s", &student->name);
    printf("ѧ��:\n");
    scanf("%d", &student->number);
    printf("���ĳɼ�:\n");
    scanf("%f", &student->Chinese);
    printf("Ӣ��ɼ�:\n");
    scanf("%f", &student->Maths);
    printf("��ѧ�ɼ�:\n");
    scanf("%f", &student->English);
}//�ɼ�¼�뺯��
void output1(Student* student)
{
    printf("������%s\n", student->name);
    printf("ѧ�ţ�%d\n", student->number);
    printf("���ĳɼ� ��%.2f\n", student->Chinese);
    printf("��ѧ�ɼ� ��%.2f\n", student->Maths);
    printf("Ӣ��ɼ���%.2f\n", student->English);
}
void output2(Student* student)
{
    printf("������%s ", student->name);
    printf("ѧ�ţ�%d ", student->number);
    printf("���ĳɼ� ��%.2f ", student->Chinese);
    printf("��ѧ�ɼ� ��%.2f ", student->Maths);
    printf("Ӣ��ɼ���%.2f ", student->English);
    (student->Sum) = (student->Chinese) + (student->Maths) + (student->English);
    printf("�ܷ֣�%.2f \n", student->Sum);
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
}//������ѯ����
void checknumber(Student* student, int p)
{
    if (student->number==p)
        output1(student);
}//ѧ�Ų�ѯ����
void checksubject(Student* student, char s[name_len],int p)
{
    char Chinese[] ="����";
    char Maths[] = "��ѧ";
    char English[] = "Ӣ��";
    if (strcmp(Chinese, s) == 0)
        output_Chinese(student,p);
    if (strcmp(Maths, s) == 0)
        output_Maths(student,p);
    if (strcmp(English, s) == 0)
        output_English(student,p);
}//��Ŀ��ѯ����
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
    int n;//�˵�ѡ�����
    int m = 1;//���ز˵�ѡ�����
    int k, q;

    while (choice)
    {
        student = (Student*)realloc(student, i * sizeof(Student));
        if (student == NULL)
            exit(1);
        get(student + i - 1);
        i++;
        printf("�Ƿ����¼��ɼ�������������ֵ���� ����0�˳�\n");
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

    char Chinese[] = "����";
    char Maths[] = "��ѧ";
    char English[] = "Ӣ��";

    while (m)

    {   
        printf("��ѡ���ܣ������Ӧ�����֣�\n________________________________________________\n1�����Ʋ�ѯ\n2��ѧ�Ų�ѯ\n3����Ŀ��ѯ\n4���ɼ�����\n5:����ɼ���\6:�򿪳ɼ���\n0���˳�\n");
        scanf("%d",&n);
        switch (n)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("��Ҫ��ѯ��ѧ���ǣ�");
            scanf("%s",check_name);
            for (j = 1; j < i; j++)
            {
                checkname(student + j - 1,check_name);
            }
            printf("�Ƿ񷵻ز˵�?��������ֵ���� ����0�˳�");
            scanf("%d", &m);
            break;
        case 2:
            printf("��Ҫ��ѯ��ѧ����ѧ���ǣ�");
            scanf("%d",&check_number);
            for (j = 1; j < i; j++)
            {
                checknumber(student + j - 1, check_number);
            }
            printf("�Ƿ񷵻ز˵�?��������ֵ���� ����0�˳�");
            scanf("%d", &m);
            break;
        case 3:
            printf("��Ҫ��ѯ�Ŀ�Ŀ�ǣ�");
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
                printf("����ƽ�����ǣ�%f\n", average_Chinese);
            if (strcmp(Maths, check_subject) == 0)
                printf("��ѧƽ�����ǣ�%f\n", average_Maths);
            if (strcmp(English, check_subject) == 0)
                printf("Ӣ��ƽ�����ǣ�%f\n",average_English);

            printf("�Ƿ񷵻ز˵�?��������ֵ���� ����0�˳�");
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
            printf("����ƽ���֣�%.2f ��ѧƽ���֣�%.2f Ӣ��ƽ���֣�%.2f ��ƽ���֣�%.2f\n ", average_Chinese, average_Maths, average_English, average_Sum);
            break;
        default:
            break;
        }
    }
    free(student);
    return 0;
}
