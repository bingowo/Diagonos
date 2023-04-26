#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int solve(int x)
{ if(x==1) return 1;
  
}

int main()
{int T,n,i,j,k,s; long long int m;
scanf("%d\n",&T);
for(i=0;i<T;i++)
{ scanf("%d\n",&n);
    m=solve(n);
    printf("case #%d:\n",i);
    printf("%lld\n",m);
}

    
}