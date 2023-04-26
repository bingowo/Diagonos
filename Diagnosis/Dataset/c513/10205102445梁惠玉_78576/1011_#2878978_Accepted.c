#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1001];
    scanf("%s",s);
    int k=0;
    int t[1001];
    for(int i=2;i<strlen(s);i++)
    {
        int d;
        if(s[i]>='A'){
            d=s[i]-'A'+10;
        }
        else{d=s[i]-'0';}
        unsigned int flag=0x8;
        while(flag)
        {
            if(d&flag) t[k++]=1;
            else t[k++]=0;
            flag=flag>>1;
        }
    }
    long long int qr=0,qi=0;
    long long int a,b;
    for(int i=0;i<k;i++)
    {
       int r=t[i];
       a=-qr-qi+r;
       b=qr-qi;
       qr=a;qi=b;

    }
    if(b==0)
    {
        printf("%lld\n",a);
    }
    else{
        if(a!=0)
        {
            printf("%lld",a);
            if(b>0){printf("+");}
        }
        if(b==1) printf("i\n");
        else if(b==-1) printf("-i\n");
        else{printf("%lld",b);printf("i\n");}

    }
    return 0;
}
