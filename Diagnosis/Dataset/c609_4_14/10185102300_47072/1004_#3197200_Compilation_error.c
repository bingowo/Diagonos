#include <stdio.h>

char digit(int d)
{ return d<10 ?  d+'0': d-10+'A'; }

void process(int n, int R)
{ if  (n>0) process(n/R,R),printf("%c",digit(n%R)); }

int main()
{   int i;
    {   int A,d,B; char n[33];
        for (scanf("%d%s%d",&A,n,&B),d=i=0;n[i];i++) 
            d=d*A+n[i]-((n[i]>='0'&&n[i]<='9')?'0':((n[i]>='a'&&n[i]<='z')?'a':'A')-10);
        if (d) process(d,B) else printf("0"); printf("\n");
     }

    return 0;
}