#include<stdio.h>

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        int r,c,n,k;
        scanf("%d %d %d %d",&r,&c,&n,&k);
        int num[n+1],rec[r+1][c+1];
        for(int i=0;i<n+1;i++)num[i]=0;
        for(int i=0;i<=r;i++){
            for(int j=0;j<=c;j++)rec[i][j]=0;
        }
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            rec[x][y]=1;
        }
        num[0]=r*c-n;num[1]=n;num[n]=1;
        a++;
    }
}