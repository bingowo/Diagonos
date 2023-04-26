#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp1(const void*_a,const void*_b)
{
    int* a=(int*)_a;
    int* b=(int*)_b;
    return (*a - *b);
}
int cmp2(const void*_a,const void*_b)
{
    int* a=(int*)_a;
    int* b=(int*)_b;
    return (*b - *a);
}
int a[1010];
int main()
{
    char c;
    scanf("%c",&c);
    int x;
    int m=0,n=0;
    while(scanf("%d",&x)!=EOF)
    {
        if(a[x]==0)
        {
            a[x]=x;
            if(x>=m) m=x;
            n++;
        }

    }
    if(c=='A')  qsort(a+1,m,sizeof(a[0]),cmp1);
    else if(c=='D')
    {
        qsort(a+1,m,sizeof(a[0]),cmp2);
        m=n;
    }
    for(int i=1;i<m;i++)
    {
       if(a[i]!=0) printf("%d ",a[i]);
    }
    printf("%d",a[m]);
    return 0;
}
