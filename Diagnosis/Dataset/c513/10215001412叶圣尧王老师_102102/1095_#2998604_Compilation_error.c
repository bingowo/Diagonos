#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int k=0;
void trans(char c,int*d)
{
    int a;
    if(isdigit(c))
        a=c-'0';
    else
        a=c-55;
    int e[4]={0}，q=3;
    while(a>0)
    {
        e[q--]=a%2;
        a/=2;
    }
    for(int i=3;i>=0;i--)d[k++]=e[i];
}
int main()
{
    getchar();getchar();char s[10001];
    scanf("%s",s);int i,j;int d[400]={0};long long a,b,m=0,n=0;
    for(i=strlen(s)-1;i>=0;i--)
    {
        trans(s[i],d);
    }
    for(i=0;i<4*strlen(s);i++)
    {
        if(i==0){a=1;b=0;}
        else
        {a=-1*(a+b);b=a-b;}
        if(d[i]==1)
        {m+=a,n+=b;}
    }
    if(m==0||n==0)
    {
        if(m==0&&n!=0)
        {
            if(n==1)printf("i");
            else if(n==-1)printf("-i");
            else printf("%lldi",n);
        }
        else if(m!=0&&n==0)
        {
           printf("%lld",n);
        }
        else printf("0");
    }
    else
    {
        if(n>0)printf("%lld+%lldi",m,n);
        else printf("%lld%lldi",m,n);
    }
}