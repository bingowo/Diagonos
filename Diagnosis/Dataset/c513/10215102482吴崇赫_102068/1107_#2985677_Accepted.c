#include <stdio.h>
#include <stdlib.h>
int p_trans(int n){
    int ret=0;
    if(n==1)ret=0;
    if(n==0)ret= 1;
    return ret;
}
int main(){
    int T,x=0;
    //cin>>T;
    scanf("%d\n",&T);
    while(x<T){
        int a[5][5];
        for(int i=1;i<4;++i){
            for(int j=1;j<4;++j) a[i][j]=1;
        }
        int b[5][5]={0};
        for(int i=1;i<4;++i){
            for(int j=1;j<4;++j) scanf("%d",&b[i][j]);
        }
        for(int i=1;i<4;++i){
            for(int j=1;j<4;++j){
                if(b[i][j]%2){
                    a[i][j]=p_trans(a[i][j]);
                    a[i+1][j]=p_trans(a[i+1][j]);
                    a[i-1][j]=p_trans(a[i-1][j]);
                    a[i][j-1]=p_trans(a[i][j-1]);
                    a[i][j+1]=p_trans(a[i][j+1]);
                }
            }
        }
        printf("case #%d:\n",x);
        for(int i=1;i<4;++i){
            for(int j=1;j<4;++j){
                //cout<<a[i][j]<<' ';
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        x++;
    }
    return 0;
}