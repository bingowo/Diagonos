#include <stdio.h>
int main()
{
    long long n,a[10000]= {0},sum = 0,x,y;
    scanf("%lld",&n);
    int i;
    for(i = 1;;i++)
    {
        sum += i;
        a[i] = 2*sum;
        if(a[i-1]<n&&a[i]>=n) break;
    }
    if(i%2==0)
    {
        if(n-a[i-1]<= i) {x = -i/2;y = i/2-(n-a[i-1]);}
        else {x=i/2-(a[i]-n);y = -i/2;}
    }
    else if(i%2==1)
    {
        if(n-a[i-1]<=i){ x = i/2;y = -i/2+(n-a[i-1]);}
        else {x = i/2-(a[i]-n);y = i/2+1;}
    }
    printf("(%lld,%lld)",x,y);
    return 0;

}
