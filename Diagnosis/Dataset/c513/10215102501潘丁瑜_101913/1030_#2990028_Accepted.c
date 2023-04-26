#include <stdio.h>
#include <stdlib.h>
struct number
{
    char string[50];
};

int cmp(const void *a,const void *b)
{
    struct number *s1=(struct number*)a;
    struct number*s2=(struct number*)b;
    char c= s1->string[0];
    char d= s2->string[0];
    long long int m=atoll(s1->string);
    long long int n=atoll(s2->string);
    if(s1->string[0] == '-')
        c = s1->string[1];
    if(s2->string[0] == '-')
        d= s2->string[1];
    if(c != d )
        return d-c;
    else
    {
        if(m > n) return 1;
        else if(m<n) return -1;
        else return 0;
    }
}
int main()
{
    int T,i;
    int N,j;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d\n",&N);
        struct number a[20000]={0};
        for(j=0;j<N;j++)
            scanf("%s",a[j].string);
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<N-1;j++)
        {
            printf("%s ",a[j].string);
        }
        printf("%s\n",a[j].string);
    }
    return 0;
}
