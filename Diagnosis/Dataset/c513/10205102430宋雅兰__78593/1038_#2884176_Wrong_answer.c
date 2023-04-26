#include<stdio.h>
int main()
{
    int n,m;
    long long k;
    int a[201][201];
    long long pre[201][201]={0};
    scanf("%d%d%lld",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",a[i]+j);
            pre[i][j+1]=pre[i][j]+a[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n-1;i++){//右下
        for(int j=0;j<m-1;j++){
            long long s=a[i][j];
            for(int l=1;l+i<n&&l+j<m;l++){
                s+=pre[i+l][j+l+1]-pre[i+l][j-1];
                if(s>=k)ans++;
            }
        }
    }
    for(int i=0;i<n-1;i++){//左下
        for(int j=m-1;j>0;j--){
            long long s=a[i][j];
            for(int l=1;l+i<n&&j-l>=0;l++){
                s+=pre[i+l][j+1]-pre[i+l][j-l-1];
                if(s>=k)ans++;
            }
        }
    }
    for(int i=n-1;i>0;i--){//左上
        for(int j=m-1;j>0;j--){
            long long s=a[i][j];
            for(int l=1;i-l>=0&&j-l>=0;l++){
                s+=pre[i-l][j+1]-pre[i-l][j-l-1];
                if(s>=k)ans++;
            }
        }
    }
    for(int i=n-1;i>0;i--){//右上
        for(int j=0;j<m-1;j++){
            long long s=a[i][j];
            for(int l=1;i-l>=0&&j+l<n;l++){
                s+=pre[i-l][j+l+1]-pre[i-l][j-1];
                if(s>=k)ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
