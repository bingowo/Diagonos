#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define N 32
void bf(int a,char s[N])
{int i=0,j;
 char p;
 while(a)
{s[i]=a%2+'0';
 i++;
 a=a/2;
}
i--;
for(j=0;j<=i/2;j++)
{ 
  p=s[j];
  s[j]=s[i-j];
  s[i-j]=p;
}
s[i+1]='\0';
}

int main()
{
 int n,i,k=1,x=1,j=1,d,a,h;
 char s[N];
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  scanf("%d",a);
  bf(a,s);
  d=strlen(s);
  s[d]=s[d-1];
while(j<=strlen(s))
{if(s[j]!=s[j-1]) k++;
 else if(k>=x) {x=k;k=1;}
 else  k=1;
 j++;
}
printf("case #%d:\n%d\n",i,x);
for(h=0;h<d;h++) s[h]='\0';   

 }
 return 0;
}