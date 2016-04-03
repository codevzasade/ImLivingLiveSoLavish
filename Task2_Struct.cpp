#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "locale.h"

#define MAX 5 // ����� ��� ����� ������
struct lib
{
	int key; // ����
	char *ath; // �����
	char *nbook; // �������� �����
}
libbase[1] = { 25671, "������ �����������", "�����" },
libbase2 = { 35672, "��� �������", "����� � ���" },
libbase3 = { 32143, "��������� ������", "���" },
libbase4 = { 54122, "��������� ������", "����������" },
libbase5 = { 54127, "������ ��������", "����� �������" };

struct stud
{
	int nticket;
	char *sname;
	char *date;
}
studbase[1] = { 89423, "�������", "25.07.1994" };


int main()
{
	setlocale(LC_ALL, "Rus");
	int i, n, temp[10], max;
	printf("\n\t \t ����� ���������� � ����������� ����������! \n \n ������������: %s \n \n ������ ��������� ����������:\n\n", studbase[0].sname);
	for (i = 0; i < 5; i++)
	{
		printf("\t%d. %s\n", i+1, libbase[i].nbook);
	}
	printf("\n ������� ���� ��� �����?\n ->");
	scanf_s("%d", &max);
	if (max>MAX)
	{
		printf(" ������: � ���������� ��� ������� ����.\n");
		return 0;
	}
	printf("\n ����� ����� ������ ��������?\n");
	for (i = 0; i < max; i++)
	{
		printf(" ->");
		scanf_s("%d", &temp[i]);
	}
	printf("\n ��� �������� �����: (*��������*) (*��������*)\n\n");
	for (i = 0; i < max; i++)
	{
		n = temp[i];
		printf("\t%d. (%d) %s \n", i + 1, libbase[n - 1].key, libbase[n - 1].nbook);
	}
	return 0;
}

