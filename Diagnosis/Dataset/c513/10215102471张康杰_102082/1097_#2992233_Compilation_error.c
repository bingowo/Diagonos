#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char input[81];
    while(scanf("%s",input) != EOF)
    {
        int max = input[0],pos = 0;
        int len = strlen(input);
        int i,j,table[len][len] = {{0}};
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
        int line = 0;
        table[line][pos] = input[pos];
        for(i = pos - 1;i >= 0;i--)
        {
            if(input[i] == input[pos])
                table[0][pos] == input[i];
            if(input[i] < input[i + 1])
            {
                line++;
                table[line][i] = input[i];
            }
            else if(input[i] == input[i + 1])
            {
                table[line][i] = input[i];
            }
            else
            {
                line--;
                table[line][i] = input[i];
            }
        }
        for(i = 0;i < len;i++)
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