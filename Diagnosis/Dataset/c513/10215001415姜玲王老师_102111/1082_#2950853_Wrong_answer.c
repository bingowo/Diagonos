#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void Atoi(char*a,char*b)
{int s;
for(s=0;s<strlen(a)&&a[s]!='.';s++);
for(int i=s-1,k=0;i>=0;i--,k++)
{b[k]=a[i];}}
void Atof(char*a,char*b)
{int s=0,k;
for(;s<strlen(a)&&a[s]!='.';s++);
for(int i=s+1,k=0;i<strlen(a);i++,k++)
    {b[k]=a[i];}
}
int main()
{char a[500],b[500],a0[500]={0},a1[500]={0},b0[500]={0},b1[500]={0},c0[500]={0},c1[500]={0};
int n,i;
char temp;
scanf("%s%s",a,b);
scanf("%d",&n);
for(int i=0;i<n+1;i++) a1[i]='0';
for(int i=0;i<n+1;i++) b1[i]='0';
Atoi(a,a0);
Atoi(b,b0);
if(b0[0]==0) b0[0]='0';
if(strstr(a,"."))Atof(a,a1);
if(strstr(b,"."))Atof(b,b1);
if((a1[n]+b1[n]-2*'0')>4) c1[n-1]++;
for( i=n-1;i>0;i--)
{temp=c1[i]+a1[i]+b1[i]-'0'-'0';
c1[i]=temp%10+'0';
c1[i-1]=temp/10;}
temp=c1[0]+a1[0]+b1[0]-'0'-'0';
c1[0]=temp%10+'0';
c0[0]=temp/10;
for( i=0;i<strlen(a0)||i<strlen(b0);i++)
{if(a0[i]==0) a0[i]='0';
if(b0[i]==0) b0[i]='0';
temp=c0[i]+a0[i]+b0[i]-'0'-'0';
c0[i]=temp%10+'0';
c0[i+1]=temp/10;
}
if(c0[i]) {c0[i]+='0';i++;}
for(int k=i-1;k>=0;k--)
{printf("%c",c0[k]);}
printf(".");
printf("%s",c1);
}
