#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void three(int n)
{int a[11]={0};
for(int i=0;n;i++)
{a[i]=n%2;
n/=2;}
for(int j=9;j>=0;j--)
{printf("%d",a[j]);}
}
void two(int n)
{int a[8]={0};
for(int i=0;n;i++)
{a[i]=n%2;
n/=2;}
for(int j=6;j>=0;j--)
{printf("%d",a[j]);}
}
void one(int n)
{int a[4]={0};
for(int i=0;n;i++)
{a[i]=n%2;
n/=2;}
for(int j=3;j>=0;j--)
{printf("%d",a[j]);}
}
int main()
{
int l,i,n1,n2;
char code[501];
scanf("%s",code);
printf("0001");
int digit[10]={0};
int length=strlen(code);
for(i=0;length;i++)
{digit[i]=length%2;
length/=2;
}
for(int k=9;k>=0;k--)
{printf("%d",digit[k]);}
int m=strlen(code);
for(l=0;m;)
{if(m>=3)
{n1=(code[l]-'0')*100+(code[l+1]-'0')*10+code[l+2]-'0';
l+=3;m-=3;
three(n1);}
if(m==2)
{
n2=(code[l]-'0')*10+code[l+1]-'0';
l+=2;m-=2;
two(n2);}
if(m==1) {one(code[l]-'0');m-=1;}}}

