#include <stdio.h>
int main(){
    int W,H;
    scanf("%d%d",&W,&H);
    int pic[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            scanf("%d",&pic[i][j]);
        }
    }
    int LBP[H-2][W-2];
    for(int i=1;i<H-1;i++){
        for(int j=1;j<W-1;j++){
            int p[8];
            p[0]=(pic[i-1][j-1]>=pic[i][j]);
            p[1]=(pic[i-1][j]>=pic[i][j]);
            p[2]=(pic[i-1][j+1]>=pic[i][j]);
            p[7]=(pic[i][j-1]>=pic[i][j]);
            p[3]=(pic[i][j+1]>=pic[i][j]);
            p[6]=(pic[i+1][j-1]>=pic[i][j]);
            p[5]=(pic[i+1][j]>=pic[i][j]);
            p[4]=(pic[i+1][j+1]>=pic[i][j]);
            int q[8];
            q[0]=p[0]+2*p[1]+4*p[2]+8*p[3]+16*p[4]+32*p[5]+64*p[6]+128*p[7];
            q[1]=p[1]+2*p[2]+4*p[3]+8*p[4]+16*p[5]+32*p[6]+64*p[7]+128*p[0];
            q[2]=p[2]+2*p[3]+4*p[4]+8*p[5]+16*p[6]+32*p[7]+64*p[0]+128*p[1];
            q[3]=p[3]+2*p[4]+4*p[5]+8*p[6]+16*p[7]+32*p[0]+64*p[1]+128*p[1];
            q[4]=p[4]+2*p[5]+4*p[6]+8*p[7]+16*p[0]+32*p[1]+64*p[2]+128*p[3];
            q[5]=p[5]+2*p[6]+4*p[7]+8*p[0]+16*p[1]+32*p[2]+64*p[3]+128*p[4];
            q[6]=p[6]+2*p[7]+4*p[0]+8*p[1]+16*p[2]+32*p[3]+64*p[4]+128*p[5];
            q[7]=p[7]+2*p[0]+4*p[1]+8*p[2]+16*p[3]+32*p[4]+64*p[5]+128*p[6];
            LBP[i-1][j-1]=q[0];
            for(int k=0;k<8;k++){
                if(q[k]<LBP[i-1][j-1])LBP[i-1][j-1]=q[k];
            }
        }
    } 
    for(int i=1;i<H-1;i++){
        for(int j=1;j<W-1;j++){
            printf("%d ",LBP[i-1][j-1]);
        }
        printf("\n");
    }
    return 0;
}