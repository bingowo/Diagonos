#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cmp(const void *a1,const void *b1);
    int m;
    scanf("%d",&m);
    int *s=(int*)malloc(sizeof(int)*m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",s+i);
    }
    qsort(s,m,sizeof(int),cmp);
    int half=m/2;
    int sum=0;
    for(int u=0;u<m;)
    {
        sum+=s[u+1]-s[u];
        u+=2;
    }
    printf("%d",sum);
    return 0;
}

int cmp(const void *a1,const void *b1)
{
    int a=*(int *)a1;
    int b=*(int *)b1;
    return a-b;
}
