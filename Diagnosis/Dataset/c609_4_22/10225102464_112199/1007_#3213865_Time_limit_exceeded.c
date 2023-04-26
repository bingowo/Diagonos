#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int cmp(const void *a,const void *b)
{
    long int x_1=*(int*)a;
    long int ast=0;
    while(x_1)
    {
        ast++;
        x_1&=(x_1-1);
    }
    long int x_2=*(int *)b;
    long int asn=0;
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
    long int result[11][10000];
    int t[10000];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t[i]);
        long int s[66];
        for(int j=0;j<t[i];j++)
        {
            scanf("%ld",&s[j]);
        }
        qsort(s,t[i],sizeof(long int),cmp);
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
            printf("%ld%c",result[i][j],j==t[i]-1?'\n':' ');
        }
    }
    return 0;
}