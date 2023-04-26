#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct {int s[102];int cent;} bint;
void divide2(bint*p)
{   int carry=0,i;
    if(p->s[p->cent-1]<2)
    {
        p->cent--;
        carry=1;
    }
    for(i=p->cent-1;i>=0;i--)
    {
       int t=10*carry+p->s[i];
       p->s[i]=t/2;
       carry=t%2;
    }
}
void addmult2(bint*q,int b)
{
    int d=b,i;
    for(i=0;i<q->cent;i++)
    {
        int t=d+q->s[i]*2;
        q->s[i]=t%10;
        d=t/10;

    }
 if(d>0) {q->s[q->cent]=d;
          q->cent++;}

}
int main()
{
    int n,t,i;
    char a[102];
    scanf("%d",&n);
    for(t=0;t<n;t++)
    {
        int b[335]={0};
        bint p,q;
        for(i=0;i<102;i++) q.s[i]=0;
        q.cent=1;
        printf("case #%d:\n",t);
        scanf("%s",a);
        int len=strlen(a);
        for(i=0;i<len;i++)
        {
          p.s[i]=a[len-i-1]-'0';
        }
        p.cent=len;
        int k=0,j=0;
        while(p.cent>0)
            {
             b[k++]=p.s[0]%2;
             divide2(&p);
            }
        for(j=0;j<k;j++)
        {
         addmult2(&q,b[j]);
        }
       for(int v=0;v<q.cent;v++)
       {printf("%d",q.s[q.cent-1-v]);

       }
       printf("\n");

    }
}
