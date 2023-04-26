#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[100];
    scanf("%s",s);
    //十六进制转化为二进制
    int t[500];
    int k=0;
    for(int i=2;i<strlen(s);i++)
    {
        int d=0;
        if(isdigit(s[i])) d=s[i]-'0';
        else d=s[i]-'A'+10;
        for(int j=3;j>=0;j--)
        {
            t[k++]=(d>>j)&1;
        }
    }
    //转成十进制下的负数
    long long int qr=0,qi=0,a=0,b=0;
    for(int i=0;i<k;i++)
    {
        int r=t[i];
        a=-qr-qi+r;b=qr-qi;
        qr=a;qi=b;
    }
    //打印
    if(qi==0) printf("%lld\n",qr);
    else
    {
        if(qr!=0) printf("%lld",qr);
        if(qr!=0&&qi>0) printf("+");
        if(qi==1) printf("i\n");
        else if(qi==-1) printf("-i\n");
        else printf("%lldi\n",qi);
    }
    return 0;
}
