#include<stdio.h>
int main(){
    int n,m,t,sum=0;
    static int a[200][200];
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++)scanf("%d",&a[i][k]);
    }
    for(int i=0;i<n-1;i++){    //右下方
        for(int k=0;k<m-1;k++){
            int r=2,s;
            s=a[i][k];
            while(r<=m-k&&r<=n-i){
                for(int q=0;q<r;q++){
                    s+=a[i+q][k+r-1-q];
                }
                if(s>=t)sum++;
                r++;
            }
        }
    }
    for(int i=n-1;i>0;i--){    //右上方
        for(int k=0;k<m-1;k++){
            int r=2,s;
            s=a[i][k];
            while(r<=m-k&&r<=i+1){
                for(int q=0;q<r;q++){
                    s+=a[i-q][k+r-1-q];
                }
                if(s>=t)sum++;
                r++;
            }
        }
    }
    for(int i=0;i<n-1;i++){    //左下方
        for(int k=m-1;k>0;k--){
            int r=2,s;
            s=a[i][k];
            while(r<=k+1&&r<=n-i){
                for(int q=0;q<r;q++){
                    s+=a[i+q][k-r+1+q];
                }
                if(s>=t)sum++;
                r++;
            }
        }
    }
    for(int i=n-1;i>0;i--){    //左上方
        for(int k=m-1;k>0;k--){
            int r=2,s;
            s=a[i][k];
            while(r<=k+1&&r<=i+1){
                for(int q=0;q<r;q++){
                    s+=a[i-q][k-r+1+q];
                }
                if(s>=t)sum++;
                r++;
            }
        }
    }
    printf("%d",sum);
    return 0;
}