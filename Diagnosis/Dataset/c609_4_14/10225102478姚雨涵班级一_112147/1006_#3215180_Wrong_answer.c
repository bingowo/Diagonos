#include <stdio.h>
int main()
{
int T;
scanf("%d",&T);
for(int cas=0;cas<T;cas++)
{
char s[61];
scanf("%s",s);
int a[128];
for(int i=0;i<128;i++)
        a[i]=-1;
int R=0,n = 1;
char *p=s;
a[*p]=1;
while (*++p){
if(a[*p]=-1)
{
a[*p]=R;
R=R?R+1:2;
n++;
}}
if (n<2)
n=2;
long long N=0;
p=s;
while(*p)
N=N*n+a[*p++];
printf("case #%d:\n%11d\n",cas,N);}
return 0;}
