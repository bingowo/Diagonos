#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b)
{
    char* pa = (char*)a;
    char* pb = (char*)b;
    return strcmp(pa, pb);
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    getchar();
    int i = 0;
    for(i = 0; i<T; i++)
    {
        printf("case #%d:\n", i);
        char word[501][55] = {0};
        int m = 0;
        int n = 0;
        char c = 0;
        int flag = 0;
        while((c = getchar())!='\n')
        {
            if(c != ' ' && c != ',' && c != '.' && c != '!' && c != '?')
            {
                word[m][n++] = c;
                flag = 1;
            }
            else
            {
                if(flag)
                {
                    m++;
                    flag = 0;
                }
                n = 0;
            }
        }
        qsort(word, m, sizeof(word[0]), cmp);
        int j = 0;
        m = 0;
        n = 0;
        flag = 0;
        while(word[j][0] != 0)
        {
            if(strcmp(word[j], word[j+1]) && flag == 0)
            {
                flag = 0;
                printf("%s ", word[j]);
                j++;
            }
            else
            {
                if(flag)
                {
                    j++;
                    flag = 0;
                }
                else
                {
                    flag = 1;
                    printf("%s ", word[j]);
                    j++;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
