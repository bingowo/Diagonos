#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count(char*s)
{
    int a[26];
    int sum = 0;
    for(int i = 0;i < 26;i++)
    {
        a[i] = -1;
    }
    int len = strlen(s);
    for(int i = 0;i < len; i++)
    {
        a[s[i]- 'A'] = 1;
    }
    for(int i = 0;i < 26;i++)
    {
        if(a[i] > 0)
        {
            sum++;
        }
    }
    return sum;
}

int cmp(const void* a, const void* b)
{
    char* A = (char*)a;
    char* B = (char*)b;
    if(count(A) != count(B))
    {
        return count(A) < count(B);
    }
    else
    {
        return strcmp(A,B);
    }
}

int main()
{
    int T;
    int a;
    char s[1000][101];
    scanf("%d",&T);
    for(int i = 0; i < T;i++)
    {
        scanf("%d",&a);
        for(int j = 0;j < a;j++)
        {
            scanf("%s",s[j]);
        }
        qsort(s,a,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int j = 0; j < a; j++)
        {
            printf("%s\n",s[j]);
        }

    }
}
