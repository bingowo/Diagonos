#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getLBP(int a[],int n){
    char s[8][10];memset(s,0,80*sizeof(char));
    int res = 0;
    for(int i = 0;i<8;i++){
        s[0][i] = '0'+a[i];
        //printf("S0 = %s\n",s[0]);
    }
        res = btoi(s[0]);
    //printf("%s: %d\n",s[0],res);

    for(int i = 1;i<8;i++){
        int cnt = 0;
        for(int j = i;j<8;j++){
            s[i][cnt++] = s[0][j];
        }
        for(int j = 0;j<i;j++){
            s[i][cnt++] = s[0][j];
        }
        int tmp = btoi(s[i]);
        if(tmp<res){
            res = tmp;
        }
        //printf("%s: %d\n",s[i],tmp);
    }

    return res;
}

int btoi(char s[]){
    int res = 0;
    for(int i = 0;i<strlen(s);i++){
        res = res*2 + s[i] - '0';
    }
    return res;
}

int main()
{
    int W = 0,H = 0;
    scanf("%d%d",&W,&H);
    int pic[H][W];memset(pic,0,W*H*sizeof(int));
    for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            scanf("%d",&pic[i][j]);
        }
    }
    int res[H-2][W-2];memset(res,0,(H-2)*(W-2)*sizeof(int));
    int rcnt = 0,ccnt = 0;
    for(int i = 1;i<H-1;i++){
        for(int j = 1;j<W-1;j++){
            int around[8];memset(around,0,8*sizeof(int));
            around[0] = pic[i-1][j-1];around[1] = pic[i-1][j];around[2] = pic[i-1][j+1];
            around[3] = pic[i][j+1];around[4] = pic[i+1][j+1];
            around[5] = pic[i+1][j];around[6] = pic[i+1][j-1];around[7] = pic[i][j-1];
            for(int k = 0;k<8;k++){
                around[k] = around[k]>=pic[i][j]? 1:0;
                //printf("%d ",around[k]);
            }
            //printf("%d,%d:\n",i,j);
            int LBP = getLBP(around,pic[i][j]);
            res[rcnt][ccnt++] = LBP;
            //printf("LBP = %d\n",LBP);
        }
        ccnt = 0;
        rcnt++;
        //printf("\n");
    }
    //for(int i = 0;i<H;i++){
    //    for(int j = 0;j<W;j++){
    //        printf("%d ",pic[i][j]);
    //    }
    //    printf("\n");
    //}
    //printf("res\n");
    for(int i = 0;i<H-2;i++){
        for(int j = 0;j<W-2;j++){
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
