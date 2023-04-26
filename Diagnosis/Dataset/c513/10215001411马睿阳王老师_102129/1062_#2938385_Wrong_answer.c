#include<stdio.h>

int main()
{int T,i;
 int s[60];
 long long int n,m;
 scanf("%d",&T);
 for(i=5;i<52;i++)
 {s[1]=1,s[2]=2,s[3]=4,s[4]=8;
 s[i]=s[i-1]+s[i-2]+s[i-3]+s[i-4];
 }

 for(i=0,n=0;i<T;i++)
{
 scanf("%d",&n);
 m=s[n];
 printf("case #%lld:\n",i);
 printf("%lld\n",m);
}
return 0;
}

