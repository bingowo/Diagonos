#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(int x,int* w,int n){
    if(x==0) return 1;
    if(n==0) return 0;
    int wi=w[n-1];
    return find(x-wi,w,n-1)||find(x+wi,w,n-1)||find(x,w,n-1);
}
int main()
{
    int n,i,a[100],max=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        max += a[i];
    }
    for(i=1;i<max+1;i++){
        printf("%d",find(i,a,n));
    }
    printf("\n");
    return 0;
}
