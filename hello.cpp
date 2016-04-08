#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
/*
Создать файл F1, компонентами которого являются
целочисленные массивы a1,.., a10, закрыть его. Затем считать
массивы из файла и записать в файл F2, расположив элементы
четных массивов в обратном порядке.
*/
int main()
{
const int n = 10; int i,j;
FILE * f = fopen("F.dat", "wb"); // файл для записи

int matrix[n][n];

for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
matrix[i][j] = rand() % 1000 - 50; // заполнение матрицы
printf("%d\t",matrix[i][j]); // вывод на экран
}
printf("\n");

}

fwrite(matrix,sizeof(matrix),1,f);
fclose(f); // закрываем файл


printf("\n\n");

FILE *f2 = fopen("F.dat", "r"); // открываем файл для считывания
if(f2 == NULL) { printf("Error open file\n"); exit(-1); }
int num = 0,index_i = 0,index_j = 0;


fwrite(matrix,sizeof(matrix),1,f2);

fread(matrix, sizeof(matrix), 1, f2);

fclose(f2); // закрываем файловый поток

FILE *f3 = fopen("F2.dat", "wb"); // открываем файл для записи в этот файл будем писать четные массивы
for (i = 1; i < n; i+=2) // i+=2 это для того чтобы выбрать массивы с парным индексом 2 4 6 8
{
for (j = 0; j < n; j++)
{
printf("%d\t",matrix[i][n - j - 1]); // вывод на экран в обратном порядке
}
printf("\n");
}

fwrite(matrix,sizeof(matrix),1,f3);
fread(matrix,sizeof(matrix), 1, f3);
fclose(f3);

getchar();
return 0;
}