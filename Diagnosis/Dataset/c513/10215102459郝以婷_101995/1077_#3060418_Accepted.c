#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int a[501],b[501],A,B,i,j,ret[501],k=0,n=0;
    scanf("%d",&A);
    for(i=0;i<A;i++)
        scanf("%d",&a[i]);
    scanf("%d",&B);
    for(i=0;i<B;i++)
        scanf("%d",&b[i]);
    for(i=0;i<A;i++)
    {
        for(j=0;j<B;j++)
        {
            if(a[i]==b[j])
            {
                ret[k++]=a[i];
                b[j]=-1;
                n++;
            }
        }
    }
    qsort(b,B,sizeof(int),cmp);
    for(i=n;i<B;i++)
        ret[k++]=b[i];
    for(i=0;i<k;i++)
        printf("%d ",ret[i]);
    return 0;
}
