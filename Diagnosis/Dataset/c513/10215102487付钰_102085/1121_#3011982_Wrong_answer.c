#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1],sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int j,k,m,x,b[sum+1],sum1=0;
    //printf("%d\n",sum);
    for(j=1;j<=sum;j++){
        b[j]=0;
        for(k=1;k<=n;k++){
        if(b[j]==0){
            if(j==a[k]){
            b[j]=1;
        }
        if(j==sum-a[k]){
            b[j]=1;
        }
        }
        }
    }

    for(j=1;j<=sum;j++){
        if(b[j]==0){
            for(k=1;k<=n;k++){
                for(m=k+1;m<=n;m++){
                    if(j==abs(a[m]-a[k])){
                        b[j]=1;
                    }
                    if(j==abs(a[m]+a[k])){
                        b[j]=1;
                    }
                    sum1=a[m]+a[k];
                    if(j==sum-sum1){
                        b[j]=1;
                    }
                    for(x=n;x>=1;x--)
                    if(a[x]>sum1){
                       if(j==a[x]-sum1){
                        b[j]=1;}
                    }
                }
            }
        }
    }
    for(j=1;j<=sum;j++){
        printf("%d",b[j]);
    }
}
