#include <stdio.h>
#include <stdlib.h>
int cmp_up(const void*a,const void*b)
{
    return *((int *)a)-*((int *)b);
}
int cmp_down(const void*a,const void*b)
{
    return *((int *)b)-*((int *)a);
}

int main()
{
    char c,d;
    int m,n;//A/D,digit,中间量
    int b[1000]={0};
    int a[101]={0};
    int j=0;
    scanf("%c",&c);
    d=getchar();
    while(scanf("%d",&m)!=EOF)
    {
        if(b[m]==0)
        {
            b[m]=1;
            a[j]=m;
            j++;
        }
    }//quchong
    n=j-1;
    if(c=='A')
    {
        qsort(a,n,sizeof(a[0]),cmp_up);
        for(j=0;j<n;j++)
        {
            printf("%d",a[j]);
        }
    }
    else
    {

        qsort(a,n,sizeof(a[0]),cmp_down);
        for(j=0;j<n;j++)
        {
            printf("%d",a[j]);
        }
    }
    return 0;

}
