#include <stdio.h>
#include <malloc.h>
int main()
{
    long long n,sum = 0,x = 0,y = 0;
    long long *a = (long long *)malloc(10000000*sizeof(long long));
    scanf("%lld",&n);
    int i;
    if(n==0) printf("(0,0)");
    else
    {for(i = 1;;i++)
    {
        sum += i;
        a[i] = 2*sum;
        //printf("%lld ",a[i]);
        if(a[i-1]<=n&&a[i]>n) break;
    }
    if(i%2==0)
    {
        if(n-a[i-1]<= i) {x = -i/2;y = i/2-(n-a[i-1]);}
        else {x=i/2-(a[i]-n);y = -i/2;}
    }
    else if(i%2==1)
    {
        if(n-a[i-1]<=i){ x = i/2;y = -i/2+(n-a[i-1]);}
        else {x = -i/2-1+(a[i]-n);y = i/2+1;}
    }
    printf("(%lld,%lld)",x,y);
    }
    free(a);
    return 0;

}
