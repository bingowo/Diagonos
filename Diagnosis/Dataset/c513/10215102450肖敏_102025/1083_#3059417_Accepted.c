#include <stdio.h>
int fun(int n)
{
    if(n<5)
        return 0;
    else
    {
        return(n/5+fun(n/5));
    }
    
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int sum;
        sum=fun(n);
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;
}
