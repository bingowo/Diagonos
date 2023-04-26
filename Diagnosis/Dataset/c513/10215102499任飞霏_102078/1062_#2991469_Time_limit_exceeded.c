#include <stdio.h>
#include <stdlib.h>

long long int step(int n)
{
    if(n<=0)return 0;
    if(n==1||n==2)
        return n;
    else if(n==3)return  4;
    else if(n==4)return 8;
    else
        return step(n-1)+step(n-2)+step(n-3)+step(n-4);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int n;
        scanf("%d",&n);
        printf("%lld\n",step(n));

    }
    return 0;
}
