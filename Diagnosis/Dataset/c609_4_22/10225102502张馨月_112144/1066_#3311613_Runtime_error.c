#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;//number of weights
    scanf("%d",&n);
    int w[10];
    int sum=0;
    for(int k=1;k<=n;k++){
        scanf("%d",&w[k]);
        sum=sum+w[k];
    }
    int f[10][500]={0};
    f[0][0]=1;
    //for(int p=0;p<=sum;p++)
    //    f[0][p]=1;
    int i,j;
    for(i=1;i<=n;i++){
        for(j=0;j<=sum;j++){
            if (f[i-1][j]){
                f[i][j]=1;
                //printf("f%d%d: %d\n",i,j,f[i][j]);
                f[i][abs(j+w[i])]=1;
                f[i][abs(j-w[i])]=1;
            }
        }
    }
    for(int d=1;d<=sum;d++){
    //printf("%d %d",d,f[n][d]);
    //getchar();
    printf("%d",f[n][d]);
    }
   

    return 0;
}