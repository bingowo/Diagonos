#include <stdio.h>
#include <stdlib.h>

int cmp(void*a,void*b)
{
    int m=*(int*)a;
    int n=*(int*)b;
    if(cd(m)==cd(n)) return m>n?1:-1;
    else return cd(m)>cd(n)?-1:1;

}

int cd(int a)
{
    int d=0;
    if(a<0)
    {
        a=-a;

    }
     do
    {
        a/=10;
        d++;
    }
    while(a!=0);
    return d;
}
int main()
{
    int a[100000];
    int i=0;int j=0;
    while((scanf("%d",&a[i]))==1)
    {
        i++;
    }
    qsort(a,i,sizeof(a[0]),cmp);
    for(j=0;j<i;j++)
    {
        printf("%d ",a[j]);
    }
    return 0;
}