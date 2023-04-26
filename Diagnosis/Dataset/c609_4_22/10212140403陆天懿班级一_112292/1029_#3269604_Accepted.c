#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

typedef long long ll;
typedef unsigned long long ull;

#define N 505
#define L 1005
int ni[L],a[N];
int n,m,ti;

int Cmp(const int* pa, const int* pb){return ni[*pa]-ni[*pb];}

int main(){
    scanf("%d",&m);
    for(int i=0;i<=1000;i++) ni[i]=i+2000;
    for(int i=0;i<m;i++){
        scanf("%d",&ti);
        ni[ti]=i;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);

    qsort(a,n,sizeof(a[0]),Cmp);
    for(int i=0;i<n;i++){
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");

    return 0;
}
