#include<stdio.h>
#include<string.h>
int gcd(int a,int b)
{
	if(b) while((a%=b) && (b%=a));
	return a+b;
}
int count(char c)
{
  int n=0,d=1;
  for(int i=0;i<8;i++)
  {
    if(c&d)n++;
    d=d<<1;
  }
  return n;
}
int main()
{
  int n,t;//n0指总位数，n1指1的位数
  scanf("%d",&n);
  getchar();
  for(int i=0;i<n;i++)
  {
    char c;
    int n1=0,n0=0;
    while(scanf("%c",&c)!=EOF&&c!='\n'){
      n1=n1+count(c);
      n0++;
    }
    n0*=8;
    t=gcd(n1,n0);
    printf("%d/%d\n",n1/t,n0/t);
  }
  return 0;
}