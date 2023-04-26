#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double row;
    double theta;
} P;

int cmp(const void* m, const void* n) {
    return *((int*)m) - *((int*)n);
}
 
int main()
{
    int n, a[100000], sum=0;
    scanf("%d",&n);
    for(int i=0; i<n; ++i) scanf("%d",&a[i]);
    qsort(a, n, sizeof(int), cmp);
    for(int i=0; i<n/2; ++i) {
        sum += abs(a[2*i+1]-a[2*i]);
    }
    printf("%d\n",sum);
    return 0;
}
