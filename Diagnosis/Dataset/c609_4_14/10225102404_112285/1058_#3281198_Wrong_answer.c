#include<stdio.h>

int main()
{
    int r,k=0,c[1000];
    long long n;
    scanf("%lld",&n);
    if(n==0)
    {
        printf("%d",0);
        return 0;
    }
    while(n)
    {
        r=n%-2;
        n/=-2;
        if(r>=0)
        {
            c[k++]=r;
        }
        else
        {
            c[k++]=r-(-2);
            n++;
        }
    }
    for(int i=k-1;i>=0;i--)
    {
        printf("%d",c[i]);
    }
    return 0;

}
