#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    if((*(int*)a)>(*(int*)b)) return 1;
    else return -1;
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
       int n,a[1001],b[1001],m = 0,p;
       scanf("%d",&n);
       for(j = 0;j<n;j++)
            scanf("%d",&a[j]);
       for(j = 0;j<n;j++)
            scanf("%d",&b[j]);
        qsort(a,n,sizeof(int),cmp);
        qsort(b,n,sizeof(int),cmp);
       for(j = 0,p = n-1;j<n;j++,p--)
       {
           m = m+ a[j]*b[p];
       }
       printf("case #%d:\n%d\n",i,m);

    }
    return 0;
}
