#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char base[]={"0123456789ABCDEF"};

long long AtoT(int A,char *s)
{
    char *p;long long T=0;
    p=s;
    while(*p)
    {
        if((*p)>='0'&&(*p)<='9')T=T*A+*p-'0';
        else T=T*A+toupper(*p)-'A'+10;
        p++;
    }
    return T;
}

void TtoB(long long T,int B)
{
    if(T>0)
    {
        TtoB(T/B,B);
        printf("%c",base[T%B]);
    }
}

int main()
{
    int A,B;char n[100]={0};long long T=0;
    scanf("%d%s%d",&A,n,&B);
    T=AtoT(A,n);
    TtoB(T,B);
    return 0;
}
