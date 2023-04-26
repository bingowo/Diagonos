#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char s[30];
int point = 0;
void push(char c)
{
    s[point++] = c;
}
void output()
{
    while (point > 0)
    {  
        point--;
        printf("%c", s[point]);
    }

}
int main()
{
    int z = 0;
    char p[600];
    int res = 0;
     int t = 1;
     scanf("%s", p);
        int num = strlen(p);
            printf("0001");
            for (int j = 0;j < 10;j++)
            {
                if (num & (t << j))
                {
                    push('1');
                }
                else push('0');
            }
            output();


        for (int i = 0;i < num;i++)
        {

            res *= 10;
            res += p[i] - '0';
            if (p[i + 1] == '\0')
            {
                if (i % 3 == 0)
                {
                    for (int j = 0;j < 4;j++)
                    {
                        if (res & (t << j))
                        {
                            push('1');
                        }
                        else push('0');
                    }
                    output();
                }
                else if (i % 3 == 1)
                {
                    for (int j = 0;j < 7;j++)
                    {
                        if (res & (t << j))
                        {
                            push('1');
                        }
                        else push('0');
                    }
                    output();
                }
            }

            if (i % 3 == 2)
            {
                for (int j = 0;j < 10;j++)
                {
                    if (res & (t << j))
                    {
                        push('1');
                    }
                    else push('0');
                }
                output();
                res = 0;
            }
        }
    
    

    return 0;
}
