#include <stdio.h>
#include <stdlib.h>
int cmp1(const void*a,const void *b)
{
    int *a1 = (int*)a,*b1=(int *)b;
    return *a1 - *b1;
}
int cmp2(const void*a,const void *b)
{
    int *a2 = (int*)a,*b2=(int *)b;
    return *b2 - *a2;
}


int main() {

    int T;
    scanf("%d",&T);
    for(int i=0;i <T;i++)
    {
        int n;
        scanf("%d",&n);
        int a[n],b[n];
        for(int j = 0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        for(int j = 0;j<n;j++)
        {
            scanf("%d",&b[j]);
        }
        qsort(a,n,sizeof (a[0]),cmp1);
        qsort(b,n,sizeof (b[0]),cmp2);
        int sum=0;
        for(int k = 0;k<n;k++)
            sum+= a[k]*b[k];
        printf("case #%d:\n",i);
        printf("%d\n",sum);
    }
    return 0;
}
