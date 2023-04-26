#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void input(int a[])
{
    char s[509];
    scanf("%s",s);
    int i=0,k,j;
    while(s[i]!='.'&&s[i])i++;
    for(j=i-1,k=500;j>=0;j--,k--)a[k]=s[j]-'0';
    for(j=i+1,k=501;s[j];j++,k++)a[k]=s[j]-'0';
}

void add(int a[],int b[],int n)
{

    for(int i=1000;i>500+n;i--){
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
    if(a[501+n]>=5)a[500+n]++;
    for(int i=500+n;i>0;i--){
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
}

int main()
{
    int a[1009]={0},b[1009]={0};
    input(a);
    input(b);
    int n;
    scanf("%d",&n);
    add(a,b,n);
    int  i=0;
    while(i<=500&&a[i]==0)i++;
    if(i>500)printf("0");
    else{
        for(int j=i;j<=500;j++)printf("%d",a[j]);
    }
    printf(".");
    for(int j=501;j<=500+n;j++)printf("%d",a[j]);
    return 0;
}