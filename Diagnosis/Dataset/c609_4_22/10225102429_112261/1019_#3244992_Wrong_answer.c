#include <stdio.h>
#include <stdlib.h>
#define N 1000000
int a[N];
int cmp(const void*a, const void* b){
    int xa = *(int*)a,xb = *(int*)b,xxa = xa,xxb = xb;
    while(xa&&xb){
        xa/=10;
        xb/=10;
    }
    if(xa){
        return -1;
    }
    if(xb){
        return 1;
    }
    else{
        return xxa-xxb;
    }
}
int main()
{
    int i = 0;
    while(~scanf("%d",&a[i++]));
    qsort(a,i,sizeof(int),cmp);
    for(int j = 0; j<i; j++){
        printf("%d ",a[j]);
    }
    return 0;
}