#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned long long pingfang(int mi)
{
    int i;
    unsigned long long re=1;
    for(i=0;i<mi;i++)
    {
        re*=10;
    }
    return re;

}

int baohan(unsigned long long x)
{
    int i=0,mid=0,len=0,l;
    unsigned long long y=x;
    while(y>0)
    {
        y/=10;
        len++;
    }
    while(x>0)
    {
        l=pingfang(len-1);
        if((x/l)==9)
           {
                mid=x%l;
               return l-mid-1;
           }

        x%=l;
        len--;
    }
    return 1;
}

int jud(unsigned long long x)
{
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
        //pan=qujian(i);
        //printf("pan=%llu\n",pan);
        //if(pan!=1) {i+=pan;continue;}
        if(jud(i)==1)
        {
            pan=baohan(i);
            //printf("pan=%d i=%d\n",pan,i);
             if(pan==1) co++;
             else if(pan==-1);
             else i+=pan;
        }
        //printf("i=%llu\n",i);
    }
    printf("%llu\n",co);
    return 0;
}
