#include <stdio.h>
#include <stdlib.h>
long long f(int n);
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
       int n;
       scanf("%d",&n);
       printf("case #%d:\n%lld\n",i,f(n));
       return 0;
    }


}
long long f(int n)
{
        if(n==0)return 1;
        else if(n==1)return 2;
        else return f(n-1)*2;
}
