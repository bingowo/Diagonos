#include <stdio.h>
#include <stdlib.h>


unsigned long long taibo(int x)
{
    unsigned long long re;
    if(x==0) return 0;
    else if(x==1) return 1;
    else if(x==2) return 1;
    return taibo(x-1)+taibo(x-2)+taibo(x-3);
}


int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        unsigned long long ans=taibo(n);
        printf("case #%d:\n%llu\n",i,ans);

    }
    return 0;
}
