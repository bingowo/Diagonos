#include <stdio.h>
#include <stdlib.h>
int count(unsigned int d)
{
    int c=0;
    while(d)
    {
        c+=(d&1);
        d>>1;
    }
    return c;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        unsigned int a,b;
        scanf("%u %u",&a,&b);
        printf("case #%d:\n%d\n",count(a^b));
    }
    return 0;
}