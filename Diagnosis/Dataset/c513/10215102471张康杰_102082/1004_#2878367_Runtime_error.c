#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char table[] = "0123456789abcdef";
    char str[13];
    while(scanf("%s",str) != EOF)
    {
        int flag = 0;
        char*pt = str;
        while(*pt)
        {
            if(*pt == '.')
            {
                flag = 1;
                break;
            }
            pt++;
        }
        if(flag == 0)
        {
            int length = strlen(str),i,j,sum = 0;
            int bi_input[32];
            char ox_input[15];
            ox_input[11] = '\0';
            ox_input[0] = ox_input[0] = ox_input[1] = ox_input[2] = '\0';
            for(i=0;i<length;i++)
            {
                sum = sum*10 + (str[i] - '0');
            }
            for(j = 0;j < 32;j++)
            {
                bi_input[31 - j] = sum&(1<<j);
            }
            int count1 = 0,count2 = 0;
            int*pt1 = bi_input,sum1 = 0;
            char*pt2 = ox_input  + 3;
            while(*pt2)
            {
                for(count2 = 0;count2 < 2;count2++)
                {

                    for(count1 = 0;count1 < 4;count1++)
                    {
                        sum1 = sum1*2 + *pt1;
                        pt1++;
                    }
                    *pt2 = table[sum1];
                    pt2++;
                }
                *pt2 = ' ';
                pt2++;

            }
            *pt2 = ox_input[12];
            while(*pt2)
            {
                printf("%c%c",*pt2,*(pt2++));
                putchar(' ');
                pt2 -= 3;
            }
        }
        else
        {
            int length = strlen(str),i,j,sum = 0;
            int bi_input[64];
            char ox_input[27];
            ox_input[26] = '\0';
            ox_input[0] = ox_input[0] = ox_input[1] = ox_input[2] = '\0';
            for(i=0;i<length;i++)
            {
                sum = sum*10 + (str[i] - '0');
            }
            for(j = 0;j < 32;j++)
            {
                bi_input[63 - j] = sum&(1<<j);
            }
            int count1 = 0,count2 = 0;
            int*pt1 = bi_input,sum1 = 0;
            char*pt2 = ox_input + 3;
            while(*pt2)
            {
                for(count2 = 0;count2 < 2;count2++)
                {

                    for(count1 = 0;count1 < 4;count1++)
                    {
                        sum1 = sum1*2 + *pt1;
                        pt1++;
                    }
                    *pt2 = table[sum1];
                    pt2++;
                }
                *pt2 = ' ';
                pt2++;

            }
            *pt2 = ox_input[24];
            while(*pt2)
            {
                printf("%c%c",*pt2,*(pt2++));
                putchar(' ');
                pt2 -= 3;
            }
        }

    }

    return 0;
}