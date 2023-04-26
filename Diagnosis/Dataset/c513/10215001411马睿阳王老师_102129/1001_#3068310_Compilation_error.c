#include<stdio.h>
#define N 1000
void turn(int a,char s[],int b)
{ char p;int i=0,c,sign=1,x;
  if(a<0) {a=-a;sign=-1;}  //解决十进制负号问题，用sign做一个判断标志
  while(a)                 //进制转化，注意转换为阿斯克码
  {c=a%b;
  if(c<10) s[i]=c+'0';
  else s[i]=(c-10)+'A';
  a=a/b;
  i++;}
  if(sign==-1) s[i]='-';  //解决数组中的负号问题。
  else i--;                 //若非负号，则去掉此位
  for(x=0;x<=i/2;x++)       //进行前后调换
  {p=s[x];s[x]=s[i-x];s[i-x]=p;}
  s[i+1]='0';                 //补上最后一位
}

int main()
{int n,i,s[N][0]，s[N][1];
char t[N];
scanf("%d",&n);
for(i=0;i<n;i++)
{scanf("%d%d",&s[i][0],&s[i][1]);
turn(s[i][0],t,s[i][1]);
printf("%s\n",t);}
return 0;

}
