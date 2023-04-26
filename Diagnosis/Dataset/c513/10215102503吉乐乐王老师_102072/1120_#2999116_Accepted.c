#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        int r,c,n,k;
        int mat[13][13]={0};
        scanf("%d%d%d%d",&r,&c,&n,&k);getchar();
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);getchar();
            mat[x][y]=1;
        }
        int ret=0;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                for(int x=i;x<=r;x++){
                    for(int y=j;y<=c;y++){
                        int cnt=0;
                        for(int p=i;p<=x;p++){
                            for(int z=j;z<=y;z++){
                                if(mat[p][z])cnt++;
                            }
                        }
                        if(cnt>=k)ret++;
                    }
                }
            }
        }
        printf("case #%d:\n%d\n",cas++,ret);
    }
}
