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
            ret=a[i][j];
            for(int r=1;i-r>=0&&j-r>=0;r++){
                int p=j-r;
                int q=j;
                for(int y=p;y<=q;y++){
                    ret+=a[i-r][y];
                }
                if(ret>=k){
                    num++;
                }
            }
            ret=a[i][j];
            for(int r=1;i-r>=0&&j+r<m;r++){
                int p=j+r;
                int q=j;
                for(int y=p;y>=q;y--){
                    ret+=a[i-r][y];
                }
                if(ret>=k){
                    num++;
                }
            }
            ret=a[i][j];
            for(int r=1;i+r<n&&j-r>=0;r++){
                int p=j-r;
                int q=j;
                for(int y=p;y<=q;y++){
                    ret+=a[i+r][y];
                }
                if(ret>=k){
                    num++;
                }
            }
            ret=a[i][j];
            for(int r=1;i+r<n&&j+r<m;r++){
                int p=j+r;
                int q=j;
                for(int y=p;y>=q;y--){
                    ret+=a[i+r][y];
                }
                if(ret>=k){
                    num++;
                }
            }
        }
    }
    printf("%d\n",num);
    return 0;
}
