#include<stdio.h>

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        int r,c,n,k,ans=0;
        scanf("%d %d %d %d",&r,&c,&n,&k);
        int num[n+1],rec[r+1][c+1],henz[r+1][c+1],shuz[r+1][c+1],hend[r+1][c+1],shud[r+1][c+1],ju[r+1][c+1];
        for(int i=0;i<n+1;i++)num[i]=0;
        num[1]=n;
        for(int i=0;i<=r;i++)
            for(int j=0;j<=c;j++)rec[i][j]=0;
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            rec[x][y]=1;
        }
        for(int i=0;i<=r;i++)//初始化
            for(int j=0;j<=c;j++){
                henz[i][j]=rec[i][j];
                shuz[i][j]=rec[i][j];
                hend[i][j]=rec[i][j];
                shud[i][j]=rec[i][j];
                ju[i][j]=rec[i][j];
            }
        for(int i=0;i<=r;i++)
            for(int j=1;j<=c;j++)henz[i][j]=rec[i][j]+henz[i][j-1];
        for(int j=0;j<=c;j++)
            for(int i=1;i<=r;i++)shuz[i][j]=rec[i][j]+shuz[i-1][j];
        for(int i=0;i<=r;i++)
            for(int j=c-1;j>=1;j--)hend[i][j]=rec[i][j]+hend[i][j+1];
        for(int j=0;j<=c;j++)
            for(int i=r-1;i>=1;i--)shud[i][j]=rec[i][j]+shud[i+1][j];z
        for(int i=1;i<=r;i++)//单列或单行矩阵
            for(int j=1;j<=c;j++){
                num[henz[i][j]]++;num[shuz[i][j]]++;
                num[hend[i][j]]++;num[shud[i][j]]++;
            }
        for(int i=0;i<=r;i++)
            for(int j=1;j<=c;j++)ju[i][j]=shuz[i][j]+ju[i][j-1]; 
        for(int i=2;i<=r;i++)
            for(int j=2;j<=c;j++)num[ju[i][j]]++;//左上矩形
        for(int i=0;i<=r;i++)ju[i][c]=shuz[i][c];//初始化
        for(int i=0;i<=r;i++)
            for(int j=c-1;j>=1;j--)ju[i][j]=shuz[i][j]+ju[i][j+1];
        for(int i=2;i<=r;i++)
            for(int j=1;j<c;j++)num[ju[i][j]]++;//右上矩形
        for(int j=0;j<=c;j++)ju[1][j]=shud[1][j];//初始化
        for(int i=0;i<=r;i++)
            for(int j=2;j<=c;j++)ju[i][j]=shud[i][j]+ju[i][j-1];
        for(int i=1;i<r;i++)
            for(int j=2;j<=c;j++)num[ju[i][j]]++;//左下矩形
        for(int i=0;i<=r;i++)ju[i][c]=shud[i][c];//初始化
        for(int i=0;i<=r;i++)
            for(int j=c-1;j>=1;j--)ju[i][j]=shud[i][j]+ju[i][j+1];
        for(int i=1;i<r;i++)
            for(int j=1;j<c;j++)num[ju[i][j]]++;//右上矩形
        num[rec[1][1]]--;num[rec[r][c]]--;
        num[rec[1][c]]--;num[rec[r][1]]--;
        for(int i=k;i<=n;i++)ans+=num[i];
        printf("case #%d:\n%d\n",a,ans);
        a++;
    }
}