#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[101];
    char s2[205];
    scanf("%s",s1);
    int i;
    int x = 0;
    int len = strlen(s1);
    for(i = 0;i < len;i++)
    {
        if(s1[i] < s1[i + 1])
        {
            s2[x++] = s1[i];
            s2[x++] = s1[i];
        }
        else if(s1[i] > s1[i + 1])
        {
            s2[x++] = s1[i];
        }
        else
        {
            int j;
            for(j = i;j < len;j++)
            {
                if(s1[j] != s1[j+1])
                    break;
            }
            if(s1[j] < s1[j + 1])
            {
                for(int c = 0;c < 2*(j + 1 - i);c++)
                    s2[x++] = s1[j];
            }
            else
            {
                for(int c = 0;c < (j - i + 1);c++)
                    s2[x++] = s1[j];
            }
            i = j;

        }


    }
    s2[x] = '\0';
    printf("%s",s2);
    return 0;
}
