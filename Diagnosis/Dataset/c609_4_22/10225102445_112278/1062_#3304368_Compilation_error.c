#include<bits/stdc++.h>
using namespace std;
int m,n,f[105][105],a[105][105];
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=100;j++){
            for(int k=0;k<=j;k++){
                f[i][j]=min(f[i][j],f[i-1][k]+abs(a[i-1][n]-k)+abs(a[i][n]-j));
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=0;i<=100;i++)ans=min(ans,f[m][i]);
    cout<<ans<<endl;
    return 0;
}
