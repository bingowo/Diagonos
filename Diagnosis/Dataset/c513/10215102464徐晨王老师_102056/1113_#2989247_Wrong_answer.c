#include <stdio.h>
#include <stdlib.h>
int main(){
    int k,n;
    scanf("%d%d",&k,&n);
    int a[n+1];
    a[0]=0;
    a[1]=0;
    a[2]=1;
    for(int i=3;i<=(n+1);i++){
        a[i]=0;
    }

    for(int i=3;i<=n;i++){
        for(int j=i-k;j<i;j++){
            if(j>=0){a[i]=a[i]+a[j];
            }
        }
    }
    printf("%d",a[n]);
    return 0;
}
