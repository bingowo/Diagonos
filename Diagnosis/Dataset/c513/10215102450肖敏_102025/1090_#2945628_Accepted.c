#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        double m,j;
        m=modf(n*1.0* log10(n*1.0),&j);
        m= modf(pow((double )10,m),&j);
        printf("%d\n",(int)j);
        scanf("%d",&n);
    }
    return 0;
}
