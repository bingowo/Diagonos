#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    char s[10];
    int a[5];
    scanf("%s",s);
    int len=strlen(s);
    int sum=0;
    for(int j=2;j<len;j++)
    {
        if(s[j]>='A')
            s[j]=s[j]-'A'+10;
        else
            s[j]=s[j]-'0';
        sum=sum+s[j]*pow(16,len-j-1);
    }
    int b=3;
    for(int m=0;m<4;m++)
    {
        a[m]=0;
    }
    do{
        a[b]=sum%2;
        b--;
        sum=sum/2;
    }while(sum>0&&b>=0);
    long long int qr=0,qi=0;
    long long int c,d;
    for(int x=0;x<4;x++)
    {
        c=-qr-qi+a[x];
        d=qr-qi;
        qr=c;
        qi=d;
    }
    if(qi==0)
    {
        printf("%lld\n",qr);
    }
    else
    {
        if(qr!=0)
        {
            printf("%lld",qr);
            if(qi>0)
                printf("+");
        }
        if(qi==1)
            printf("i\n");
        else if(qi==-1)
            printf("-i\n");
        else
        {
            printf("%lld",qi);
            printf("i\n");
        }
    }
    return 0;
}
