#include<stdio.h>

int main()
{int T,i;
 int s[51];
 long long int n;
 scanf("%d",&T);
 for(i=0;i<T;i++)
{
 scanf("%d",&n);
 s[1]=1,s[2]=2,s[3]=4,s[4]=8;
 s[n]=s[n-1]+s[n-2]+s[n-3]+s[n-4];
 printf("case #%lld:\n",i);
 printf("%lld\n",s[n]);
}
return 0;
}

