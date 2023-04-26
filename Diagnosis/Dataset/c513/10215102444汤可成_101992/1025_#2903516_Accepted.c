#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num(char* s)
{
    char alphabet[26] = {0};
    int len = 0;
    int i = 0;
    while(*(s+i)!=0)
    {
        if(alphabet[*(s+i)-'A'] == 0)
        {
            alphabet[*(s+i)-'A'] = 1;
            len++;
        }
        i++;
    }
    return len;
}

int cmp(const void* pa, const void* pb)
{
    char* a = (char* )pa;
    char* b = (char* )pb;
    if(num(a) != num(b)) return num(b) - num(a);
    else return strcmp(a, b);
}

int main()
{
    int T = 0;
    int i = 0;
    scanf("%d", &T);
    for(i = 0; i<T; i++)
    {
        printf("case #%d:\n", i);
        int n = 0;
        char s[101][21] = {0};
        scanf("%d", &n);
        int j = 0;
        for(j = 0; j<n; j++)
        {
            scanf("%s", s[j]);
        }
        qsort(s, n, sizeof(s[0]), cmp);
        for(j = 0; j<n; j++)
        {
            printf("%s\n", s[j]);
        }
    }
    return 0;
}
