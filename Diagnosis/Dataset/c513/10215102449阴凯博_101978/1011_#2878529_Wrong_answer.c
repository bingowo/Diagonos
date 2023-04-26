#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int r;
    int f;
} NUM;

NUM mul(NUM a,NUM b)
{
    NUM n;
    n.f=a.r*b.f+b.r*a.f;
    n.r=a.r*b.r-a.f*b.f;
    return n;
}

NUM pwr(int a)
{
    NUM n,m;
    m.f=1; m.r=-1;
    n.f=0; n.r=1;
    int i;
    for (i=0;i<a;i++)
        n=mul(n,m);
    return n;
}




int main()
{
    int m,i,j;
    int arr[100]={0};
    scanf("%x",&m);
    for (i=0;m>>i;i++)
    {
        arr[i]=m>>i&1;
    }
    NUM n;
    n.r=0; n.f=0;
    for (j=0;j<i;j++)
    {
        if (arr[j]==1)
        {
            n.r+=pwr(j).r;
            n.f+=pwr(j).f;
        }
    }
    if (n.f==0 && n.r==0) printf("%d\n",0);
    else if (n.f==0) printf("%d\n",n.r);
    else if (n.f>0)
        {if (n.f==1) printf("%d+i\n",n.r);
        else printf("%d+%di\n",n.r,n.f);}
    else
        {if (n.f==-1) printf("%d-i\n",n.r);
         else printf("%d%di\n",n.r,n.f);}
    return 0;
}
