#include<stdio.h>
#include<string.h>
int main(void)
{
    char s[1000];
    int a[1000],b[1000];
    getchar();
    getchar();
    gets(s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9') b[i]=s[i]-'0';
        if(s[i]>='A'&&s[i]<='Z') b[i]=s[i]-'A'+10;
        for(int j=4*i+3;j>4*i;j--)
        {
            a[i]=b[i]%2;
            b[i]/=2;
        }
    }
    long long int r,re,im,qr=0,qi=0;
    for(int i=0;i<4*strlen(s);i++)
    {
        r=a[i];
        re=r-qr-qi;
        im=qr-qi;
        qr=re;
        qi=im;
    }
    if(qi==0) printf("%d",qr);
    else
    {
        if(qr!=0)
        {
            printf("%lld",qr);
        }
        if(qi>0) printf("+");
        if(qi==1) printf("i");
        else if(qi==-1) printf("-i");
        else
        {
            printf("%lld",qi);
            printf("i");
        }
    }
    return 0;
}
