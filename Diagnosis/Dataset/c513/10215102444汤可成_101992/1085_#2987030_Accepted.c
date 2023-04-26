#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sub(char* a, char* b)
{
    for(int j = 500; j>=0; j--)
    {
        if(b[j] == 0) b[j] = '0';
        if(a[j] == 0) a[j] = '0';
        if(a[j]>=b[j]) a[j] = a[j] - b[j];
        else
        {
            a[j] = 10 + a[j] - b[j];
            a[j-1]--;
        }
    }
}

int main()
{
    char s1[501] = {0}, s2[501] = {0};
    while(scanf("%s %s", s1, s2) != EOF)
    {
        char a1[501] = {0}, a2[501] = {0};
        int len1 = strlen(s1), len2 = strlen(s2);
        for(int i = 0; i<len1; i++)
        {
            a1[500-i] = s1[len1-1-i];
        }
        for(int i = 0; i<len2; i++)
        {
            a2[500-i] = s2[len2-1-i];
        }
        int i = 0;
        if(strcmp(s1,s2)>0)
        {
            sub(a1,a2);
            while(a1[i] == 0) i++;
            for(; i<=500; i++)
            {
                printf("%d", a1[i]);
            }
            printf("\n");
        }
        else if(strcmp(s1,s2)<0)
        {
            sub(a2,a1);
            while(a2[i] == 0) i++;
            printf("-");
            for(; i<=500; i++)
            {
                printf("%d", a2[i]);
            }
            printf("\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
