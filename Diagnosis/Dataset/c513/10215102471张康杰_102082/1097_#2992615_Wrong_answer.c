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
        int table[len][len];
        memset(table,0,sizeof(int) * len * len);
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
        int line1 = 0,line2 = 0;
        table[line1][pos] = input[pos];
        for(i = pos - 1;i >= 0;i--)
        {
            if(input[i] == input[pos])
                table[0][pos] == input[i];
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
        }
        for(i = pos + 1;i < len;i++)
        {
            if(input[i] == input[pos])
                table[0][pos] == input[i];
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
        }
        int line;
        if(line1 > line2)
            line = line1;
        else
            line = line2;
        for(i = 0;i < line + 1;i++)
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