#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char s[10000];
    int f[10000]={0};
    gets(s);
    int point=0,i=0,flag,k=0;
    long long int a=0,b=0,qr,qi,r;
    if(s[0]=='-')
    {
        point=1;
        i++;
    }    
    for(;i<strlen(s);i++)
    {
        if(s[i]=='-')
        {
            flag=1;
            break;
        }
        if(s[i]=='+')break;
        a=a*10+s[i]-'0';
    }
    i++;
    for(;i<strlen(s);i++)
    {
        if(s[i]=='i')break;
        b=b*10+s[i]-'0';
    }
    if(point)a=-a;
    if(flag)b=-b;
    while(qi!=0||qr!=0)
    {
        if(abs(a)%2==abs(b)%2)r=0;
        else r=1;
        f[k++]=r;
        qr=(b-a+r)/2;
        qi=(-a-b+r)/2;
        a=qr;
        b=qi;
    }
    for(k=k-1;k>=0;k--)
    printf("%d",f[k]);
    return 0;
}