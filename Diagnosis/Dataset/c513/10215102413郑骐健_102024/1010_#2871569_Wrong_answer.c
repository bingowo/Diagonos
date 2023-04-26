#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    int z = 0;
    char s[500];
    int num = 0;
    char c;  
    int point = 0;
        int t = 1;
    while (c = getchar())
    {
      
        if (c == '\n')
        {
            if (z % 3 == 1)
            {
                for (int j = 0;j < 4;j++)
                {
                    if (num & (t << j))
                    {
                        s[point] = '1';
                    }
                    else s[point] = '0';
                    point++;
                }
            }

            else if (z % 3 == 2)
            {
                for (int j = 0;j < 7;j++)
                {
                    if (num & (t << j))
                    {
                        s[point] = '1';
                    }
                    else s[point] = '0';
                    point++;
                }
            }
            break;
        }
        num *= 10;
        num += c - '0';
        z++;
        if (z % 3 == 0)
        {
            for (int j = 0;j < 10;j++)
            {
                if (num & (t << j))
                {
                    s[point] = '1';
                }
                else s[point] = '0';
                point++;
            }
            num = 0;
        }
    }
        printf("0001");
        for (int j = 0;j <  10;j++)
        {
            if (z & (t << j))
            {
                s[point] = '1';
            }
            else s[point] = '0';
            point++;
        }
        for (int j = point - 1;j > -1;j--)
        {
            printf("%c", s[j]);
        }
    
    return 0;
}
