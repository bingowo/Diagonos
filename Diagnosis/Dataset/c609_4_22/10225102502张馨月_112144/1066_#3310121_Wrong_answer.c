//1066
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;//number of weights
    scanf("%d",&n);
    int w[10];
    int sum=0;
    for(int k=0;k<n;k++){
        scanf("%d",&w[k]);
        sum=sum+w[k];
    }
    int f[10][1000]={0};
    f[0][0]=1;
    int i,j;
    for(i=1;i<=n;i++){
        for(j=0;j<=sum;j++){
            if (f[i-1][j]){
                f[i][j]=1;
                f[i][abs(j+w[i])]=1;
                f[i][abs(j-w[i])]=1;
            }
        }
    }
    printf("%d",f[n][j]);
    
    return 0;
}