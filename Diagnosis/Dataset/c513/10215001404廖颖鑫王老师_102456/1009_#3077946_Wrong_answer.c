#define N 130
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 130

int num(char m)
{
    int c=m,cnt=0;
    scanf("%c",&m);
    for(int i=0;i<8;i++)
    {
        if(c%2==1)cnt++;
        c=c/2;
    }
    return cnt;
}//计算1的个数

int maxn(int m,int n)
{
    int temp;
    if(n%m==0)return m;
    while(n%m!=0)
    {
        temp=n%m;
        n=m;
        m=temp;
    }
    return temp;
}//求最大公因数

int main()
{
    int n,ans=0,per;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
      char s[N];
      gets(s);
      int sz=strlen(s);
      int a[sz];
      for(int j=0;j<sz;j++)
      {
          a[j]=num(s[j]);//a[j]存储s[j]中1的个数
          ans+=a[j];
      }
      per=maxn(ans,sz*8);
      printf("%d/%d\n",ans/per,sz*8/per);
    }
}
