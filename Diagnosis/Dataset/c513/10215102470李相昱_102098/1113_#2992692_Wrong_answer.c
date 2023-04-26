#include <stdio.h>
#include <string.h>
int main() {
    int a[100];
    memset(a,0,100*sizeof(int));
    a[1]=1;
    a[2]=1;
    int n,k;
    scanf("%d%d",&k,&n);
    for(int i=3;i<n;i++){
        if(i<k){
            a[i]=2*a[i-1];
        }else{
            a[i]=2*a[i-1]-a[i-k-1];
        }
    }
    printf("%d",a[n-1]);
    return 0;
}
