#include <stdio.h>
#include <stdlib.h>

void fun(int a,int b)
{
    int k=b,t=0;
    while(k!=0)
    {
        t=t*10+k%10;
        k=k/10;
    }
    if(b==t) printf("%d %d",a-1,b);
    else return fun(a+1,b+t);
}

int main()
{
    int n;
    int a=1;
    scanf("%d",&n);
    fun(a,n);
    return 0;
}
