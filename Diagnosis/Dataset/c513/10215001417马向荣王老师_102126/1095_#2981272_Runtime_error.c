#include<stdio.h>
#include<string.h>
int main(void)
{
    char s[100]={0};//存输入
    long long int a[1000]={0};//存二进制
    long long int b[1000]={0};//存16进制转化成十进制
    getchar();
    getchar();
    gets(s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0' && s[i]<='9') b[i]=s[i]-'0';
        if(s[i]>='A' && s[i]<='Z') b[i]=s[i]-'A'+10;
        for(int j=i*4+3;j>=4*i;j--)
        {
            a[j]=b[i]%2;
            b[i]/=2;
        }
    }
    long long int qr=0,qi=0;//实部虚部
    long long int re,im;
    for(int c=0;c<4*strlen(s);c++)
    {
        long long int r=a[c];
        re=-qr-qi+r;
        im=qr-qi;
        qr=re;
        qi=im;
    }
    if(qi==0)
    {
        printf("%lld",qr);
    }
    else
    {
        if(qr!=0)
        {
            printf("%lld",qr);
            if(qi>0) printf("+");
        }//实部
        if(qi==1) printf("i");//虚部
        else if(qi==-1) printf("-i");
        else 
        {
            printf("%lld",qi);
            printf("i");
        }
    }
    return 0;
}