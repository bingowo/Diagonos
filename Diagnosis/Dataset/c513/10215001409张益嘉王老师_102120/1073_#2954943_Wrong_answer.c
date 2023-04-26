#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int baohan(unsigned long long x)
{
    int i=0;
    while(x>0)
    {
        if((x%10)==9) return i*10-1;
        x/=10;
        i++;
    }
    return 1;
}

int jud(unsigned long long x)
{
    char*s;
    if((x%9)==0) return -1;
    else return 1;

}

int main()
{
    unsigned long long a,b,i,co=0;
    unsigned long long pan;
    scanf("%llu%llu",&a,&b);
    //printf("test: a=%llu  b=%llu\n",a,b);
    for(i=a;i<=b;i++)
    {
        
        if(jud(i)==1)
        {
            pan=baohan(i);
             if(pan==1) co++;
             else if(pan==-1);
             else i+=pan;
        }
        //printf("i=%llu\n",i);
    }
    printf("%llu\n",co);
    return 0;
}
