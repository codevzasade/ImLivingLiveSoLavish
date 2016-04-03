#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "locale.h"

#define MAX 5 // Место под конец строки
struct lib
{
	int key; // шифр
	char *ath; // автор
	char *nbook; // название книги
}
libbase[1] = { 25671, "Михаил Достоевский", "Идиот" },
libbase2 = { 35672, "Лев Толстой", "Война и мир" },
libbase3 = { 32143, "Александр Куприн", "Яма" },
libbase4 = { 54122, "Александр Пушкин", "Дубровский" },
libbase5 = { 54127, "Михаил Булгаков", "Белая гвардия" };

struct stud
{
	int nticket;
	char *sname;
	char *date;
}
studbase[1] = { 89423, "Скайнет", "25.07.1994" };


int main()
{
	setlocale(LC_ALL, "Rus");
	int i, n, temp[10], max;
	printf("\n\t \t Добро пожаловать в электронную библиотеку! \n \n Пользователь: %s \n \n Список доступной литературы:\n\n", studbase[0].sname);
	for (i = 0; i < 5; i++)
	{
		printf("\t%d. %s\n", i+1, libbase[i].nbook);
	}
	printf("\n Сколько книг вам нужно?\n ->");
	scanf_s("%d", &max);
	if (max>MAX)
	{
		printf(" Ошибка: В библиотеке нет столько книг.\n");
		return 0;
	}
	printf("\n Какие книги хотите заказать?\n");
	for (i = 0; i < max; i++)
	{
		printf(" ->");
		scanf_s("%d", &temp[i]);
	}
	printf("\n Ваш итоговый заказ: (*Штрихкод*) (*Название*)\n\n");
	for (i = 0; i < max; i++)
	{
		n = temp[i];
		printf("\t%d. (%d) %s \n", i + 1, libbase[n - 1].key, libbase[n - 1].nbook);
	}
	return 0;
}

