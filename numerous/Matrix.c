#include<malloc.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"matrix.h"
typedef struct 
{
    double **mat;
    int row,col;
}
Matrix;
int main()
{
    int n;
    Matrix t1,t2,t3;
    printf("矩阵函数测试，请选择功能，输入对应的数字：\n***************************************************\n1：输入一个矩阵，求矩阵均值；\n2：产生一个随机数矩阵，求矩阵均值；\n3：输入两个矩阵，求矩阵和；\n4：输入两个矩阵，求矩阵差；\n5：输入两个矩阵，求矩阵积；\n6：产生两个随机数矩阵，求矩阵和；\n7：产生两个随机数矩阵，求矩阵差；\n8：产生两个随机数矩阵，求矩阵积；\n9：求矩阵的子阵，如矩阵的2-4行，1-3列的子阵；\n10：输入一个矩阵，求矩阵元素的最大值；\n11：产生一个随机数矩阵，求矩阵元素的最大值；\n12：输入一个矩阵，求矩阵转置；\n13：产生一个随机数矩阵，求矩阵转置；\n14：输入一个矩阵，求矩阵归一化；\n15：产生一个随机数矩阵，求矩阵归一化；\n0：结束!\n");
    scanf("%d",&n);
    switch (n)
    {
    case 0:
        return 0;
        break;
    case 1:
        Test1(&t1);
        break;
    case 2:
        Test2(&t1);
        break;
    case 3:
        Test3(&t1,&t2,&t3);
        break;
    case 4:
        Test4(&t1,&t2,&t3);
        break;
    case 5:
        Test5(&t1,&t2,&t3);
        break;
    case 6:
        Test6(&t1,&t2,&t3);
        break;
    case 7:
        Test7(&t1,&t2,&t3);
        break;
    case 8:
        Test8(&t1,&t2,&t3);
        break;
    case 9:
        Test9(&t1,&t2);
        break;
    case 10:
        Test10(&t1);
        break;
    case 11:
        Test11(&t1);
        break;
    case 12:
        Test12(&t1);
        break;
    case 13:
        Test13(&t1);
        break;
    case 14:
        Test14(&t1);
        break;
    case 15:
        Test15(&t1);
        break;
    default:
        break;
    }
    printf("\n");
    system("pause");
    return 0;
}
void InitialMatrix(Matrix *T,int row,int col)
{
    if(row>0||col>0)
    {
        int i,j;
        T->col=col;
        T->row=row;
        T->mat=(double**)malloc(sizeof(double)*row);
        for(i=0;i<row;i++)
        {
            T->mat[i]=(double*)malloc(sizeof(double)*col);
        }
    }
    else
    {
        printf("error!");
    }
    
}
void InitialMatrixZero(Matrix *T,int row,int col)
{
    if(row>0||col>0)
    {
        int i,j;
        T->col=col;
        T->row=row;
        T->mat=(double**)malloc(sizeof(double)*row);
        for(i=0;i<row;i++)
        {
            T->mat[i]=(double*)malloc(sizeof(double)*col);
            for(j=0;j<col;j++)
            {
                T->mat[i][j]=0;
            }
        }
    }
    else
    {
        printf("error");
    }
    
}
void InitialMatrixRand(Matrix *m,int row,int col)
{
    if(row>0||col>0)
    {
        int i,j;
        srand((unsigned)time(NULL));
        m->col=col;
        m->row=row;
        m->mat=(double**)malloc(sizeof(double)*row);
        for(i=0;i<row;i++)
        {
            m->mat[i]=(double*)malloc(sizeof(double)*col);
            for(j=0;j<col;j++)
            {
                m->mat[i][j]=(int)(rand()%50+1);
            }
        }
        }
    else
    {
        printf("error");
    }    
}
void DestroyMatrix(Matrix *T)
{
    free(T->mat);
}
void InputMatrix(Matrix *T)
{
    int i,j;
    double t;
    printf("pless input matrix.\n");
    for(i=0;i<T->row;i++)
    {
        for(j=0;j<T->col;j++)
        {
            printf("plese input the element of row %d col %d\n",i+1,j+1);
            scanf("%lf",&t);
            T->mat[i][j]=t;
        }
    }
}
void PrintMatrix(Matrix *T)
{
    int i,j;
    printf("\nthe matrix is\n");
     for(i=0;i<T->row;i++)
        {
            for(j=0;j<T->col;j++)
            {
                
                {
                    printf("%f ",T->mat[i][j]);
                }
                      
            }
            printf("\n");
        }
    printf("\n");
}
void AddMatrix(Matrix *A,Matrix *B,Matrix *C)
{
    if((A->row==B->row)&&(A->col==B->col))
    {
        int i,j;
        C->row=A->row;
        C->col=A->col;
        InitialMatrix(C,C->row,C->col);
        for(i=0;i<C->row;i++)
        {
            for(j=0;j<C->col;j++)
            {
                C->mat[i][j]=A->mat[i][j]+B->mat[i][j];
            }
        }
        printf("\nSucceed to add Matrix!");
    }
}
void MinusMatrix(Matrix *A,Matrix *B,Matrix *C)
{
    if((A->row==B->row)&&(A->col==B->col))
    {
        int i,j;
        C->row=A->row;
        C->col=A->col;
        InitialMatrix(C,C->row,C->col);
        for(i=0;i<C->row;i++)
        {
            for(j=0;j<C->col;j++)
            {
                C->mat[i][j]=A->mat[i][j]-B->mat[i][j];
            }
        }
        printf("\nSucceed to minus Matrix!");
    }
}
void MultiMatrix(Matrix *A,Matrix *B,Matrix *C)
{
    if((A->col==B->row))
    {
        int i,j,k;
        C->row=A->row;
        C->col=B->col;
        InitialMatrix(C,C->row,C->col);
        for(i=0;i<C->row;i++)
        {
            for(j=0;j<C->col;j++)
            {
                for(k=0;k<A->col;k++)
                {
                    C->mat[i][j]=(C->mat[i][j])+(A->mat[i][k])*(B->mat[k][j]);
                }
            }
        }
        printf("\nSucceed to multi Matrix!");
        PrintMatrix(C);
    }
    else
    {
        printf("form error!");
    }
}
void TransMatrix(Matrix *T)
{
    int i,j;
    Matrix temp;
    InitialMatrix(&temp,T->row,T->col);
    for(i=0;i<T->row;i++)
    {
        for(j=0;j<T->col;j++)
        {
            temp.mat[i][j]=T->mat[i][j];
        }
    }
    InitialMatrix(T,temp.col,temp.row);
    for(i=0;i<T->row;i++)
    {
        for(j=0;j<T->col;j++)
        {
            T->mat[i][j]=temp.mat[j][i];
            printf("%f ",T->mat[i][j]);
        }
        printf("\n");
    }
}
double MeanMatrix(Matrix *T)
{
    int i,j;
    double sum=0;
    for(i=0;i<T->row;i++)
    {
        for(j=0;j<T->col;j++)
        {
            sum=sum+T->mat[i][j];
        }
    }
    sum=sum/(T->col*T->row);
    return sum;
}
void SubMatrix(Matrix *T1,Matrix *T2,int BeginRow,int BeginCol,int EndRow,int EndCol)
{
    if(BeginCol>0||BeginRow>0||EndCol>=BeginCol||EndRow>=BeginRow)
    {
        int i,j;
        InitialMatrix(T2,EndRow-BeginRow+1,EndCol-BeginCol+1);
        for(i=0;i<EndRow-BeginRow+1;i++)
        {
            for(j=0;j<EndCol-BeginCol+1;j++)
            {
                T2->mat[i][j]=T1->mat[i+BeginCol-1][j+BeginRow-1];
            }
        }
    }
    else
    {
        printf("error!");
    }
    
}
double MaxMatrix(Matrix *T)
{
    double max=T->mat[0][0];
    int i,j;
     for(i=0;i<T->row;i++)
        {
            for(j=0;j<T->col;j++)
            {
                if(max<T->mat[i][j])
                {
                    max=T->mat[i][j];
                }
            }
        }
    return max;
}
double MinMatrix(Matrix *T)
{
    double min=T->mat[0][0];
    int i,j;
     for(i=0;i<T->row;i++)
        {
            for(j=0;j<T->col;j++)
            {
                if(min>T->mat[i][j])
                {
                    min=T->mat[i][j];
                }
            }
        }
    return min;
}
void NormMatrix(Matrix *T)
{
    int i,j;
    double max,min;
    max=MaxMatrix(T);
    min=MinMatrix(T);
    for(i=0;i<T->row;i++)
    {
        for(j=0;j<T->col;j++)
        {
            T->mat[i][j]=(T->mat[i][j]-min)/(max-min);
        }
    }
}
void Test1(Matrix *T)
{
    int row,col;
    double mean;
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrix(T,row,col);
    InputMatrix(T);
    mean=MeanMatrix(T);
    printf("the mean of matrix is %f",mean);
}
void Test2(Matrix *T)
{
    int row,col;
    double mean;
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrixRand(T,row,col);
    PrintMatrix(T);
    mean=MeanMatrix(T);
    printf("the mean of matrix is %f",mean);
}
void Test3(Matrix *T1,Matrix *T2,Matrix *T3)
{
    int row,col;
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrix(T1,row,col);
    InitialMatrix(T2,row,col);
    InitialMatrix(T3,row,col);
    InputMatrix(T1);
    InputMatrix(T2);
    AddMatrix(T1,T2,T3);
    PrintMatrix(T3);
}
void Test4(Matrix *T1,Matrix *T2,Matrix *T3)
{
    int row,col;
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrix(T1,row,col);
    InitialMatrix(T2,row,col);
    InitialMatrix(T3,row,col);
    InputMatrix(T1);
    InputMatrix(T2);
    MinusMatrix(T1,T2,T3);
    PrintMatrix(T3);
}
void Test5(Matrix *T1,Matrix *T2,Matrix *T3)
{
    int row,col;
    printf("please input the left matrix\n");
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrix(T1,row,col);
    InputMatrix(T1);
    printf("please input the right matrix\n");
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrix(T2,row,col);
    InputMatrix(T2);
    MultiMatrix(T1,T2,T3);
}
void Test6(Matrix *T1,Matrix *T2,Matrix *T3)
{
    int row,col;
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrixRand(T1,row,col);
    InitialMatrixRand(T2,row,col);
    InitialMatrix(T3,row,col);
    PrintMatrix(T1);
    PrintMatrix(T2);
    AddMatrix(T1,T2,T3);
    PrintMatrix(T3);
}
void Test7(Matrix *T1,Matrix *T2,Matrix *T3)
{
    int row,col;
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrixRand(T1,row,col);
    InitialMatrixRand(T2,row,col);
    InitialMatrix(T3,row,col);
    PrintMatrix(T1);
    PrintMatrix(T2);
    MinusMatrix(T1,T2,T3);
    PrintMatrix(T3);
}
void Test8(Matrix *T1,Matrix *T2,Matrix *T3)
{
    int row,col;
    printf("please input the left matrix\n");
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrixRand(T1,row,col);
    PrintMatrix(T1);
    printf("please input the right matrix\n");
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrixRand(T2,row,col);
    PrintMatrix(T2);
    MultiMatrix(T1,T2,T3);
}
void Test9(Matrix *T1,Matrix *T2)
{
    int row,col,endrow,endcol;
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrix(T1,row,col);
    InputMatrix(T1);
    printf("please input the beginrow\n");
    scanf("%d",&row);
    printf("please input the begincol\n");
    scanf("%d",&col);
    printf("please input the endrow\n");
    scanf("%d",&endrow);
    printf("please input the endcol\n");
    scanf("%d",&endcol);
    SubMatrix(T1,T2,row,col,endrow,endcol);
    PrintMatrix(T2);  
}
void Test10(Matrix *T)
{
    int row,col;
    double max;
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrix(T,row,col);
    InputMatrix(T);
    max=MaxMatrix(T);
    printf("the max element of matrix is %f",max);
}
void Test11(Matrix *T)
{
    int row,col;
    double max;
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrixRand(T,row,col);
    PrintMatrix(T);
    max=MaxMatrix(T);
    printf("the max element of matrix is %f",max);
}
void Test12(Matrix *T)
{
    int row,col;
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrix(T,row,col);
    InputMatrix(T);
    printf("the trans of matrix is\n");
    TransMatrix(T);
}
void Test13(Matrix *T)
{
    int row,col;
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrixRand(T,row,col);
    PrintMatrix(T);
    printf("the trans of matrix is\n");
    TransMatrix(T);
}
void Test14(Matrix *T)
{
    int row,col;
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrix(T,row,col);
    InputMatrix(T);
    NormMatrix(T);
    printf("the norm matrix is\n");
    PrintMatrix(T);
}
void Test15(Matrix *T)
{
    int row,col;
    printf("please input the row\n");
    scanf("%d",&row);
    printf("please input the col\n");
    scanf("%d",&col);
    InitialMatrixRand(T,row,col);
    PrintMatrix(T);
    NormMatrix(T);
    printf("the norm matrix is\n");
    PrintMatrix(T);
}