#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int Num(long long int n)
{
    long long int i = 0;
    while(n!=0)
    {
        i++;
        n = n&(n-1);
    }
    return i;
}
long long int cmp(const void*a,const void*b)
{
    long long int *p1 = a;
    long long int *p2 = b;
    if(Num(*p1)==Num(*p2)) return *p1-*p2;
    else return (Num(*p2)-Num(*p1));
}

int main()
{
    int n,m,i,j,k= 0;
    scanf("%d",&n);
    int s[n];
    long long int a[10000];
    long long int*p = a;
    for(i = 0;i<n;i++)
    {
        scanf("%d",&s[i]);
        for(j = 0;j<s[i];j++,k++)
        {
            scanf("%lld",&a[k]);
        }
    }
    for(i = 0;i<n;i++)
    {
        qsort(p,s[i],sizeof(a[0]),cmp);
        p = p+s[i];
    }

    for(i = 0,k = 0;i<n;i++)
    {
        printf("case #%d:\n",i);
        for(j = 0;j<s[i];j++,k++)
        {
            printf("%d ",a[k]);
        }
        printf("\n");
    }
    return 0;
}
