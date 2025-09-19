#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <stdbool.h>
bool IsRight(int date, int mouth[]);
bool IsBackWord(int date, int dateToWord[]);
int qi = 2;
int main(int argc, char* argv[])
{
    long long int date1,date2;
    scanf("%d%d", &date1,&date2);
    int mouth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    long long int i, year;
    int dateToWord[8] = { 0 };
    int dateToABAB[8] = { 0 };
    int result = 0;
    for (i = date1+1; i <= date2; i++)
    {
        year = i / 10000;
        if (year % 4 == 0)
            mouth[1] = 29;
        if (!IsRight(i, mouth))
            continue;
        //if (IsBackWord(i, dateToWord))
            //result++;
        if (i % 10 == 1&&qi == 1)
        {result++;}
        qi++;
        if (qi == 8)qi == 1;
    }
    printf("%d\n", result);
    return 0;
}



bool IsRight(int date, int mouth[])
{
    int mouthNumber = (date % 10000) / 100;
    int dayNumber = (date % 10000) % 100;
    if ((mouthNumber > 12) || (dayNumber > mouth[mouthNumber - 1]))
        return false;
    return true;
}

bool IsBackWord(int date, int dtw[])
{
    int temp;
    int j = 0;
    for (j = 0; j < 8; j++)
    {
        temp = date;
        temp = temp / (pow(10, 7 - j));
        dtw[j] = temp % 10;
    }
    if ((dtw[0] == dtw[7]) && (dtw[1] == dtw[6]) && (dtw[2] == dtw[5]) && (dtw[3] == dtw[4]))
        return true;
    return false;
}