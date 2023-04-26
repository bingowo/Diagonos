#include<stdio.h>

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        int r,c,n,k,ans=0;
        scanf("%d %d %d %d",&r,&c,&n,&k);
        int num[n+1],rec[r+1][c+1],hen[r+1][c+1],shu[r+1][c+1],ju[r+1][c+1];
        for(int i=0;i<n+1;i++)num[i]=0;
        for(int i=0;i<=r;i++)
            for(int j=0;j<=c;j++){
                rec[i][j]=0;hen[i][j]=0;shu[i][j]=0;ju[i][j]=0;
            }
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            rec[x][y]=1;
        }
        for(int i=0;i<=r;i++)
            for(int j=1;j<=c;j++)hen[i][j]=rec[i][j]+hen[i][j-1];
        for(int j=0;j<=c;j++)
            for(int i=1;i<=r;i++)shu[i][j]=rec[i][j]+shu[i-1][j];
        for(int i=0;i<=r;i++)
            for(int j=1;j<=c;j++)ju[i][j]=shu[i][j]+ju[i][j-1]; 
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++){
                num[hen[i][j]]++;num[shu[i][j]]++;
            }
        for(int i=2;i<=r;i++)
            for(int j=2;j<=c;j++)num[ju[i][j]]++;
        num[rec[1][1]]--;
        for(int i=k;i<=n;i++)ans+=num[i];
        printf("case #%d:\n%d\n",a,ans);
        a++;
    }
}