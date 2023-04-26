#include<stdio.h>
#include<string.h>

#define N 210
#define L 100
#define M 1000000007

long long p(char *s)
{ long long dp[L+1][N]={1},ans=0;
  int i,slen,sgn,cur,j,x;
  for (slen=strlen(s),i=0;i<slen;i++)
    for(sgn=(i==0)?1:-1;sgn<=1;sgn+=2)
      for (cur=0,j=i;j<slen;j++)
        for (cur=(cur*10+s[j]-'0')%N,x=0;x<N;x++)
          dp[j+1][(x+sgn*cur+N)%N]+=dp[i][x],dp[j+1][(x+sgn*cur+N)%N]%=M;
  for (x=0;x<N;x++) ans=(ans+(x%2==0||x%3==0||x%5==0||x%7==0)*dp[slen][x])%M;
  return ans;
}
int main()
{  int I,T; char s[L+1];
   for (scanf("%d\n",&T),I=0;I<T;I++)
     printf("%lld\n",(scanf("%s",s),p(s)));
   return 0;
}
