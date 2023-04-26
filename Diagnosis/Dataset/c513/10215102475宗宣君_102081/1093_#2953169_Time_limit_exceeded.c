#include <stdio.h>
int main()
{
    long long int n,i,p,m;
    scanf("%lld",&n);
    for(i = n+1;;i++)
    {
        p = i;m = 0;
        while(p!=0&&m!=9)
        {
            m = p%10;
            p = p/10;
        }
        if(i%9!=0&&p==0&&m!=9) break;
    }
    printf("%lld",i);
    return 0;
}