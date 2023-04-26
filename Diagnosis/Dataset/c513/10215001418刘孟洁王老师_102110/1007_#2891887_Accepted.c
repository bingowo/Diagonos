#include <stdio.h>
#include <ctype.h>
#include<string.h>
#define N 32
void bf(int a,char s[N])
{
    int i=0,j;
    char p;
    while(a)
    {
        s[i]=a%2+'0';
         a=a/2;
         i++;
    }
   s[i]='\0';}


int main()
{
    int n,a,i,k,x,j,h,d;
    char s[N];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        bf(a,s);
        k=1;
        x=1;
        j=1;
        d=strlen(s);
        s[d]=s[d-1];//当有这个过程时，需要有终止符号！！
        s[d+1]='\0';//即需要这一步！方便还有面继续输入时可以覆盖。
   while(j<strlen(s))
      {
        if(s[j]!=s[j-1])k++;
        else if(k>=x){x=k;k=1;}
        else if(k<x)k=1;
        j++;
      }//如果没有前面两步，可以在这后面加上：if(k>x)x=k;
      printf("case #%d:\n%d\n",i,x);

}
    return 0;
}