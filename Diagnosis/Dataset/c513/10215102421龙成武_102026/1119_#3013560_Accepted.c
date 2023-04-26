#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//很神奇地没有考虑超车减速，破题目，直接扒江晖代码
typedef struct
{
    int advance;
    int remain;
    int speed;
    double to_time;

}car;

int main()
{
    long distance;
    car C[1010];
    int number;
    double speed;

    scanf("%d %d", &distance, &number);
    for (int i = 0; i < number; i++)
    {
        scanf("%d %d", &C[i].advance, &C[i].speed);
    }

    for (int i = 0; i < number; i++)
    {
        C[i].to_time = (double)(distance - C[i].advance) / (double)(C[i].speed);

    }

    double times = 0;
    for (int i = 0; i < number; i++)
    {
        if (times < C[i].to_time)
        {
            times = C[i].to_time;
        }
    }
    speed = distance / times;
    printf("%.6f", speed);
    return 0;
}
