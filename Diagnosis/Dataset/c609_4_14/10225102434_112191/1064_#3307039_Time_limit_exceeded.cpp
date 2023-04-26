#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    unsigned long long int x,y;
    scanf("%llu%llu",&x,&y);
    unsigned long long int sum = 0;
    x = x-y;
    sum=sum+4*y;
    while(x!=0&&y!=0)
    {
        if(x>y){x = x-y;sum=sum+4*y;}
        else if(x<y){y = y-x;sum=sum+4*x;}
        else if(x==y){sum =sum+4*x;break;}
    }
    printf("%llu",sum);
    return 0;

}
