#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number(char* s)
{
    int sum = 0;
    int flag = 0;
    int len = strlen(s);
    int i = 0;
    for(i = 0; i<len; i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            sum = 10*sum +s[i] - '0';
            flag = 1;
        }
    }
    if(flag) sum = -1;
    return sum;
}

int strnumcmp(const void* pa, const void* pb)
{
    char* a = (char*)pa;
    char* b = (char*)pb;
    int n1 = number(a);
    int n2 = number(b);
    if(n1 != n2) return n1 - n2;
    else
        return strcmp(a, b);
}

int main()
{
    char s[101][31] = {0};
    int i = 0;
    while(scanf("%s",s[i]) != EOF)
    {
        i++;
    }
    qsort(s, i, sizeof(s[0]), strnumcmp);
    int j = 0;
    for(j = 0; j<i; j++)
    {
        printf("%s ",s[j]);
    }
    return 0;
}
