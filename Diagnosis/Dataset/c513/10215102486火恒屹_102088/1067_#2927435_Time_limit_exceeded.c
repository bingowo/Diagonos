#include <stdio.h>
#include <stdlib.h>
long long f(int a)
{
    if(a==0)
        return 0;
    else if((a==1)||(a==2))
        return 1;
    else
        return f(a-1)+f(a-2)+f(a-3);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int a;
        scanf("%d",&a);
        printf("%lld\n",f(a));
    }
    return 0;
}
