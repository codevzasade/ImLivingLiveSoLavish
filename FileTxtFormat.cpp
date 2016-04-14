#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"

int main()
{
	FILE * f;
	fopen_s(&f, "CODE.txt", "r");
	int open, close, line, end, position, byte, bstr; // item'i
	open = close = line = end = 0;
	byte = bstr = 0; // s ychetom 1 elemt 0 po spisky
	while (feof(f) == 0)
	{
		item = ' ';
		while (item != '\n' && item != EOF)
		{
			item = fgetc(f);
			if (item == '(')
			{
				open++;
			}
			else
			{
				if (item == ')')
				{
					close++;
				}
			}
			bstr++;
			byte++;
		}
		line++;
		if (open != close)
		{
			item = ' ';
			fseek(f, byte - bstr, SEEK_SET);
			printf("Line %d: ", line);
			while (item != '\n' && item != EOF)
			{
				item = fgetc(f);
				printf("%c", item);
			}
			fseek(f, byte + 1, SEEK_SET);
		}
		byte += 1;
		open = close = bstr = 0;
	}
	getchar();
	return 0;
}

/* CODE.txt 
()()(()))
())
())
*/
