#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    unsigned long long int x,y;
    unsigned long long int n;
    scanf("%llu%llu",&x,&y);
    unsigned long long int sum = 0;
    while(x!=0&&y!=0)
    {
        if(x>y){n = x/y;x = x-n*y;sum=sum+4*n*y;}
        else if(x<y){n = y/x;y = y-n*x;sum=sum+4*n*x;}
        else if(x==y){sum =sum+4*x;break;}
    }
    printf("%llu",sum);
    return 0;

}

