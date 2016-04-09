#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "locale.h"

#define MAX 5 // Ìåñòî ïîä êîíåö ñòðîêè
struct lib
{
	int key; // øèôð
	char *ath; // àâòîð
	char *nbook; // íàçâàíèå êíèãè
}
libbase[1] = { 25671, "Ìèõàèë Äîñòîåâñêèé", "Èäèîò" },
libbase2 = { 35672, "Ëåâ Òîëñòîé", "Âîéíà è ìèð" },
libbase3 = { 32143, "Àëåêñàíäð Êóïðèí", "ßìà" },
libbase4 = { 54122, "Àëåêñàíäð Ïóøêèí", "Äóáðîâñêèé" },
libbase5 = { 54127, "Ìèõàèë Áóëãàêîâ", "Áåëàÿ ãâàðäèÿ" };

struct stud
{
	int nticket;
	char *sname;
	char *date;
}
studbase[1] = { 89423, "Ñêàéíåò", "25.07.1994" };


int main()
{
	setlocale(LC_ALL, "Rus");
	int i, n, temp[10], max;
	printf("\n\t \t Äîáðî ïîæàëîâàòü â ýëåêòðîííóþ áèáëèîòåêó! \n \n Ïîëüçîâàòåëü: %s \n \n Ñïèñîê äîñòóïíîé ëèòåðàòóðû:\n\n", studbase[0].sname);
	for (i = 0; i < 5; i++)
	{
		printf("\t%d. %s\n", i+1, libbase[i].nbook);
	}
	printf("\n Ñêîëüêî êíèã âàì íóæíî?\n ->");
	scanf_s("%d", &max);
	if (max>MAX)
	{
		printf(" Îøèáêà: Â áèáëèîòåêå íåò ñòîëüêî êíèã.\n");
		return 0;
	}
	printf("\n Êàêèå êíèãè õîòèòå çàêàçàòü?\n");
	for (i = 0; i < max; i++)
	{
		printf(" ->");
		scanf_s("%d", &temp[i]);
	}
	printf("\n Âàø èòîãîâûé çàêàç: (*Øòðèõêîä*) (*Íàçâàíèå*)\n\n");
	for (i = 0; i < max; i++)
	{
		n = temp[i];
		printf("\t%d. (%d) %s \n", i + 1, libbase[n - 1].key, libbase[n - 1].nbook);
	}
	return 0;
}

