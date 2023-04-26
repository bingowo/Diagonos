#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int deng[3][3]={{1,1,1},{1,1,1},{1,1,1}};
        int caozuo[3][3]={0};
        for(int ii=0;ii<3;ii++){
            for(int jj=0;jj<3;jj++) scanf("%d",&caozuo[ii][jj]);
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(caozuo[i][j]%2!=0){
                    deng[i][j]=deng[i][j]==0 ? 1:0;
                    if(i>0) deng[i-1][j]=deng[i-1][j]==0 ? 1:0;
                    if(i<=1) deng[i+1][j]=deng[i+1][j]==0 ? 1:0;
                    if(j>0) deng[i][j-1]=deng[i][j-1]==0 ? 1:0;
                    if(j<=1) deng[i][j+1]=deng[i][j+1]==0 ? 1:0;
                }
            }
        }
        printf("case #%d:\n",t);
        for(int m=0;m<3;m++){
            for(int n=0;n<3;n++) printf("%d ",deng[m][n]);
            printf("\n");
        }
    }
    return 0;
}
