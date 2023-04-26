#include<stdio.h>

void func();
int main()
{
    int T;
    char s[120];
    scanf("%d",&T);
    gets(s);
    for (int i=0;i<T;i++)
    {
        func();
    }
    return 0;
}

void func()
{
    char c[120];
    gets(c);
    int i=0,ans,gcd,numer=0,denom=0;
    while(c[i]!='\0')
    {
        for (int j=0;j<8;j++)
        {
            
            if ((c[i]>>j)&1==1)
                numer++;
        }
        i++;
    }
    denom=i*8;
    for(int j=1;j<=numer&&j<=denom;j++)
    {
        if(numer%j==0 && denom%j==0)
            gcd = j;
    }
    if (gcd>1)
    {
        numer/=gcd;denom/=gcd;
        printf("%d/%d\n",numer,denom);
    }
    else
        printf("%d/%d\n",numer,denom);
}