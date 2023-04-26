#include<stdio.h>

int main()
{ char s[61];char *p;
  *p=s;
  scanf("%s",&s);//输入一个字符串
  int a[128],i;
  for(i=0;i<128;i++)//给所有i赋一个初值
  {a[i]=-1;}
  int digit=0,N=1;
  a[*p]=1;
  while(*p++)
  {if(*p==-1) //在字符串里
   {a[*p]=digit;digit=digit?2:digit+1;N++; }//前面是0.则后面为2；前面是n，则后面是n+1
  }
  if(N<2) N=2; //不可能是一进制
  long long t=0;
  while(*p)
  { t=t*N+a[*p++];
  printf("%lld\n",t);
  }
  return 0;
}
