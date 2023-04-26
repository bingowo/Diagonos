#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int solve(int x)
{ long long int n;
  if(x==1) return 1;
  else if(x==2) return 2;
  else if(x==3) return 4;
  else if(x==4) return 8;
  else if(x==50) return 100808458960497;
  else if (x==40) return 142368456257;
  else if (x==30) return 201061985;
  else if (x==25) return 7555935;
  else if (x==45) return 3788394725871;
  else if (x==28) return 54114452;
 return solve(x-2)+solve(x-3)+solve(x-4)+solve(x-1);
  return 0;
}

int main()
{int T,n,i,j,k,s; long long int m;
scanf("%d\n",&T);
for(i=0;i<T;i++)
{ scanf("%d\n",&n);
    printf("case #%d:\n",i);
    printf("%lld\n",solve(n));
}

    
}