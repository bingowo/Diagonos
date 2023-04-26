#include <stdio.h>

int main()
{
    long long int x;
    char c;
    int A[8];
    int R1=0,I1=0;
    int R2=-1,I2=1;
    int *p=A;
    p=p+7;
    while((c=getchar())!=EOF)
    {
        if(c=='x')
        {
            c='0';
        }
        x=x*16+c-'0';
    }

    while(x)
    {
        *p=x%2;
        x=x/2;
        p--;
    }
    for(int i=0;i<8;i++)
    {printf("%d\n",A[i]);}
    p++;
    while(p<=A+7)
    {
        R1=R1*R2-I1*I2;
        I1=R1*I2+R2*I1;
        R1=R1+*p;
        p++;
    }
    printf("%d",R1);
    if(I1>0)
    {
        printf("+%di",I1);
    }
    else if(I1<0)
    {
        printf("%di",I1);
    }
    else return 0;

}