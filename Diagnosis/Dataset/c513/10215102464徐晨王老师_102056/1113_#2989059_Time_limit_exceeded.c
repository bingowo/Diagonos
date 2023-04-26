#include <stdio.h>
#include <stdlib.h>
int main(){
    int k,n;
    scanf("%d%d",&k,&n);
    int a[n+1];
    a[0]=0;
    a[1]=2;
    for(int i=3;i++;i<=n){
        for(int j=i-k;j<k;j++){
            if(j>=0)a[i]=a[i]+a[j];
        }
    }
    printf("%d",a[n]);
}