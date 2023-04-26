#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    long long k;
}shu;
shu p[50];
long long zuofa(int n)
{
    p[0].k=0;p[1].k=1;p[2].k=2;p[3].k=4;p[4].k=8;
    if(n>4)
    {
    if(p[n-1].k==-1)p[n-1].k=zuofa(n-1);
    else if(p[n-2].k==-1)p[n-2].k=zuofa(n-2);
     else if(p[n-3].k==-1)p[n-3].k=zuofa(n-3);
      else if(p[n-4].k==-1)p[n-4].k=zuofa(n-4);
      p[n].k=p[n-1].k+p[n-2].k+p[n-3].k+p[n-4].k;
    }

      return p[n].k;


}
int main()
{
    int N,h,i=0;
    scanf("%d",&N);
    for(i=0;i<50;i++)p[i].k=-1;
    for(h=0;h<N;h++)
    {
        int n;

    scanf("%d",&n);
    printf("case #%d:\n",h);
    printf("%lld\n",zuofa(n));
    }

    return 0;
}
