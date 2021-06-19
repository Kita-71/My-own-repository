#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int id;
	char name[50];
	float chinese;
	float math;
	float english;
	float sum;
}student;
int ReadStuInfoFromFile(char* name, student** stu);
int NoPass(student stu[], int n, student** noPassStudent, int* m);
int Pass(student stu[], int n, student** PassStudent, int* m);
int SortStudents(student stu[], int n);
int PrintStudents(student stu[], int n);
int SearchStudent(student stu[], int n, int id, int* rank, student* rstu);
int main()
{
	int n, rank, id, i, m;
	char name[] = "stuScores.txt";
	student* stu = NULL, * noPassStu = NULL, * passStu = NULL, rstu;
	n = ReadStuInfoFromFile(name, &stu);
	if (n == 0) { printf("error"); return -1; }
	PrintStudents(stu, n);

	printf("\n no pass studnt--------\n");
	i = NoPass(stu, n, &noPassStu, &m);
	if (i == -1)printf("no pass error");
	else
		PrintStudents(noPassStu, m);

	printf("\n  passed studnt--------\n");
	i = Pass(stu, n, &passStu, &m);
	if (i == -1)printf(" pass error");
	else
		PrintStudents(passStu, m);

	printf("\n sort studnt--------\n");
	i = SortStudents(stu, n);
	if (i == -1)printf("sort error");
	else
		PrintStudents(stu, n);

	printf("\n search id--------\n");
	scanf_s("%d", &id);
	i = SearchStudent(stu, n, id, &rank, &rstu);
	if (i == -1)printf("search error");
	else
		PrintStudents(&rstu, 1);
	if (stu) { free(stu); stu = NULL; }
	if (noPassStu) { free(noPassStu); noPassStu = NULL; }
	if (passStu) { free(passStu); passStu = NULL; }
	return 0;
}
int ReadStuInfoFromFile(char* name, student** stu)
{
	int n;
	FILE* fp;
	fopen_s(&fp, name, "r");
	if (fp == NULL || name == NULL)return 0;
	fread(&n, sizeof(int), 1, fp);
	*stu = (student*)malloc(n * sizeof(student));
	int i;
	for (i = 0; i < n; i++)
	{
		fread(&((*stu)[i]), sizeof(struct student), 1, fp);
		(*stu)[i].sum = (*stu)[i].chinese + (*stu)[i].math + (*stu)[i].english;
	}
	fclose(fp);
	return n;
}
int NoPass(student stu[], int n, student** noPassStudent, int* m)
{
	if (n <= 0 || stu == NULL) return -1;
	int i, j = 0;
	float summery = 0, sumaver;
	for (i = 0; i < n; i++)
		summery += stu[i].sum;
	sumaver = summery / n;
	*noPassStudent = (student*)malloc(sizeof(student) * n);
	for (i = 0; i < n; i++)
	{
		if (stu[i].sum < sumaver)
		{
			(*noPassStudent)[j] = stu[i];
			j += 1;
		}
	}
	*m = j;
	return 0;
}
int Pass(student stu[], int n, student** PassStudent, int* m)
{
	if (n <= 0 || stu == NULL) return -1;
	int i, j = 0;
	float summery = 0, sumaver;
	for (i = 0; i < n; i++)
		summery += stu[i].sum;
	sumaver = summery / n;
	*PassStudent = (student*)malloc(sizeof(student) * n);
	for (i = 0; i < n; i++)
	{
		if (stu[i].sum < sumaver)
		{
			(*PassStudent)[j] = stu[i];
			j += 1;
		}
	}
	*m = j;
	return 0;
}
int SortStudents(student stu[], int n)
{
	if (n <= 0 || stu == NULL) return -1;
	student tmp;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (stu[j].sum < stu[j + 1].sum)
			{
				tmp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = tmp;
			}
		}
	}
	return 0;
}
int PrintStudents(student stu[], int n)
{
	if (n == 0 || stu == NULL)return -1;
	int i;
	for (i = 0; i < n; i++)
		printf("%d %s %f %f %f %f\n", stu[i].id, stu[i].name, stu[i].chinese, stu[i].math, stu[i].english, stu[i].sum);
	return 0;
}
int SearchStudent(student stu[], int n, int id, int* rank, student* rstu)
{
	if (n == 0 || stu == NULL)return -1;
	rank = (int*)malloc(sizeof(int));
	SortStudents(stu, n);
	int i, r = 0;
	for (i = 0; i < n; i++)
	{
		if (stu[i].id == id)
		{
			*rank = i + 1;
			*rstu = stu[i];
			r = 1;
		}
	}
	if (r)
		return 0;
	return -1;
}