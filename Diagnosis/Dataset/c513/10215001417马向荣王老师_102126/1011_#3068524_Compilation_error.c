#include<stdio.h>
#include<string.h>
int main(void)
{
    char s[100];
    int a[1000];
    int b[1000];
    getchar();
    getchar();
    gets(s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0' && s[i]<='9') b[i]=s[i]-'0';
        if(s[i]>='A' && s[i]<='Z') b[i]=s[i]-'A'+10;
        for(int j=4*i+3;j>=4*i;j--)
        {
            a[j]=b[i]%2;
            b[i]/=2;
        }
    }
    long long int qr=0,qi=0;
    long long int re,im;
    for(int i=0;i<4*strlen(s);i++)
    {
        int r=a[i];
        re=-qr-qi+r;
        im=qr-qi;
        qr=re;
        qi=im;
    }
    if(qi==0) printf("%lld",qr);
    else
    {
        if(qr==0) 
        {
            printf("%lld",qi);
            printf("i");
        }
        if(qr!=0)
        {
            printf("%lld",qr);
            if(qi>0) printf("+");
        }
        if(qi==1) printf("i");
        if(qi==-1) printf("-i");
        printf("%lldi\n",qi)
    }
    return 0;
}
