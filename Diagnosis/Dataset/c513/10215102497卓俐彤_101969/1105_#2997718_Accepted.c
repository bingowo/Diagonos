#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
    int W,H;
    scanf("%d %d",&W,&H);
    int graph[H][W];
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            scanf("%d",&graph[h][w]);
        }
    }
    int lbp[8],min=300,temp=0,LBP[H-2][W-2];
    for(int i=1;i<H-1;i++){
        for(int j=1;j<W-1;j++){
            min=255;
            temp=0;
            lbp[0]=graph[i-1][j-1]>=graph[i][j]?1:0;
            lbp[1]=graph[i-1][j]>=graph[i][j]?1:0;
            lbp[2]=graph[i-1][j+1]>=graph[i][j]?1:0;
            lbp[3]=graph[i][j+1]>=graph[i][j]?1:0;
            lbp[4]=graph[i+1][j+1]>=graph[i][j]?1:0;
            lbp[5]=graph[i+1][j]>=graph[i][j]?1:0;
            lbp[6]=graph[i+1][j-1]>=graph[i][j]?1:0;
            lbp[7]=graph[i][j-1]>=graph[i][j]?1:0;
            for(int k=0;k<8;k++){
                for(int p=0;p<8;p++){
                    temp=temp*2+lbp[(k+p)%8];
                }
                min=min<temp?min:temp;
                temp=0;
            }
            LBP[i-1][j-1]=min;
        }
    }
    for(int i=0;i<H-2;i++){
        for(int j=0;j<W-2;j++){
            printf("%d%c",LBP[i][j],j==W-3?'\n':' ');
        }
    }
    return 0;
}
