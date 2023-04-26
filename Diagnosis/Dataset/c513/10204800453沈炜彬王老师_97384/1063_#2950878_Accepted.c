#include <stdio.h>

long long int max(long long int num1,long long int num2);
long long int min(long long int num1,long long int num2);
long long int cal(long long int num1,long long int num2);

int
main()
{
    long long int x,y;
    long long int res;
    
    scanf("%lld%lld",&x,&y);
    res = cal(max(x,y),min(x,y));
    
    printf("%lld\n",res);
    
    return 0;
}


long long int
max(long long int num1,long long int num2)
{
    return num1>num2?num1:num2;
}


long long int
min(long long int num1,long long int num2)
{
    return num1<num2?num1:num2;
}



long long int
cal(long long int num1,long long int num2)
{
    if (num1 == num2)
    {
        return num2*4;
    }
    else
    {
        if (num1%num2 == 0)
        {
            return num1*4 ;
        }
        else
        {
            return num1/num2 * 4 * num2 + cal(max(num1%num2, num2),min(num1%num2, num2));
        }
    }
}