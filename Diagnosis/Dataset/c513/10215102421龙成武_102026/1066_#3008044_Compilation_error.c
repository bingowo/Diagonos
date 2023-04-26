#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
int times(int ALLf, int floor, int minute, int end)
{
    if (minute == 0 && floor == end)
    {
        return 1;
    }
    else if (minute == 0 && floor != end)
    {
        return 0;
    }

    if (floor == 1)
    {
        return times(ALLf, floor + 1, minute - 1, end);
    }
    if (floor == ALLf)
    {
        return times(ALLf, floor - 1, minute - 1, end);
    }

    return times(ALLf, floor - 1, minute - 1, end) + times(ALLf, floor + 1, minute - 1, end);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {

        int n, p, m, t;
        scanf("%d%d%d%d", &n, &p, &m, &t);
        printf("%d\n", times(n, p, m, t));
    }

    return 0;
}


