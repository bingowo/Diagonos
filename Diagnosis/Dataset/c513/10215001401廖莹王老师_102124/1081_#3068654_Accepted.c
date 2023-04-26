#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int m[1000];
    int d
}shuzu;
shuzu p;
void jisuan(int m[1000],int a)
{
    int i,j,l=0,k=0;
    for(i=0;i<p.d;i++)
    {
        l=m[i]*a+k;
        m[i]=l%10;
        k=l/10;
    }
    if(k>0){m[i]=k;p.d++;}
}
void zhixing(int h)
{
    int a,n,i;
    memset(p.m,0,sizeof(p.m));
    scanf("%d %d",&a,&n);
    p.m[0]=a;p.d=1;
    printf("case #%d:\n",h);
    if(n==0)printf("1\n");
    else
    {
     for(i=1;i<n;i++)
    {
        jisuan(p.m,a);
    }
    for(i=p.d-1;i>=0;i--)printf("%d",p.m[i]);
    printf("\n");
    }
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)zhixing(h);
    return 0;
}
