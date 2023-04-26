#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int a[500],m;
int cmp1(const void*a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int Turn(int p)
{
    int i;
    for(i = 0;i<m;i++)
    {
        if(p==a[i])return i;
    }
}
int cmp2(const void*a,const void*b)
{
    int p1 = *(int*)a,p2 = *(int*)b;
    int x1 = Turn(p1),x2 = Turn(p2);
    return x1-x2;
}
int main()
{
    int n,b[500],c[500],d[500],i,j,k,l,num;
    scanf("%d",&m);
    for(i = 0;i<m;i++)scanf("%d",&a[i]);
    scanf("%d",&n);
    for(i = 0;i<n;i++)scanf("%d",&b[i]);
    for(j = 0,k = 0,l = 0;j<n;j++)
    {
        for(i = 0,num = 0;i<m;i++)
        {
            if(b[j] == a[i])
            {
                c[k]=b[j];
                k++;
                break;
        }
        num++;
    }
    if(num==m)
    {d[l] = b[j];
    l++;}
    }
    qsort(d,l,sizeof(d[0]),cmp1);
    qsort(c,k,sizeof(c[0]),cmp2);
    for(i = 0;i<k;i++)printf("%d ",c[i]);
    for(i = 0;i<l;i++)printf("%d ",d[i]);
    return 0;
}
