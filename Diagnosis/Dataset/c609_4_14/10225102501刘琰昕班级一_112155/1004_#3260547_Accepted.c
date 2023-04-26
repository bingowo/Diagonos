#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char base[]={"0123456789ABCDEF"};
//将A进制转换为10进制
long long AtoT(const int A,const char *s)
{
    char *p=s;long long T=0;
    while(*p)
    {
        if(isdigit(*p))T=T*A+*p-'0';
        else T=T*A+toupper(*p)-'A'+10;
        p++;
    }
    return T;
}
//10进制转换为B进制
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
    if(T==0)printf("0");
    else TtoB(T,B);
    return 0;
}
