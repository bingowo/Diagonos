#include <stdio.h>
#include <stdlib.h>

int cmpA(const void *a,const void *b)
{
    int m=*((int *)a);
    int n=*((int *)b);
    return m-n;
}

int cmpD(const void *a,const void *b)
{
    int m=*((int *)a);
    int n=*((int *)b);
    return n-m;
}

int main()
{
    char way;
    scanf("%c",&way);
    int s[101];
    int *p;
    p=(int *)malloc(100*sizeof(int));
    int i=0;
    while(scanf("%d",&s[i])!=EOF)i++;
    p=s;
    if(way=='A')qsort(p,i,sizeof(int),cmpA);
    if(way=='D')qsort(p,i,sizeof(int),cmpD);
    for(int j=0;j<i;j++)
    {
        while(s[j]==s[j+1])j++;
        printf("%d",s[j]);
        if(j!=i-1)printf(" ");
    }
    free(p);
    return 0;
}
