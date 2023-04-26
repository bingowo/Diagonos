#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int cmp(const void *a,const void *b)
{
    int x_1=*(int*)a;
    int ast=0;
    while(x_1)
    {
        ast++;
        x_1&=(x_1-1);
    }
    int x_2=*(int *)b;
    int asn=0;
    while(x_2)
    {
        asn++;
        x_2&=(x_2-1);

    }
    if(ast==asn) return *(int*)a-*(int*)b;
    else return asn-ast;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    int result[11][10000];
    int t[11];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t[i]);
        int s[66];
        for(int j=0;j<t[i];j++)
        {
            scanf("%d",&s[j]);
        }
        qsort(s,t[i],sizeof(int),cmp);
        for(int u=0;u<t[i];u++)
        {
            result[i][u]=s[u];
        }


    }
    for(int i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        for(int j=0;j<t[i];j++)
        {
            printf("%d%c",result[i][j],j==t[i]-1?'\n':' ');
        }
    }
    return 0;
}

