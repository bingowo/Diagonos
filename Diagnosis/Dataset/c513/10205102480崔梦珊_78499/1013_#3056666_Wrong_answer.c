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
            char ch;
            while((ch=getchar())!='\n')
            {
                point++;
                if(ch=='1')
                {
                    B=B*3+1;
                }
                if(ch=='0')
                {
                    B=B*3;
                }
                if(ch=='2')
                {
                    B=B*3-1;
                }
            }
            break;
        }
    }
    /*printf("%lld\n",A);
    printf("%lld\n",B);
    printf("%lld\n",C);*/
    if(A==0&&B!=0)
    {
        C=pow(3,point);
        printf("%lld %lld",B,C);
    }
    if(A==0&&B==0)
    {
        printf("0");
    }
    if(A!=0&&B==0)
    {
        C=pow(3,point);
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
