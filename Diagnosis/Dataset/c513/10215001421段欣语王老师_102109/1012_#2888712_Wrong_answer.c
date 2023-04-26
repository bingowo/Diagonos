#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[10000],f[10000];
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
    i++;
    for(;i<strlen(s);i++)
    {
        b=b*10+s[i]-'0';
    }
    if(point)a=-a;
    if(flag)b=-b;
    while(qi!=0||qr!=0)
    {
        if((a%2==1&&b%2==1)||(a%2==0&&b%2==0))r=0;
        else r=1;
        qr=(b-a+r)/2;
        qi=(-a-b+r)/2;
        a=qr;
        b=qi;
        f[k++]=r;
    }
    for(int j=strlen(f)-1;j>=0;j--)
    printf("%d",f[j]);
    return 0;
}