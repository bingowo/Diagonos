#include<stdio.h>
#include<string.h>

int main()
{
    int k,i;
    char s[1000];
    char t[1000];
    long long int qr=0,qi=0;
    long long int a,b;
    scanf("%s",s);
    for(i=2;i<strlen(s);i++)
    {
        int d;
        if(s[i]>='A') d=s[i]-'A'+10;
        else d=s[i]-'0';
        unsigned int flag = 0x8; 
        while(flag)
        {
            if(d&flag) t[k++]='1';
            else t[k++]='0';
            flag = flag>>1;
        }
    }
    for(i=0;i<k;i++)
    {
        int r=t[i]-'0';
        a=-qr-qi+r; 
        b=qr-qi;
        qr=a;qi=b;
    }
    if(b==0)
    {
        printf("%lld\n",a);
    }
    else
    {
        if(a!=0)
        {
            printf("%lld",a);
            if(qi>0) printf("+");
        }
        if(b==1) printf("i\n");
        else if(qi==-1) printf("-i\n");
        else 
        {
            printf("%lldi\n",b);
        }
    }

    return 0;
}
