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
    int m=0;
    while(scanf("%d",&x)!=EOF)
    {
        if(a[x]==0)
        {
            a[x]=x;
            if(x>=m) m=x;
        }
    }
    if(c=='A')  qsort(a,m+1,sizeof(a[0]),cmp1);
    else if(c=='D')  qsort(a,m+1,sizeof(a[0]),cmp2);
    for(int i=0;i<m;i++)
    {
        if(a[i]!=0) printf("%d ",a[i]);
    }
    printf("%d",a[m]);
    return 0;
}
