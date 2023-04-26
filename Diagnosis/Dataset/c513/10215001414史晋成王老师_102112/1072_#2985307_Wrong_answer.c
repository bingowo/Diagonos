#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int f(long long int x)
{ if (x>=0) return x;
else return -x;
    
}

int main()
{long long int x,y,z,man;
int step,k;
scanf("%lld %lld\n",&x,&y);
x=f(x); y=f(y);
if((y+x)%2==0&&(y+x!=0)) printf("-1");
else
{ step=0;
 man=f(x)+f(y);
     for (k=1;k<=64;k++)
        if(man<(1ull<<k))
         {step+=k;
          break;
         }
       printf("%d\n",step);  
         
     
    }
    
}