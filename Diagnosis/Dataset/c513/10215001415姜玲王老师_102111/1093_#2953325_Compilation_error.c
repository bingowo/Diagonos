#include <stdio.h>
#include <stdlib.h>
#include<string.h>
produce(char*a)
{for(j=0;j<strlen(a)-1;j++)
{for(a[j]++;)
}}
int main()
{char s[200],a,v[200];
int i,j;
scanf("%s",s);
for(i=0;i<=strlen(s)/2;i++)
{a=s[i];
s[i]=s[strlen(s)-1];
s[strlen(s)-1]=a;}
do{produce(s);}
while(!judge(a));
for(i=strlen(a)-1;i>=0;i--)
{printf("%d",a[i]);}
}