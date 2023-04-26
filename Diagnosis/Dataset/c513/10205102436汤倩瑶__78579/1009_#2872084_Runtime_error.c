#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f(char c)
{
    int ans=0;
    for(int i=0;i<8;i++)
{
    if((c&1)==1)ans++;
    c>>=1;
}
    return ans;

}
int gcd(int a,int b)
{
    if(a==0)return b;
     return gcd(b,a%b);
}
int main()
{
    int T;
    scanf("%d",&T);
    char c;
    scanf("%c",&c);
    for(int i=0;i<T;i++)
    {

 int ans1=0;
    int cnt=0;
    while(scanf("%c",&c)!=EOF&&c!='\n')
    {
    ans1+=f(c);
    cnt++;
    }
    int g=gcd(ans1,cnt*8);
if(ans1==0)printf("0\n");
else if(ans1==cnt*8)printf("1\n");
  else  printf("%d/%d\n",ans1/g,cnt*8/g);
    }

}
