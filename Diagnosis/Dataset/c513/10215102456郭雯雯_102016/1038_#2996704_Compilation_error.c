#include<stdio.h>
#include<string.h>

int main(){
    long long data[205][205],s[205][205],sum;
    memset(data,0,sizeof(data));memset(s,0,sizeof(s));
    int n,m,k,ans=0;
    scanf("%d %d %d",&n,&m,&K);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)scanf("%d",&data[i][j]);
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)s[i][j]=data[i][j]+s[i][j-1];
    for(int x=1;x<=n;x++){
        for(int y=1;y<=m;y++){
            sum=data[x][y];
            for(int r=1;x+r<=n&&y+r<=m;r++){//直角在右上
                sum+=(s[x+r]s[y+r]-s[x-1][y+r]);
                if(sum>=k)ans++;
            }
            sum=data[x][y];
            for(int r=1;x-r>=1&&y-r>=1;r++){//直角在左下
                sum+=(s[x]s[y-r]-s[x-r-1][y-r]);
                if(sum>=k)ans++;
            }
            
        }
    }
    printf("%d",ans);
}