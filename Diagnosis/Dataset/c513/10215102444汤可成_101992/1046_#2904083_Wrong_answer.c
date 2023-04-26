#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valid(char* s)
{
    static char* w[] = {"the", "a", "an", "of", "for", "and"};
    int i = 0;
    for(i = 0 ; i<6; i++)
    {
        if(strcmp(s, w[i]) == 0) return 0;
    }
    return 1;
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    int i = 0;
    for(i = 0; i<T; i++)
    {
        printf("case #%d:\n", i);
        char s[101][30] = {0};
        char c = 0;
        int i = 0;
        do
        {
            scanf("%s", &s[i++]);
        }
        while((c = getchar())!='\n');
        int j = 0;
        int num = 0;
        for(j = 0; j<i; j++)
        {
            if(valid(s[j])) num++;
        }
        printf("%d\n", num);
    }
    return 0;
}
