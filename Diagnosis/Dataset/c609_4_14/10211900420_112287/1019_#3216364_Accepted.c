#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int len(int x)
{
    int sum=0;
    while(x!=0)
    {
        sum++;
        x=x/10;
    }
    return sum;

}
int cmp1(const void* a,const void* b)
{
    int suma,sumb,c,d,e;
    c=*(int*)a;
    d=*(int*)b;
    suma=len(c);
    sumb=len(d);
    if(suma>sumb) return -1;
    else if(suma<sumb) return 1;
    else return c-d;
}
int main()
{
    int sum,*a,i,n;
    n=0;
    a=(int*)malloc(1000000*sizeof(int));
    while(scanf("%d",&a[n])!=EOF)
    {
        n++;
    }
    qsort(a,n,sizeof(int),cmp1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    free(a);
    return 0;
}
