#include <stdio.h>
#include <stdlib.h>

int main()
{char s[1000001];
gets(s);
long long start=0,len=0;
long long  m[128];
int i=0;
for(;i<128;i++)
{m[i]=-1;}
char c;
long long t=0;
for(long long i=0;s[i];i++)
{c=s[i];
if(m[c]>=t)
{t=m[c]+1;
m[c]=i;}
else{m[c]=i;
if(len<i-t+1)
{start=t;
len=i-t+1;}}
}
for(long long i=0;i<len;i++)
{printf("%c",s[start+i]);
}
printf("\n");}
