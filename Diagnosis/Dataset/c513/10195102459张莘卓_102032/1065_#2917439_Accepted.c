#include <stdio.h>
#include <stdlib.h>

int fib[21] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765};

int sum(int n) {
    int ans = 0;
    for(int i=1; i<=n; ++i) ans += fib[i];
    return ans;
}

int main()
{
    int a, n, m, x;
    scanf("%d %d %d %d",&a, &n, &m, &x);
    if(x == n) printf("0");
    else if(n <= 3) printf("%d",a);
    else {
        int t = (m - a*(2+sum(n-5)))/sum(n-4);
        if(x==1 || x==2) printf("%d",a);
        else printf("%d",a*(2+sum(x-4))+t*sum(x-3));
    }
    printf("\n");
    return 0;
}
