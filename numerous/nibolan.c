#include <stdio.h>
#include <windows.h>
#include <ctype.h>
typedef struct hello
{
    int length;
    int *number;
    int round;
} nibolan;
void getnumber(char *sentence, nibolan *p)
{
    int i, j = 0, num = 0;
    for (i = 0; i <= p->length; i++) //扫描字符串
    {
        if (isdigit(sentence[i]))
        {
            num = num * 10 + sentence[i] - '0'; //凑成完整的数
            if (sentence[i + 1] == ',')
            {
                p->number[j] = num; //读入
                num = 0;
                j++;
            }
        }
    }
}
int main()
{
    nibolan *p;
    nibolan go;
    p = &go;
    int final, round;
    puts("please tell me how long your sentence folumar is");
    scanf("%d", &go.length);
    char *sentence;
    sentence = (char *)calloc(go.length, sizeof(char));
    p->number = (int *)calloc(go.length, sizeof(char));
    puts("please put the sentence fomular in.\nWarning:You must input like\"3,3,+,2,-\"");
    scanf("%s", sentence);
    if (strlen(sentence) != go.length) //检测输入是否合规
    {
        printf("error");
        return 0;
    }
    getnumber(sentence, p);
    final = p->number[0];
    int i, j = 0;
    for (i = 0; i <= p->length; i++)
    {
        char check = sentence[i];
        switch (check)
        {
        case '+':
        {
            final += p->number[j];
            j++;
            break;
        }
        case '-':
        {
            final = final - p->number[j];
            j++;
            break;
        }
        case '*':
        {
            final = final * p->number[j];
            j++;
            break;
        }
        case '/':
        {
            final = (double) final / p->number[j];
            j++;
            break;
        }
        default:
            break;
        }
    }
    printf("%d\n", (double) final);
    system("Pause");
    free(sentence);
    return 0;
}