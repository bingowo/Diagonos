#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

int maxn(int x,int y)
{
    if(x-y>=0)
        return x;
    else return y;
}

int main()
{
  char s[N+1];
  gets(s);//把s读进去
  int ans[N+1],i=0,sz=strlen(s),max=1;
  for(i=1;i<sz;i++)
  {
     ans[0]=1;
     if(s[i]!=s[i-1])
     {
         ans[i]=ans[i-1]+1;//如果两两不相同则围栏长度加一
         max=maxn(ans[i],max);//比较大小，保留更大的那一个；（也即保留截至当前的最大长度）
     }
     else ans[i]=1;
  }
printf("%d",max);
}
