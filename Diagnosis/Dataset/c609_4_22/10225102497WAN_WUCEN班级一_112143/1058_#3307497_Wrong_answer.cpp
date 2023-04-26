#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cnt;
    int v[1000];
    int sign;
}bigint;

bigint DIVint(const bigint n,int divisor,int* remainder);

int main()
{
    char c=0;
    bigint n={0,{0},0};
    int result[500]={0},j=0;
    scanf("%c",&c);
    if(c=='-')
    {
        n.sign=-1;
        scanf("%c",&c);
    }
    else
        n.sign=1;
    for(int i=0;c!='\n';i++)
    {
        n.cnt++;
        n.v[i]=c-'0';
        scanf("%c",&c);
    }
    while(n.cnt)
    {
        n=DIVint(n,2,result+j);
        j++;
    }
    j--;
    for(;j>=0;j--)
        printf("%d",result[j]);
    return 0;
}

bigint DIVint(const bigint n,const int divisor,int* remainder)
{
    bigint quotient={0,{0},0};
    const int absbase=(divisor>0)?divisor:-divisor;
    if(divisor<0)
    {
        if(n.sign>0)
            quotient.sign=-1;
        else
            quotient.sign=1;
    }
    const int count=n.cnt;
    int Remainder=0;
    for(int i=0;i<count;i++)
    {
        Remainder*=10;
        quotient.v[i]=(n.v[i]+Remainder)/absbase;
        Remainder=(n.v[i]+Remainder)%absbase;
    }
    if(n.sign<0&&Remainder)
    {
        Remainder=-Remainder;
        quotient.v[count-1]++;
        for(int i=count-1;quotient.v[i]==10;i--)
        {
            quotient.v[i-1]++;
            quotient.v[i]=0;
        }
        Remainder+=absbase;
    }
    *remainder=Remainder;
    int j=0;
    for(j=0;quotient.v[j]==0;j++);
    for(int i=0;j<count;i++,j++)
    {
        quotient.v[i]=quotient.v[j];
        quotient.cnt++;
    }
    return quotient;
}
