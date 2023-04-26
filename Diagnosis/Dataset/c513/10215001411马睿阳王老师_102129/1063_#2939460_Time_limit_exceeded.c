#include <stdio.h>

long long int swap(long long int a,long long int b)
{long long int t;
 t=a;
 a=b;
 b=t;
}

int main()
{ long long int x,y,v=0;
  scanf("%lld %lld",&x,&y);
  if(x<y) v=swap(x,y);
  else if(x==y) v=4*x;
  else if(x%y==0) v=x*4;
  else while(x%y!=0)
   {v+=4*x;
    x=x%y;}
 printf("%lld",v);
 return 0;

}
