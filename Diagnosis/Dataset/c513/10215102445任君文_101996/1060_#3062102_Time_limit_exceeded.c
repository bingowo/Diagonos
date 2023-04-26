#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define M 100
int is_number(char x)
{
    if((x>='0')&&(x<='9'))
    {
        return 1;
    }
    else 
     return 0;
}
int main()
{
    long long number=0;
    int L = 0,MAX=0;
    while(scanf("%lld",&number)!=EOF)
    {
        while(number>0)
        {
            number=number/10;
            L++;
        }
        if(MAX<L)
        {
            MAX=L;
        }
    }
    printf("%d\n",MAX);
    return 0;   
}