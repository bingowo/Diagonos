#include <stdio.h>
#include <string.h>
long long int Ato10(int A,char s[1000])
{
    int power=1,i;
    long long int sum;
    for(i=strlen(s);i>=0;i--)
    {
        if(isdigit(s[i]))
        {
            sum=sum+(s[i]-'0')*power;
        }
        else
        {
            switch(s[i])
            {
                case 'A':sum=sum+10*power;break;
                case 'B':sum=sum+11*power;break;
                case 'C':sum=sum+12*power;break;
                case 'D':sum=sum+13*power;break;
                case 'E':sum=sum+14*power;break;
                case 'F':sum=sum+15*power;break;
            }
        }
        power*=A;
    }
    return sum;
}
void tentoB(long long int N,long long int B)
{
    char table[]="0123456789ABCDEF";
    if(N>0)
    {
        tentoB(N/B,B);
        putchar(table[N%B]);
    }
}
int main()
{
    int A,B,s[10000],N;
    scanf("%d %s %d",&A,&s,&B);
    N=Ato10(A,s);
    tentoB(N,B);
    return 0;
}
