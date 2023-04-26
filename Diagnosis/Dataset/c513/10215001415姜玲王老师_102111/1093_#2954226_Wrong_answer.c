#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void produce(char*a)
{int j=0;
for(a[j]++;a[j]>='9';j++){a[j]='0';a[j+1]++;}
}
int judge(char*a)
{int i=0,sum=0;
for(;i<200;i++)
{sum+=a[i]-'0';}
if(sum%9) return 1;
if(strstr(a,"9")) return 1;
return 0;
}
int main()
{char s[200],a;
int i,j;
scanf("%s",s);
int k;
k=strlen(s);
for(i=0;i<(k/2);i++)
{a=s[i];
s[i]=s[k-i-1];
s[k-i-1]=a;}
for(i=k;i<200;i++)
{s[i]='0';
}
do{produce(s);}
while(!judge(s));
for(i=199;s[i]=='0'&&i>0;i--);
for(;i>=0;i--)
{printf("%c",s[i]);}
}
