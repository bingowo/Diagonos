#include<stdlib.h>
#include<stdio.h>
int pick(int a,int i)
{int b;
    b=(a&(~(~0<<i)&(~0<<i-1)))>>(i-1);
    return b;
}

main()
{int T,a=1,in[10],out[10],i,n,c=1,e,f,g,h=1;
scanf("%d",&T);
for(i=0;i<T;i++)+
    scanf("%d",in+i);
for(i=0;i<T;i++)
{for(n=32;n>0;n--)
{if (!pick(in[i],n)&&c)continue;
else c=0;
if(!(n-1))
{if(a>h)h=a;break;}
e=pick(in[i],n);
g=n-1;
f=pick(in[i],g);
if((e!=f))a++;
else if(a>h){h=a;a=1;}
else a=1;}
printf("case #%d:\n",i);
printf("%d\n",h);a=1;c=1;h=1;}

}
