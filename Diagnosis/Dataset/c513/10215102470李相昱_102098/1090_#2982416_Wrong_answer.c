#include <stdio.h>
#include <math.h>
int main() {
    int N;
    while(scanf("%d",&N)&&N!=0) {
        double a = N* log10(N);
        int b = (int) pow(10,a);
        printf("%d\n",b);
    }
    return 0;
}
