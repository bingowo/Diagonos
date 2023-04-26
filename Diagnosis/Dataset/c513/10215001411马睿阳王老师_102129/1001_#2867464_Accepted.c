#include<stdio.h>

#define N 1000
void turn(int a,char s[],int b)
{ char p;int i=0,c,sign=1,x;
  if(a<0) {a=-a;sign=-1;}
  while(a)
  {c=a%b;
  if(c<10) s[i]=c+'0';
  else s[i]=(c-10)+'A';
  a=a/b;
  i++;}
  if(sign==-1) s[i]='-';
  else i--;
  for(x=0;x<=i/2;x++)
  {p=s[x];s[x]=s[i-x];s[i-x]=p;}
  s[i+1]=0;
}

int main()
{int n,i,s[N][2];
char t[N];
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d%d",&s[i][0],&s[i][1]);
for(i=0;i<n;i++)
{turn(s[i][0],t,s[i][1]);
printf("%s\n",t);}
return 0;

}
