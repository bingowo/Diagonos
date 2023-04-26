#include <stdio.h>
int main()
{
    long long n,a[100000]= {0},sum = 0,x = 0,y = 0;
    scanf("%lld",&n);
    int i;
    if(n==0) printf("(0,0)");
    else
    {for(i = 1;;i++)
    {
        sum += i;
        a[i] = 2*sum;
        //printf("%lld ",a[i]);
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
    }
    return 0;

}
