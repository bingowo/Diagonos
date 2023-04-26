#include <stdio.h>
#include <stdlib.h>

void plus(int p[101],int q[101]){
    for(int i=0;i<=100;i++){
        p[i]=p[i]+q[i];
    }
    for(int i=100;i>=0;i--){
        p[i-1]=p[i-1]+p[i]/10;
        p[i]=p[i]%10;
    }
}

int main(){
    int k,n;
    scanf("%d%d",&k,&n);
    int a[n+1][101];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=100;j++){
            a[i][j]=0;
        }
    }
    a[2][100]=1;
    a[3][100]=1;
    for(int i=4;i<=n;i++){
        for(int j=i-k;j<i;j++){
            if(j>=0){
                plus(a[i],a[j]);
            }
        }
    }
    if(n==1)printf("0");
    else{
    int index=0;
    while(a[n][index]==0)index++;
    for(int i=index;i<=100;i++){
        printf("%d",a[n][i]);
    }
    }
    return 0;
}
