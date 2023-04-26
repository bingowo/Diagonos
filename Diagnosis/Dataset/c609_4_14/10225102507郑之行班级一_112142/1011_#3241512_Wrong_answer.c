#include <stdio.h>
#include <stdlib.h>

#define MXL 100

int gcd(int x, int y)
{	if (y)
        return gcd(y, x%y);
    else
        return x;
}

int main()
{
    char input[MXL];
    char* p=input;
    long long A=0,B=0,C=1,REM=0;
    int j,rem[MXL];
    for (int i=0;i<MXL;i++)input[i]='\0';
    scanf("%s",input);

    while(*p!='.' && *p!='\0')
    {
        A*=3;
        if(*p=='2')
        {
            A += (-1); p++;
        }
        else
        {
            A += (*p-'0'); p++;
        }
    }
    if (A!=0) printf("%lld ",A);

    if(*p=='.')
    {
        p++;
        for(j=0;*p!='\0';j++)
        {
            B*=3;C*=3;
            if(*p=='2')
            {
                B +=(-1);
                p++;
            }
            else
            {
                B += (*p-'0');
                p++;
            }
        }

        long long G=gcd(B,C);
        B/=G;C/=G;

        if(B<0)
        {
            B+=C;
            A-=1;
        }
        printf("%lld %lld\n",B,C);
    }
    return 0;
}
