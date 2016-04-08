#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
/*
������� ���� F1, ������������ �������� ��������
������������� ������� a1,.., a10, ������� ���. ����� �������
������� �� ����� � �������� � ���� F2, ���������� ��������
������ �������� � �������� �������.
*/
int main()
{
const int n = 10; int i,j;
FILE * f = fopen("F.dat", "wb"); // ���� ��� ������

int matrix[n][n];

for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
matrix[i][j] = rand() % 1000 - 50; // ���������� �������
printf("%d\t",matrix[i][j]); // ����� �� �����
}
printf("\n");

}

fwrite(matrix,sizeof(matrix),1,f);
fclose(f); // ��������� ����


printf("\n\n");

FILE *f2 = fopen("F.dat", "r"); // ��������� ���� ��� ����������
if(f2 == NULL) { printf("Error open file\n"); exit(-1); }
int num = 0,index_i = 0,index_j = 0;


fwrite(matrix,sizeof(matrix),1,f2);

fread(matrix, sizeof(matrix), 1, f2);

fclose(f2); // ��������� �������� �����

FILE *f3 = fopen("F2.dat", "wb"); // ��������� ���� ��� ������ � ���� ���� ����� ������ ������ �������
for (i = 1; i < n; i+=2) // i+=2 ��� ��� ���� ����� ������� ������� � ������ �������� 2 4 6 8
{
for (j = 0; j < n; j++)
{
printf("%d\t",matrix[i][n - j - 1]); // ����� �� ����� � �������� �������
}
printf("\n");
}

fwrite(matrix,sizeof(matrix),1,f3);
fread(matrix,sizeof(matrix), 1, f3);
fclose(f3);

getchar();
return 0;
}