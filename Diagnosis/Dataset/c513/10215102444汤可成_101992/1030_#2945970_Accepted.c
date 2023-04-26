#include <stdio.h>
#include <stdlib.h>

int cmp(const void*pa, const void*pb)
{
    char* a = (char*)pa;
    char* b = (char*)pb;
    if(*a == '-') a++;
    if(*b == '-') b++;
    if(*a != *b) return *b-*a;
    else
    {
        a = (char*)pa;
        b = (char*)pb;
        long long num1 = 0;
        long long num2 = 0;
        int flag = 1;
        while(*a != '\0')
        {
            if(*a == '-')
            {
                flag = -1;
                a++;
            }
            else
            {
                num1 = num1*10 + *a - '0';
                a++;
            }
        }
        num1 = num1*flag;
        flag = 1;
        while(*b != '\0')
        {
            if(*b == '-')
            {
                flag = -1;
                b++;
            }
            else
            {
                num2 = num2*10 + *b - '0';
                b++;
            }
        }
        num2 = num2*flag;
        if(num1>num2)return 1;
        else return -1;
    }
}

int main()
{
    int T = 0;
    int i = 0;
    scanf("%d", &T);
    for(i = 0; i<T; i++)
    {
        int n = 0;
        scanf("%d", &n);
        char s[10001][20] = {0};
        for(int j = 0; j<n; j++)
        {
            scanf("%s", s[j]);
        }
        qsort(s, n, sizeof(s[0]), cmp);
        printf("case #%d:\n", i);
        for(int j = 0; j<n; j++)
        {
            printf("%s ",s[j]);
        }
        printf("\n");
    }
    return 0;
}
