#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int f(long long int x)
{ if (x>=0) return x;
else return -x;
    
}
 char* Path(long long int x,long long int y,int r)
{ if (r>1)
{ long long int d={1LL<<(r-1)};
   return f(x)>f(y)?
         (x>0?strcat(Path(x-d,y,r-1),"E"):strcat(Path(x+d,y,r-1),"W"))
         :(y>0?strcat(Path(x,y-d,r-1),"N"):strcat(Path(x,y+d,r-1),"s"));
    }
    else if (r==1)
    { long long int d={1LL<<(r-1)};
   return f(x)>f(y)?
         (x>0?strcpy(Path(x-d,y,r-1),"E"):strcpy(Path(x+d,y,r-1),"W"))
         :(y>0?strcpy(Path(x,y-d,r-1),"N"):strcpy(Path(x,y+d,r-1),"s"));
        
    }
    return "";
}
int main()
{long long int x,y,z,man,a,b;
int step,k;
char s[100];
scanf("%lld %lld\n",&x,&y);
a=f(x); b=f(y);
man=f(x)+f(y);
if(man%2==0&&(b+a!=0)) printf("-1");
else if (a+b==0) printf("0");
else
{ step=0;
 man=f(x)+f(y);
     for (k=1;k<=64;k++)
        if(man<(1ull<<k))
         {step+=k;
          break;
         }
       printf("%d\n",step);  
         strcpy(s,Path(x,y,step));
       printf("%s\n",s);
    }
    
}