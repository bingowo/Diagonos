#include <stdio.h>
#include <stdlib.h>
unsigned long long cntRoute(int n)
{
    static unsigned long long rslt[50];
    if(rslt[n-1])return rslt[n-1];
    rslt[0]=1,rslt[1]=2,rslt[2]=4,rslt[3]=8;
    if(n==1)return rslt[0];
    else if(n==2)return rslt[1];
    else if(n==3)return rslt[2];
    else if(n==4)return rslt[3];
    else if(n>4)
        {
            rslt[n-1]=cntRoute(n-1)+cntRoute(n-2)+cntRoute(n-3)+cntRoute(n-4);
            return rslt[n-1];
        }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%llu",i,cntRoute(n));
    }
    return 0;
}
