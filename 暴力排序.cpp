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
	printf("请输入10个学生的学号、姓名、成绩：\n");
	for (int i = 0; i != 10; i++)
	{
		printf("请输入第%d个学生的学号：", i + 1); scanf("%s", student[i].id);
		printf("请输入第%d个学生的姓名：", i + 1); scanf("%s", student[i].name);
		printf("请输入第%d个学生的成绩：", i + 1); scanf("%Lf", &student[i].score);
	}
	printf("按成绩排序后：\n");
	for (int i = 0; i != 10; i++)
	{
		printf("%s %s %.1Lf\n", student[i].id, student[i].name, student[i].score);
	}
	return 0;
}