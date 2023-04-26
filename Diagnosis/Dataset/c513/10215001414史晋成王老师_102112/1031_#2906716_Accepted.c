#include<stdio.h>
#include<stdlib.h>
int cmp1(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}
int cmp2(const void* a,const void* b)
{ 
    return *(int *)a-*(int*)b;
}
int main()
{int T; int i,n,a[10001],b[10000],j,sum;
scanf("%d",&T);
for(i=0;i<T;i++)
{scanf("%d",&n);
 for(j=0;j<n;j++)
 scanf("%d",&a[j]);
 for(j=0;j<n;j++)
 scanf("%d",&b[j]);
 qsort(a,n,sizeof(a[0]),cmp1);
 qsort(b,n,sizeof(b[0]),cmp2);
 sum=0;
 for(j=0;j<n;j++)
 sum+=a[j]*b[j];
 printf("case #%d:\n",i);
 printf("%d\n",sum);
}

}
