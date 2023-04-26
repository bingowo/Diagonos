#include<stdio.h>
int main()
{int T,N,i,j;
 int d5=0,d25=0,d125=0,d625=0,x;
 scanf("%d",&T);
 for(i=0;i<T;i++)
  {scanf("%d",&N);
     for(j=1;j<=N;j++)
    {if(j%625==0) d625+=4;
     if(j%125==0) d125+=3;
     if(j%25==0) d25+=2;
     if(j%5==0) d5+=1;
    }
   x=d5+d25+d125+d625;
   printf("case #%d:\n",i);
   printf("%d\n",x);
   }
return 0;
}
