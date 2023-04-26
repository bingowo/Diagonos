#include<stdio.h>
#include<stdlib.h>

int digit(int a)
{
    int res;
    for(res=0;a!=0;res++)
    {
        a/10;
    }
    return res;
}
int cmp(const void*p1,const void*p2)
{
    int *a=(int*)p1;
    int *b=(int*)p2;
    int aa=*a;
    int bb=*b;
    aa=digit(aa);
    bb=digit(bb);
    if(aa!=bb) return (bb-aa);
    else return (*a-*b);
}

int main()
{
    int a[1000000];
    int i;
    for(i=0;scanf("%d",&a[i])!=EOF;i++);
    qsort(a,i,sizeof(a[0]),cmp);
    for(int j=0;j<i;j++)
    {
        printf("%d ",a[j]);
    }
    return 0;
}