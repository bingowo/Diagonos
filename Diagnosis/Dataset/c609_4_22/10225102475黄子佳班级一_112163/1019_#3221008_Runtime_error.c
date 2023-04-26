#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    int d1,d2,d11,d22;
    d1=*((int *)a);
    d2=*((int *)b);
    d11=d1;
    d22=d2;
    int t=0,q=0;
    do
    {
        d1/=10;
        t++;
    }while(d1!=0);
    do
    {
        d2/=10;
        q++;
    }while(d2!=0);
    if(t==q)return d11-d22;
    else return q-t;
}

int main()
{
    int a[100001];
    int i=0;
    do
    {
        scanf("%d",&a[i]);
        i++;
    }
    while(getchar()!='\n');
    int *p=a;
    qsort(p,i,sizeof(int),cmp);
    for(int j=0;j<i;j++)
        printf("%d ",*(p+j));
    return 0;
}
