#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#define n 10

int main()
{
	int i, j;
	/*part1_zadanie_dannix*/
	FILE * f;
	fopen_s(&f, "First.dat", "w");
	int free[n][n], temp, max_i, max_j, min_i, min_j, MaxItem, MinItem;
	srand(time(NULL));
	/*gen massiv*/
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			free[i][j] = rand() % 26 + 97;
			printf("%d\t", free[i][j]);
		}

	}
	fwrite(&free, 1, sizeof(free), f);
	fclose(f);
	printf("\n");
	/*part2_Sortiovka*/
	FILE * g;
	fopen_s(&g, "Two.dat", "w");
	for (i = 0; i < n; i++)
	{
		MaxItem=MinItem=0;
		max_i=max_j=min_i=min_j=0;
		for (j = 0; j < n; j++)
		{
			if (free[i][j] > MaxItem)
			{
				MaxItem = free[i][j];
				max_i = i;
				max_j = j;
			}
		}
		MinItem = MaxItem;
		for (j = 0; j < n; j++)
		{
			if (free[i][j] < MinItem)
			{
				MinItem = free[i][j];
				min_i = i;
				min_j = j;
			}
		}
		temp = free[max_i][max_j];
		free[max_i][max_j] = free[min_i][min_j];
		free[min_i][min_j] = temp;
		printf("\t\t line %d  | MinItem:%d \t MaxItem:%d |\n", i, free[max_i][max_j], free[min_i][min_j]);
	}
	printf("\n");
	fwrite(&free, 1, sizeof(free), g);
	/* vivod massiva*/
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", free[i][j]);
		}
	}
	fclose(g);
	getchar();
	return 0;
}
