#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 121

int num(char s[N])
{
    int i,k,b=1,j,n,sum=0,d;
    
    for(j=0;j<strlen(s);j++)
    {
        n=s[j]-'0';
        for(i=0,k=0;i<8;i++)
        {
           if(n&b)k++;
           n>>=1;
         }
    sum=sum+k;
    }
    return sum;
}
int main()
{
    int i,n,sum,j;
    char s[N];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        sum=num(s);
        printf("%d/%d",sum,d*8);
        for(i=0;i<d;i++)s[i]='\0';
    }
    return 0;
    
    
