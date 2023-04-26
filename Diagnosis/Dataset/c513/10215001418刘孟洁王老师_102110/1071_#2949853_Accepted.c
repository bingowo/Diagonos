#include <stdio.h>
const int MAXN = 1000;
long long CC[1007][1007];
void init()
{
    for(int i=0; i<=MAXN; ++i)
    {
        CC[0][i] = 0;
        CC[i][0] = 1;
    }
    for(int i=1; i<=MAXN; ++i)
    {
        for(int j=1; j<=MAXN; ++j)
        CC[i][j] = (CC[i-1][j] + CC[i-1][j-1]) % 10007;//从n里面选m个，对于某个元素，选就是C(m-1,n-1);不选就是c(m,n-1);
    }
}//求二项式系数;

long long qpow(long long a, long long b){
 long long ans = 1;
 long long base = a;
 while(b){
  if(b&1) ans = ans*base%10007;//跳过b的二进制为0的地方
  base = base*base%10007;//base一直乘（乘自己）；
  b>>=1;
 }
 return ans;
}//快速幂

int main()
{
 init();
 int t;
 scanf("%d",&t);
 int cnt=0;
 while(t--){
  long long a,b,k,n,m;
  scanf("%lld%lld%lld%lld%lld", &a,&b,&k,&n,&m);
  printf("case #%d:\n",cnt++);
  printf("%lld\n",qpow(a,n)*qpow(b,m)%10007*CC[k][m]%10007);
 }
  return 0;

}