#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int qvalue(char *q)
{
    int value;
    if(*q=='2')
        value=-1;
    else if(*q=='0')
        value=0;
    else if(*q=='1')
        value=1;
    return value;
}
int main()
{
    char c[31],*p,*q;
    int i;
    long long int A,B,C;
    A=B=0;C=1;
    memset(c,0,sizeof(c));
    gets(c);
    if(!strchr(c,'.'))
    {
        for(q=c;*q!=0;q++)
        {
            A=A*3+qvalue(q);
        }
        printf("%lld",A);
    }
    else
    {
        p=strchr(c,'.');
        if(c[0]!='0')
        {
            for(q=c;q!=p;q++)
            {
                A=A*3+qvalue(q);
            }
            for(q=p+1;*q!=0;q++)
            {
                B=B*3+qvalue(q);
                C*=3;
            }

            if(B<0)
            {
                A--;
                B=C+B;
            }
            printf("%lld %lld %lld",A,B,C);
        }
        else if(c[0]=='0')
        {
            for(q=p+1;*q!=0;q++)
            {
                B=B*3+qvalue(q);
                C*=3;
            }
            printf("%lld %lld",B,C);
        }
    }

    return 0;
}
