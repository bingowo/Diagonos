#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int f(int n)
{ if(n==0||n==1) return 1;
   else     return n*f(n-1);
}
int main()
{ int t,i,j,n,s,k,m;
long long int ans;
scanf("%d",&t);
for(i=0;i<t;i++)
{ scanf("%d %d",&m,&n);
  printf("case #%d:\n",i);
  if(n==0) printf("1\n");
  else
  { ans=f(m)/f(n)/f(m-n);
      printf("%lld\n",ans);
      
  }
}
    
}