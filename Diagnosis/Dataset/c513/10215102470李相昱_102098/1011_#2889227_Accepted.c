#include <stdio.h>
#include <string.h>
int main(){
    int k=0;
    int test=0;
    char s[1000];
    scanf("0x%s",s);
    char t[1000];
    for(int i=0;i<strlen(s);i++)
    {
        int d;
        if(s[i]>='A')
            d=s[i]-'A'+10;
        else
            d=s[i]-'0';
        unsigned int flag=0x8;
        while(flag)
        {
            if(d&flag) t[k++]='1';
            else t[k++]='0';
            flag=flag>>1;
        }
    }
    //t[k]=0;
    //while(t[test]=='0')
    //{
       // test++;
    //}
    //test++;

    long long int qr=0,qi=0;
    long long int a,b;
    for(int i=test;i<k;i++)
    {

        int r=t[i]-'0';
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;qi=b;

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
            if(qi>0) printf("+");
        }
        if(qi==1) printf("i\n");
        else if(qi==-1) printf("-i\n");
        else {printf("%lld",qi);printf("i\n");}
    }
    return 0;

}
