#include <stdio.h>

char table[]="0123456789ABCDEF";
void trans(int N,int R)
{
    if(N>0)
    {
        trans(N/R,R);
        putchar(table[N%R]);
    }
    if(N==0)
        printf("0");
}

int main()
{
    int A,B;
    char n[32];
    scanf("%d %s %d",&A,n,&B);
    int num=0;
    int i=0;
    while(n[i])
    {
        if(n[i]>='a'&&n[i]<='f')
            n[i]=n[i]-'a'+10;
        else if(n[i]>='A'&&n[i]<='F')
            n[i]=n[i]-'A'+10;
        else
            n[i]-='0';
        num=num*A+n[i];
        i++;
    }
    trans(num,B);
    return 0;
}
