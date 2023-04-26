#include<stdio.h>
#include<stdlib.h>
#define N 120
int one1(unsigned char d)
{
    int r;
    for(r=0;d>0;d>>=1)if(d&1) r++;
    return r;
}
int GCD(int num1,int num2)
{
    if(num1<num2)
    {
        int num=num1;
        num1=num2;
        num2=num;
    }
    return num1%num2?GCD(num2,num1%num2):num2;
}
void solve()
{
    char s[N+2];
    fgets(s,N+2,stdio)
    int i,count1,count10;
    count1=0;count10=strlen(s)*8;
    for(i=0;s[i]!='\n';i++)
    {
        count1+=one1(s[i]);
    }
    int gcd=GCD(count1,count10);
    count1=count1/gcd;
    count10=count10/gcd;
    printf("%d/%d\n",count1,count10);
}
int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
        solve;
}