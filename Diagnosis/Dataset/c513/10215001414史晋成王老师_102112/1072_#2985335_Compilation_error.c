#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int f(long long int x)
{ if (x>=0) return x;
else return -x;
    
}
 char *Path(long long int x,long long int y,int r)
{ if (r)
{ long long int d={1LL<<(r-1)};
   return f(x)>f(y)?
         (x>0?Path(x-d,y,r-1)+"E":Path(x+d,y,r-1)+"W")
         :(y>0?Path(x,y-d,r-1)+"N":Path(x,y+d,r-1)+"s");
    }
    return 0;
}
int main()
{long long int x,y,z,man;
int step,k;
char s[100];
scanf("%lld %lld\n",&x,&y);
man=f(x)+f(y);
if(man%2==0&&(y+x!=0)) printf("-1");
else if (y+x==0) printf("0");
else
{ step=0;
 man=f(x)+f(y);
     for (k=1;k<=64;k++)
        if(man<(1ull<<k))
         {step+=k;
          break;
         }
       printf("%d\n",step);  
         s=Path(x,y,step);
       printf("%s\n",s);
    }
    
}