#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int a[100005],n,r;

int Cmp(const int* pa,const int* pb){
    return *pa-*pb;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    qsort(a,n,sizeof(a[0]),Cmp);
    for(int i=0;i<n;i+=2){
        r+=a[i+1]-a[i];
    }
    printf("%d\n",r);

    return 0;
}
