#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
unsigned long long int solve(int n)
{ if(n==0) return 1;
else return n*solve(n-1);
}
unsigned long long int fang(int a,int n)
{ if(n==0) return 1;
else return a*fang(a,n-1);
}
int main()
{ int t,i,j,a,b,k,n,m;
unsigned long long int s1,s2,s4,s3;
scanf("%d\n",&t);
for(i=0;i<t;i++)
{ scanf("%d %d %d %d %d\n",&a,&b,&k,&n,&m);
 printf("case #%d:\n",i);
 s1=fang(a,n); s2=fang(b,m);
 s3=solve(k)/solve(n)/solve(k-n);
 printf("%llu\n",s1*s2*s3%10007);
}
}