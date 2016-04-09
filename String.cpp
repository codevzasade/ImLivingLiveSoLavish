#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define NUM 1000

int main()
{
	int i, g, item = 0, j = 0;
	char str[NUM];
	srand(time(NULL));
	for (i = 0; i < NUM; i++)
	{
		if (i == NUM - 1)
			str[i] = '\0';
		else if (i % 9 == 0 && i > 0)
			str[i] = ' ';
		else
			str[i] = rand() % 26 + 97;
	}
	printf("Source string:\n%s\n", str);
	printf("\nResult string:\n");
	i = 0;
	for (i; i < NUM; i++)
	{
		j += 1;
		if (str[i] == ' ' || str[i] == '\0')
		{
			g = i - (j - 1); 
			j = 0; 
			if (str[g] == str[i - 1])
			{
				// printf("g: %d , i: %d\n", g, i);
				item += 1;
				for (g; g < i; g++)
				{
					printf("%c", str[g]);
				}
				printf(" ");
			}
		}
	}
	printf("\n\nitem:%d\n\n", item);
	return 0;
}




