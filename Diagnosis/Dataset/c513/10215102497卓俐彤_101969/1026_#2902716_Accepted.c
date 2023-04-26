#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int compar(const void*a,const void*b){
    int n1,n2;
    n1=*((int*)a);
    n2=*((int*)b);
    return n1-n2;
}



int main(){
    int n;
    scanf("%d",&n);
    int list[n];
    for(int i=0;i<n;i++)scanf("%d",&list[i]);
    qsort(list,n,sizeof(list[0]),compar);
    int minsum=0;
    for(int i=0;i<n/2;i++){
        minsum+=abs(list[2*i]-list[2*i+1]);
    }
    printf("%d",minsum);
    return 0;
}
