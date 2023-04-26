#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char chr[1005];
int ans[1005];
int main()
{
    long long bin[5],flag=0;
    scanf("%s",chr);
    int L=strlen(chr);
    long long a=0,b=0,qr=0,qi=0,r,x=1;
    int i=L-1;
    if(chr[L-1]=='i')
    {
        b=1;
        for(i=L-2;i>=0;i--)
        {
            if(chr[i]=='+'){i--;break;}
            if(chr[i]=='-'){i--;b=-b;break;}
            if(i==L-2)b=0;
            b+=(chr[i]-'0')*x;
            x*=10;
        }
    }
    x=1;
    for(;i>=0;i--)
    {
        if(chr[i]=='-'){a=-a;break;}
        a+=(chr[i]-'0')*x;
        x*=10;
    }//printf("%d %d\n",a,b);
    int cnt=0;
    while(1)
    {
        if((a&1)==(b&1))r=0;
        else r=1;
        qi=(-a-b+r)/2;qr=qi+b;
        ans[++cnt]=r;
        if((a==1&&b==0)||(a==0&&b==0))break;
        a=qr;b=qi;
    }
    for(i=cnt;i>=1;i--)printf("%d",ans[i]);
    return 0;
}