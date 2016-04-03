#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main()
{
	const int n = 10; 
	int i, j;
	FILE * f = fopen("F.dat", "wb"); // файл для записи 
	int matrix[n][n], temp, index1, index2, index3, index4, MaxItem, MinItem; //выделяем динамическую память для матрицы
	srand(time(0));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 200 + 100; // заполнение матрицы 
			printf("%d ", matrix[i][j]);	  // вывод на экран 
			fprintf(f, "%d", matrix[i][j]);	  // запись у файл 
		}
		printf("\n"); fprintf(f, "\n");        // на новую строчку для красоты:)

	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		MaxItem=0;MinItem=n;
		index1=0;index2=0;index3=0;index4=0;
		//printf("line:%d\n", i);
		for (j = 0; j < n; j++)
		{
			if(matrix[i][j] > MaxItem)
			{
				MaxItem=matrix[i][j];
				index1=i;
				index2=j;
			}
		}
		MinItem=MaxItem;
		for (j = 0; j < n; j++)
		{
			if(matrix[i][j] < MinItem)
			{
				MinItem=matrix[i][j];
				index3=i;
				index4=j;
				//printf(" MinItem:%d i=%d j=%d ", MinItem, index3, index4);
			}
		}
		//printf("\n");
			temp=matrix[index1][index2];
			matrix[index1][index2]=matrix[index3][index4];
			matrix[index3][index4]=temp;
			fprintf(f, "%d", matrix[index3][index4]);
			fprintf(f, "%d", matrix[index1][index2]);
			printf("line %d | Min: %d <-> Max: %d\n", i, matrix[index1][index2], matrix[index3][index4]);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);	  // вывод на экран 
		}
		printf("\n"); fprintf(f, "\n");        // на новую строчку для красоты:)
	}
	printf("\n");
	fclose(f); // закрываем файл 
	return 0;
}
