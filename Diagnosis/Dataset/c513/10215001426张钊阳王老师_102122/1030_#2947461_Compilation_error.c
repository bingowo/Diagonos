#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int cmp(const void *a1,const void *b1);
    int hei(const int m);
    int m;
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
        int n,i=0;
        scanf("%d",&n);
        long long int a[10000];
        for(i=0;i<n;i++) scanf("%lld",&a[i]);
        qsort(a,n,sizeof(a[0]),cmp);

        printf("case #%d:\n",z);
        for(int j=0;j<n;j++)
        {
            if(j==n) printf("%d",a[j]);
            else printf("%d ",a[j]);
        }
        printf("\n");
    }
return 0;
}

int hei(const long long int m)
{
    int n=m;
    if(n<0) n=-n;
    while(n/10>=1)
    {
        n=n/10;
    }
    return n;
}

int cmp(const void *a1,const void *b1)
{
    int hei(const int m);
    long long int a=*(int *)a1;
    long long int b=*(int *)b1;
    if(hei(a)!=hei(b)) return hei(b)-hei(a);
    else if(hei(a)==hei(b)) return a-b;
}