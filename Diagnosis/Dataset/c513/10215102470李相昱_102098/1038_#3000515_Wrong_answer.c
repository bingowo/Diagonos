#include <stdio.h>

int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int num=0,ret;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ret=0;
            for(int r=1;i-r>=0&&j-r>=0;r++){
                int n1=i;
                int m1=r;
                for(;n1>=i-r;n1--){
                    for(int t=m1;t>=0;t--){
                        ret+=a[n1][j-t];
                    }
                    m1--;
                }
            }
            if(ret>=k){
                num++;
            }
            ret=0;
            for(int r=1;i-r>=0&&j+r<m;r++){
                int n1=i;
                int m1=r;
                for(;n1>=i-r;n1--){
                    for(int t=m1;t>=0;t--){
                        ret+=a[n1][j+t];
                    }
                    m1--;
                }
            }
            if(ret>=k){
                num++;
            }
            ret=0;
            for(int r=1;i+r<n&&j-r>=0;r++){
                int n1=i;
                int m1=r;
                for(;n1<=i+r;n1++){
                    for(int t=m1;t>=0;t--){
                        ret+=a[n1][j-t];
                    }
                    m1--;
                }
            }
            if(ret>=k){
                num++;
            }
            ret=0;
            for(int r=1;i+r<n&&j+r<m;r++){
                int n1=i;
                int m1=r;
                for(;n1<=i+r;n1++){
                    for(int t=m1;t>=0;t--){
                        ret+=a[n1][j+t];
                    }
                    m1--;
                }
            }
            if(ret>=k){
                num++;
            }
        }
    }
    printf("%d\n",num);
    return 0;
}
