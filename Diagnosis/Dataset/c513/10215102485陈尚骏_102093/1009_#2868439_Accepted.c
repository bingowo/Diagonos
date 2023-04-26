#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int gcd(int a,int b)
{
    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}
int judge(char s[],int k)
{
    int i,m=0;
    if(s[k]<0)i=s[k]+256;
    else i=s[k];
    if(i>=128) {m++;i=i-128;}
    if(i>=64) {m++;i=i-64;}
    if(i>=32) {m++;i=i-32;}
    if(i>=16) {m++;i=i-16;}
    if(i>=8) {m++;i=i-8;}
    if(i>=4) {m++;i=i-4;}
    if(i>=2) {m++;i=i-2;}
    if(i>=1) {m++;i=i-1;}
    return m;
}
int main()
{
    int n,j,l,m;
    char s[121];
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;++i)
    {
    l=0;
    gets(s);
    j=strlen(s);
    for(int k=0;k<j+1;++k)
    {
        l=l+judge(s,k);
    }
    m=gcd(l,j*8);
    printf("%d/%d\n",l/m,(j*8)/m);
    }
}


