#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int gcd(int a,int b)
{int c;
    while(a%b)
{c=a%b;
a=b;
b=c;
}
return b;
}
void number(char p[])
{int c,d=0,i,k,m;
c=strlen(p)*8;
for(i=0;i<strlen(p);i++)
{while(p[i]!=0)
{if(p[i]%2) d++;
p[i]=p[i]/2;}}
m=gcd(d,c);
c=c/m;
d=d/m;
printf("%d/%d\n",d,c);}
int main()
{int n,i,l=0;
char a,str[121];
scanf("%d",&n);
getchar();
for(i=0;i<n;i++)
{while((a=getchar())!="\n")
{str[l++]=a;}
number(str);
}
}
