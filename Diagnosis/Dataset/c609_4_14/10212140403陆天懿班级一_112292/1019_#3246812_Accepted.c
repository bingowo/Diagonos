#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int a[1000005],n,r;

int Cmp(const int* pa,const int* pb){
    int la = log10(labs(*pa)),
        lb = log10(labs(*pb));
    if(la!=lb) return lb-la;
    return *pa>*pb;
}

int main(){
    while(scanf("%d",a+n)!=EOF)
        n++;
    qsort(a,n,sizeof(a[0]),Cmp);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}
