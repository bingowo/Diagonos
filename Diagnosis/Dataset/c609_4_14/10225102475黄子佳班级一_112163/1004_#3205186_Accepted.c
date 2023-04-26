#include <stdio.h>
#include <string.h>

char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void trans_1(long long N,int R)
{
    if(N>0)
    {
        trans_1(N/R,R);
        putchar(table[N%R]);
    }
}

long long trans_2(char N[],int R)
{

    int i,sum=0;
    for(i=0;i<strlen(N);i++)
    {
        if(N[i]>='A'&&N[i]<='F')sum=sum*R+N[i]-'A'+10;

        else if(N[i]>='a'&&N[i]<='f')sum=sum*R+N[i]-'a'+10;

              else sum=sum*R+N[i]-'0';
    }
    return sum;

}

int main()
{
    int A,B;
    char n[100];
    scanf("%d",&A);
    scanf("%s",n);
    scanf("%d",&B);
    if(n[0]=='0'&&strlen(n)==1)
    {
        printf("0");
        return 0;
    }
    long long M;
    M=trans_2(n,A);
    trans_1(M,B);
    return 0;
}