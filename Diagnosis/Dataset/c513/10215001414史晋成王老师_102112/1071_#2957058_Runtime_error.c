#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long int solve(int n)
{ if(n==0) return 1;
else return n*solve(n-1);
}
long long int fang(int a,int n)
{ if(n==1) return a;
else if(n==0) return 1;
else return a*fang(a,n-1);
}
int main()
{ int t,i,j,a,b,k,n,m;
long long int s1,s2,s4,s3;
scanf("%d",&t);
for(i=0;i<t;i++)
{ scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
 printf("case #%d:\n",i);
 s1=fang(a,n); s2=fang(b,m);
 s3=solve(k)/solve(n)/solve(k-n);
 printf("%lld\n",s1*s2*s3%10007);
}
}