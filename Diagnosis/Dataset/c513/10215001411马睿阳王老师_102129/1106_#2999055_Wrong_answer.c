#include<stdio.h>
#include<string.h>

int main()
{char G[1007]={0},W[1007]={0};
 int c[100000]={0};
 long long int sum=1;
 int i=0,j=0,k=0,t=0,l=0,q=0;
 scanf("%s",G);
 l=strlen(G);

 if(l==1) sum=1;
 else if(l==2)
 {
     if(G[0]==G[1]) sum=1;
     else sum=2;
 }
 else
 {if(G[0]!=G[1]) c[0]=2;
 else c[0]=1;
 for(i=1;i<=l-2;i++)
 {
     if((G[i]!=G[i+1])&&(G[i]!=G[i-1])) c[i]=3;
     if(((G[i]!=G[i+1])&&(G[i]==G[i-1]))||((G[i]==G[i+1])&&(G[i]!=G[i-1]))) c[i]=2;
     if(G[i]==G[i-1]==G[i+1])  c[i]=1;
 }
 if(G[l-1]!=G[l-2]) c[l-1]=2;
 else c[l-1]=1;
 for(j=0;j<=l-1;j++)
 sum*=c[j];
 }
 sum%=1000000007;
 printf("%lld",sum);
 return 0;
}
