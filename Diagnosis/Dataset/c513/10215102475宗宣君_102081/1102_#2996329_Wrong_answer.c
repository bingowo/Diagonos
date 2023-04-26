#include <stdio.h>
#define N 999792010816
int main()
{
    long long n,a[11] = {0},sum = 0,x = 0,y = 0;
    scanf("%lld",&n);
    int i;
    if(n==0) printf("(0,0)");
    else
    {if(n>N)
    {sum = 499896505356;
    for(i = 999897;;i++)
    {
        sum += i;
        a[i%10] = 2*sum;
        if(a[(i-1)%10]<=n&&a[i%10]>n) break;
    }}
    else{
        for(i = 1;;i++)
    {
        sum += i;
        a[i%10] = 2*sum;
        //printf("%lld ",a[i]);
        if(a[(i-1)%10]<=n&&a[i%10]>n) break;
    }
    }
    printf("%lld ",sum);
    if(i%2==0)
    {
        if(n-a[(i-1)%10]<= i) {x = -i/2;y = i/2-(n-a[(i-1)%10]);}
        else {x=i/2-(a[i%10]-n);y = -i/2;}
    }
    else if(i%2==1)
    {
        if(n-a[(i-1)%10]<=i){ x = i/2;y = -i/2+(n-a[(i-1)%10]);}
        else {x = -i/2-1+(a[i%10]-n);y = i/2+1;}
    }
    printf("(%lld,%lld)",x,y);
    }
    return 0;

}
