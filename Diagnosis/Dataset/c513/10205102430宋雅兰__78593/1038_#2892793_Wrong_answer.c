#include<stdio.h>
int main()
{
    int n,m;
    long long k;
    int a[201][201];
    long long pre[201][201]={0};
    scanf("%d%d%lld",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",a[i]+j);
            pre[i][j]=pre[i][j-1]+a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<n;i++){//右下
        for(int j=1;j<m;j++){
            long long s=a[i][j];
            for(int l=1;l+i<=n&&l+j<=m;l++){
                s+=pre[i+l][j+l]-pre[i+l][j-1];
                if(s>=k)ans++;
            }
        }
    }
    for(int i=1;i<n;i++){//左下
        for(int j=m;j>1;j--){
            long long s=a[i][j];
            for(int l=1;l+i<=n&&j-l>0;l++){
                s+=pre[i+l][j]-pre[i+l][j-l-1];
                if(s>=k)ans++;
            }
        }
    }
    for(int i=n;i>1;i--){//左上
        for(int j=m;j>1;j--){
            long long s=a[i][j];
            for(int l=1;i-l>0&&j-l>0;l++){
                s+=pre[i-l][j]-pre[i-l][j-l-1];
                if(s>=k)ans++;
            }
        }
    }
    for(int i=n;i>1;i--){//右上
        for(int j=1;j<m;j++){
            long long s=a[i][j];
            for(int l=1;i-l>0&&j+l<=n;l++){
                s+=pre[i-l][j+l]-pre[i-l][j-1];
                if(s>=k)ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
