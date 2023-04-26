#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int anti(int n){
    if(n==0){
        n=1;
    }else{
        n=0;
    }
}
int main(){
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int b[3][3]={};
        int a[3][3]={1};
        int m,n;
        for(m=0;m<3;m++){
            for(n=0;n<3;n++){
                scanf("%d",&b[m][n]);
                if(b[m][n]%2==1){
                    if(m==1&&n==1){
                        a[m-1][n-1]==anti(a[m-1][n-1]);
                        a[m-1][n+1]==anti(a[m-1][n+1]);
                        a[m+1][n-1]==anti(a[m+1][n-1]);
                        a[m+1][n+1]==anti(a[m+1][n+1]);
                        a[m][n]==anti(a[m][n]);
                    }
                    if(m==0&&n==0){
                        a[m][n]==anti(a[m][n]);
                        a[m+1][n]
                    }
                }
            }
        }
    }
}