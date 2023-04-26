#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char s[10000];
    int f[10000]={0};
    scanf("%s",s);
    int k=0,r,l;
    long long int a=0,b=0,qr,qi;
    l=strlen(s);
    if(s[l-1]!='i') a=atoll(s),b=0;
    else
    {
    for(int i=l-1;i>=0;i--)
    if(s[i]=='+'||s[i]=='-'||i==0){
    if(s[i+1]=='i') b=s[i]=='+'?1:-1;
    else if(s[i]=='i') b=1;
    else s[l-1]='\0',b=atoll(s+i);
    if(i!=0) s[i]='\0',a=atoll(s);
    else a=0;
    break;
    }
    }
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