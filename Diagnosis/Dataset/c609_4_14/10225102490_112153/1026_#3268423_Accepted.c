#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char s[21];
    int unq;
} String;

int cmp(String*a, String*b)
{
    if (a->unq != b->unq) return b->unq - a->unq;
    else return strcmp(a->s,b->s);
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int I = 0; I < T; I++)
    {
        int n;
        scanf("%d",&n);
        String*a = (String*)malloc(sizeof(String) * n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s",a[i].s);
            a[i].unq = 0;
            int hash[128] = {0};
            for (int j = 0; j < strlen(a[i].s); j++)
            {
                hash[a[i].s[j]]++;
            }
            for (int j = 0; j < 128; j++)
            {
                if (hash[j] != 0) a[i].unq++;
            }
        }
        qsort(a,n,sizeof(String),cmp);
        printf("case #%d:\n",I);
        for (int i = 0; i < n; i++)
        {
            printf("%s\n",a[i].s);
        }
    }
}