#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void three(int n)
{int a[10]={0};
for(int i=0;n;i++)
{a[i]=n%2;
n/=2;}
for(int j=9;j>=0;j--)
{printf("%d",a[j]);}
}
void two(int n)
{int a[7]={0};
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
int l,i;
char code[501];
char a[3],b[2];
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
{a[0]=code[l];a[1]=code[l+1];a[2]=code[l+2];
l+=3;m-=3;
three(atoi(a));}
if(m==2)
{b[0]=code[l];b[1]=code[l+1];
l+=2;m-=2;
two(atoi(b));}
if(m==1) {one(code[l]-'0');m-=1;}}}

