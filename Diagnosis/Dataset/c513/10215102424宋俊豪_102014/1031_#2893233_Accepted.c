#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int cmp1(const void *a,const void *b)
{  int x=*(int*)a;int y=*(int*)b;
    return x-y;
}
int cmp2(const void *a,const void *b)
{  int x=*(int*)a;int y=*(int*)b;
    return y-x;
}
int main()
{
    int n,n1;;
    int a[1001],b[1001];
    scanf("%d",&n);
    long long int num;
    for (int i=0; i<n; i++)
    {   num=0;
        scanf("%d",&n1);
        for (int j=0; j<n1; j++)
        {
            a[j]=0;
            b[j]=0;
            scanf("%d",&a[j]);
        }
        for (int j=0; j<n1; j++)
        {
            scanf("%d",&b[j]);
        }
        qsort(a,n1,sizeof(int),cmp1);
        qsort(b,n1,sizeof(int),cmp2);
        for(int q=0;q<n1;q++)
            num=num+a[q]*b[q];
        printf("case #%d:\n",i);
        printf("%lld\n",num);
    }
    return 0;
}
