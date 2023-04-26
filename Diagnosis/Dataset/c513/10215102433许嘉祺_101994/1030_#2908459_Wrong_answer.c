#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void *a,const void*b)
{
    char*p1=*(char(*)[21])a,*p2=*(char(*)[21])b;
    int a1,b1;
    int i=0;
    while (p1[i]<'0'||p1[i]>'9') i++;
    a1=p1[i]-'0';
    i=0;
    while (p2[i]<'0'||p2[i]>'9') i++;
    b1=p2[i]-'0';
    if (b1==a1)
    {
        long long a2=atol(p1),b2=(p2);
        if (a2>b2)return 1;
        else return -1;
    }
    else return b1-a1;
}


int main()
{
    int t;
    scanf("%d",&t);
    int n;
    char s[10000][21];
    for (int i=0; i<t; i++)
    {
        scanf("%d",&n);
        for (int j=0; j<n; j++)
            scanf("%s",s[j]);
        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for (int j=0; j<n; j++)
            printf("%s%c",s[j],j==n-1?'\n':' ');
    }

    return 0;
}