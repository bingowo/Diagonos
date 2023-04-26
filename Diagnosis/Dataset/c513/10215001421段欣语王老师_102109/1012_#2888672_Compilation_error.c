#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[10000],a[10000];
    scanf("%s",s);
    int point=0,i=0,flag,k=0;
    long long int a=0,b=0,qr=1,qi=1,r;
    if(s[0]=='-')
    {
        point=1;
        i++;
    }    
    for(;i<strlen(s);i++)
    {
        a=a*10+s[i]-'0';
        if(s[i]=='-')
        {
            flag=1;
            break;
        }
        if(s[i]=='+')break;
    }
    for(;i<strlen(s);i++)
    {
        b=b*10+s[i]-'0';
    }
    if(point)a=-a;
    if(flag)b=-b;
    while(qi||qr)
    {
        if((a%2==1&&b%2==1)||(a%2==0&&b%2==0))r=0;
        else r=1;
        qr=(b-a+r)/2;
        qi=(-a-b+r)/2;
        a=qr;
        b=qi;
        a[k++]=r;
    }
    for(int j=strlen(a)-1;j>=0;j--)
    printf("%d",a[i]);
    return 0;
}