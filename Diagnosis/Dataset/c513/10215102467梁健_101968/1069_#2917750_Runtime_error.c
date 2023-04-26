#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
long long sol[51];
int res;
void i2a(char s[],int n)
{
   int m=n,len=0;
   while(m/10){
        len++;m/=10;
   }
   for(int i=len-1;i>-1;i--){
    s[i]=n%10;
    n/=10;
   }
}
void solve(int n)
{
    res++;
    int a=n,b,s;
    char s1[11],s2[11];
    i2a(s1[11],n);
    for(int i=strlen(s1)-1;i>-1;i--)s2[strlen(s1)-i-1]=s1[i];
    b=atoi(s2);
    s=a+b;
    char jud[11];
    i2a(jud[11],s);
    int judge=0;
    for(int i=0;i<strlen(jud)/2;i++)if(jud[i]==jud[strlen(jud)-i])judge++;
    if(judge==strlen(jud)/2)printf("%d %d",res,s);
    else solve(s);
}
int main()
{
    int n;scanf("%d",&n);
    res=0;
    solve(n);
    return 0;
}
