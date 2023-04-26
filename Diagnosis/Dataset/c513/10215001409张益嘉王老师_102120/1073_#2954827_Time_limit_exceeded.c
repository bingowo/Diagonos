#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int baohan(unsigned long long x)
{
    while(x>0)
    {
        if((x%10)==9) return -1;
        x/=10;
    }
    return 1;
}

int jud(unsigned long long x)
{
    char*s;
    if((x%9)==0) return -1;
    else if(baohan(x)==-1) return -1;
    else return 1;

}

int main()
{
    unsigned long long a,b,i,co=0;
    scanf("%llu%llu",&a,&b);
    for(i=a;i<=b;i++)
    {
        if(jud(i)==1) co++;
    }
    printf("%llu\n",co);
    return 0;
}
