#include<stdio.h>
#include<string.h>

void trans2(int n,int bits)
{
    int i=0,N=bits*3+1;
    int b[N];
    for(int j=0;j<N;j++) b[j]=0;
    for(i=0;i<N;i++)
    {
        b[i] = n&1;
        n>>=1;
    }
    for(;i;)
    {
        printf("%d",b[--i]);
    }
}

int main()
{
    char s[500];
    gets(s);
    int len=strlen(s);
    printf("0001");
    trans2(len,3);

    int times = len/3;
    int last;
    if(times*3<len)
    {
        last=len%3;
        times++;
    }
    else last=3;

    for(int i=0;i<times;i++)
    {
        int eachT=0;
        for(int j=0;j<3;j++)
        {
            if(s[i*3+j]=='\0') break;
            eachT*=10;
            eachT+=(s[i*3+j]-'0');
        }
        (i!=times-1)?trans2(eachT,3):trans2(eachT,last);
    }
    return 0;
}
