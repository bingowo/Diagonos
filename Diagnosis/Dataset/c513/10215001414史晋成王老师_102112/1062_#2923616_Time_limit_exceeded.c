#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int solve(int x)
{ if(x==1) return 1;
  else if(x==2) return 2;
  else if(x==3) return 3;
  else if(x==4) return 8;
  else if(x>4) return solve(x-4)+solve(x-3)+solve(x-2)+solve(x-1);
}

int main()
{int T,n,i,j,k,s; long long int m;
scanf("%d",&T);
for(i=0;i<T;i++)
{ scanf("%d\n",&n);
    m=solve(n);
    printf("case #%d:\n",i);
    printf("%lld\n",m);
}

    
}