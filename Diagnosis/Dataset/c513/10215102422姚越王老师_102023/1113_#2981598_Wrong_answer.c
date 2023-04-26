#include<stdio.h>
#define C 101
#define L 32
void add(int* a,const int* b)
{
    int i,carry=0,tmp;
    for(i=L-1;i>-1;--i)
    {
        tmp=a[i]+b[i];
        a[i]=tmp%10;
        carry=tmp/10;
    }
}
int main()
{
    int k,n,i,j;scanf("%d%d",&k,&n);
    int** a=(int**)malloc(sizeof(int*)*C);
    for(i=0;i<2;++i)
    {
        int* b=(int*)malloc(sizeof(int)*L);
        memset(b,0,4*L);
        if(!i)a[i]=b;
        else {b[L-1]=1;a[i]=b;}
    }
    for(i=2;i<n;++i)
    {
        int *c=(int*)malloc(sizeof(int)*L);memset(c,0,4*L);
        if(i<k)
        {
            for(j=0;j<i;++j)add(c,a[j]);
            a[i]=c;
        }
        else
        {
            for(j=i-k;j<i;++j)add(c,a[j]);
            a[i]=c;
        }
    }
    for(i=0;i<L;++i)if(a[n-1][i])break;
    for(i;i<L;++i)printf("%d",a[n-1][i]);
    for(i=0;i<n;++i)free(a[i]);
    free(a);
    return 0;
}