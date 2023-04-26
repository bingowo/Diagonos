#include<stdio.h>
#include<stdlib.h>
#define N 120
int number1(unsigned char d)
{
    int r=0;
    for(r=0;d>0;d>>=1)
   { if(d&1) r++;}
    return r;
}
int GCD(int num1,int num2)
{
    return num1%num2?GCD(num2,num1%num2):num2;
}
void solve()
{
    char s[N+2];
    fgets(s,N+2,stdin);
    int count1,i,count10;
    for(count10=count1=i=0;s[i]!='\n';i++)
    {
        count1+=number1(s[i]);
        count10+=8;
    }
    int gcd=GCD(count1,count10);
    printf("%d/%d\n",count1/gcd,count10/gcd);
}
int main()
{
    int T;
    int i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        solve();
    }
    return 0;
}