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
		printf("第%d名为:%s %s       分数为：%.1Lf  等级为：%c\n", i + 1, a[i].name, a[i].id, a[i].score, a[i].level);

	}
	printf("A等级有%d人\nB等级有%d人\nC等级有%d人\nD等级有%d人\nE等级有%d人\n",sa[1],sa[2],sa[3],sa[4],sa[5]);
	return sum / 10;
}
int main(void) {
	Student student[11];
	printf("请输入十个学生的学号、姓名、成绩、等级、名次：\n");
	for (int i = 0; i != 10; i++)
	{
		printf("请输入第%d个学生的学号：", i + 1); scanf("%s", student[i].id);
		printf("请输入第%d个学生的姓名：", i + 1); scanf("%s", student[i].name);
		printf("请输入第%d个学生的成绩：", i + 1); scanf("%Lf", &student[i].score);
	}

	printf("平均分为：%.2Lf", Static(student));
	return 0;
}