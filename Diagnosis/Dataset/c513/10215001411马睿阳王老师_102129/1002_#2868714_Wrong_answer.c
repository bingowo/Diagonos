#include<stdio.h>

int main()
{ char s[61];
  scanf("%s",&s);//输入一个字符串
  int a[128],i;
  for(i=0;i<128;i++)//给所有i赋一个初值
  {a[i]=-1;}
  int digit=0,N=1;char *p=s;
  a[*p]=1;
  while(*p++)
  {if(a[*p]==-1) //在字符串里
   {a[*p]=digit;digit==0?digit+1:2;N++; }//前面是0.则后面为2；前面是n，则后面是n+1
  }
  if(N<2) N=2; //不可能是一进制
  long long t=0;p=s;
  while(*p)
  { t=t*N+a[*p];p++;}
  printf("%lld\n",t);
  return 0;
}
