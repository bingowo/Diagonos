#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cun[1100];

int cmp(const void*p,const void*q)
{
    int pp=*((int*)p);
    int qq=*((int*)q);

    if(cun[pp]>cun[qq]) return 1;
    else if(cun[pp]<cun[qq]) return -1;
    else
    {
         return pp-qq;
    }

}

int main()
{
    int m,n,i,j;
    int a[510],b[510];
    scanf("%d",&m);
    
    for(i=0;i<1100;i++)
    {
        cun[i]=1200;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<m;i++)
    {
        cun[a[i]]=i;
    }
    qsort(b,n,sizeof(int),cmp);
    /*for(i=0;i<10;i++)
    {
        printf("test: cun[%d]=%d\n",i,cun[i]);
    }*/
    for(i=0;i<n-1;i++)
    {
        printf("%d ",b[i]);
    }
    printf("%d",b[i]);
}
