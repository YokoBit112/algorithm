#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
	char id[100], name[100],level;
	int rank;
	double score;
};
int sa[6];
bool so(Student a, Student b) {
	return a.score > b.score;
}
double Static(Student a[]) {
	sort(a, a + 10, so);
	double sum = 0;
	for (int i = 0; i != 10; i++)
	{
		a[i].rank = i + 1;
		sum += a[i].score;
		if (a[i].score >= 90) {
			a[i].level = 'A'; sa[1]++;
		}
		else if (a[i].score >= 80) { a[i].level = 'B'; sa[2]++; }
		else if (a[i].score >= 70) {
			a[i].level = 'C'; sa[3]++;
	}
		else if (a[i].score >= 60) { a[i].level = 'D'; sa[4]++; }
		else {
			a[i].level = 'E'; sa[5]++;
		}
		printf("��%d��Ϊ:%s %s       ����Ϊ��%.1Lf  �ȼ�Ϊ��%c\n", i + 1, a[i].name, a[i].id, a[i].score, a[i].level);

	}
	printf("A�ȼ���%d��\nB�ȼ���%d��\nC�ȼ���%d��\nD�ȼ���%d��\nE�ȼ���%d��\n",sa[1],sa[2],sa[3],sa[4],sa[5]);
	return sum / 10;
}
int main(void) {
	Student student[11];
	printf("������ʮ��ѧ����ѧ�š��������ɼ����ȼ������Σ�\n");
	for (int i = 0; i != 10; i++)
	{
		printf("�������%d��ѧ����ѧ�ţ�", i + 1); scanf("%s", student[i].id);
		printf("�������%d��ѧ����������", i + 1); scanf("%s", student[i].name);
		printf("�������%d��ѧ���ĳɼ���", i + 1); scanf("%Lf", &student[i].score);
	}

	printf("ƽ����Ϊ��%.2Lf", Static(student));
	return 0;
}