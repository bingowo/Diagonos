#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char input[81];
    char ch;
    while(scanf("%s",input))
    {
        if((ch = getchar()) == EOF)
            break;
        int max = input[0],pos = 0;
        int len = strlen(input);
        int i,j;
        int table[2 * len + 1][len];
        memset(table,0,sizeof(int) * (2 * len + 1) * len);
        for(i = 1;i < len;i++)
        {
            if(input[i] > max)
            {
                max = input[i];
                pos = i;
            }
            else
                continue;
        }
        int line1 = len,line2 = len;
        int line_max = len,line_min = len;
        table[line1][pos] = input[pos];
        for(i = pos - 1;i >= 0;i--)
        {
            if(input[i] < input[i + 1])
            {
                line1++;
                table[line1][i] = input[i];
            }
            else if(input[i] == input[i + 1])
            {
                table[line1][i] = input[i];
            }
            else
            {
                line1--;
                table[line1][i] = input[i];
            }
            if(line1 > line_max)
                line_max = line1;
            else if(line1 < line_min)
                line_min = line1;
        }
        for(i = pos + 1;i < len;i++)
        {
            if(input[i] < input[i - 1])
            {
                line2++;
                table[line2][i] = input[i];
            }
            else if(input[i] == input[i - 1])
            {
                table[line2][i] = input[i];
            }
            else
            {
                line2--;
                table[line2][i] = input[i];
            }
            if(line2 > line_max)
                line_max = line2;
            else if(line2 < line_min)
                line_min = line2;
        }

        for(i = line_min;i <= line_max;i++)
        {
            for(j = 0;j < len;j++)
            {
                if(table[i][j] == 0)
                    putchar(' ');
                else
                {
                    printf("%c",table[i][j]);
                }
            }
            putchar('\n');
        }
    }
    return 0;
}