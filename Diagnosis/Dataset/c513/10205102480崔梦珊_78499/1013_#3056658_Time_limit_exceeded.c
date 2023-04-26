#include<stdio.h>
int main()
{
    char c;
    long long A=0;
    long long B=0;
    long long C=0;
    long long point=0;
    while((c=getchar())!='\n')
    {
        if(c=='1')
        {
            A=A*3+1;
        }
        if(c=='0')
        {
            A=A*3;
        }
        if(c=='2')
        {
            A=A*3-1;
        }
        if(c=='.')
        {
            break;
        }
    }
    /*printf("%lld",A);*/
    while((c=getchar())!='\n')
    {
        point++;
        if(c=='1')
        {
            B=B*3+1;
        }
        if(c=='0')
        {
            B=B*3;
        }
        if(c=='2')
        {
            B=B*3-1;
        }
    }
    /*printf("%lld",B);
    printf("%lld",C);*/
    if(A==0)
    {
        C=pow(3,point);
        printf("%lld %lld",B,C);
    }
    if(B==0)
    {
        printf("%lld",A);
    }
    if(A*B>0)
    {
        C=pow(3,point);
        B=C-B;
        printf("%lld %lld %lld",A,B,C);
    }
    if(A>0&&B<0)
    {
        A--;
        B=-B;
        C=pow(3,point);
        B=C-B;
        printf("%lld %lld %lld",A,B,C);
    }
    if(A<0&&B>0)
    {
        A++;
        B=-B;
        C=pow(3,point);
        B=C+B;
        printf("%lld %lld %lld",A,B,C);
    }

}
