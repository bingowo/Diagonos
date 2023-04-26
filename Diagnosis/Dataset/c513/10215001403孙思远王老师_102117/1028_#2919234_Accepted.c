#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int cmp2(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}

int main()
{
    char ad;
    int x[100],y[100],n=0,i,j;
    scanf("%c",&ad);
    while(scanf("%d",&x[n])!=EOF)
        n++;
    if(ad=='A')
        qsort(x,n,sizeof(x[0]),cmp1);
    else if(ad=='D')
        qsort(x,n,sizeof(x[0]),cmp2);
    int be=0;
    for(i=0,j=0;i<n;i++)
    {
        if(be!=x[i])
        {
            y[j]=x[i];
            j++;
        }
        be=x[i];
    }
    for(i=0;i<j;i++)
    {
        printf("%d",y[i]);
        if(i<j-1)
            printf(" ");
    }
    return 0;
}
