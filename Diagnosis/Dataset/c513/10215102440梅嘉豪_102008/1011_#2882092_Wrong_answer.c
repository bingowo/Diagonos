#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000],t[1000];
    long long int qr=0,qi=0;
    long long int a,b;
    scanf("0x%s",s);
    int k=0;
    for(int i=0;i<strlen(s);i++)//16进制转化为2进制
    {
        int d=s[i]>='A'?s[i]-'A'+10:s[i]-'0';
        unsigned int flag=8;
        while(flag)
        {
            t[k++]=d&flag?'1':'0';
            flag=flag>>1;
        }
    }
    for(int i=0;i<k;i++)//迭代求系数a,b
    {
        int r=t[i]-'0';
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;qi=b;
    }
    if(a!=0)    printf("%lld",a);
    if(b>1&&a==0)     printf("%lldi",b);
    if(b>1)     printf("+%lldi",b);
    else if(b==1&&a==0)   printf("i");
    else if(b==1)   printf("+i");
    else if(b==0&&a==0) printf("0");
    else if(b==-1)  printf("-i");
    else if(b<-1)   printf("%lldi",b);
}