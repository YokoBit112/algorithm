#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Student {
	char name[100], id[100];
	double score;
};

void sort(Student a[])
{

	for (int p = 0; p != 10; p++) {
		Student temp; int min = 1e10, tem = 0;
		for (int i = p; i != 10; i++)
		{
			if (a[i].score < min) {
				min = a[i].score;
				tem = i;
			}
		}
		temp = a[tem];
		a[tem] = a[p];
		a[p] = temp;
	}
}

int main(void)
{
	Student student[11];
	printf("������10��ѧ����ѧ�š��������ɼ���\n");
	for (int i = 0; i != 10; i++)
	{
		printf("�������%d��ѧ����ѧ�ţ�", i + 1); scanf("%s", student[i].id);
		printf("�������%d��ѧ����������", i + 1); scanf("%s", student[i].name);
		printf("�������%d��ѧ���ĳɼ���", i + 1); scanf("%Lf", &student[i].score);
	}
	printf("���ɼ������\n");
	for (int i = 0; i != 10; i++)
	{
		printf("%s %s %.1Lf\n", student[i].id, student[i].name, student[i].score);
	}
	return 0;
}