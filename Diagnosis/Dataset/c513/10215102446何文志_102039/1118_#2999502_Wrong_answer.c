#include <stdio.h>
#include <stdlib.h>

int ColckWiseDegree(int D, char c){//逆时针转化为顺时针
    D %= 360;
    if(c == 'L'){
        D = 360-D;
    }
    return D;
}

int** SpinnedPic(int** pic, int W, int H, int D){
    int** res = NULL;
    int resH = 0, resW = 0;

    if(D%180 == 0){
        resH = H; resW = W;
        res = (int**)calloc(resH,sizeof(int*));
        for(int i = 0;i<resH;i++){
            res[i] = (int*)calloc(resW,sizeof(int));
        }
        for(int i = 0;i<resH;i++){//先反转列
            for(int j = 0;j<resW;j++){
                res[i][j] = pic[i][W-j-1];
            }
        }
        for(int i1=0,j1=resH-1;i1<j1;i1++,j1--){//再反转行
            int* tmp = res[i1];
            res[i1] = res[j1];
            res[j1] = tmp;
        }
    }
    else{
        resH = W; resW = H;
        res = (int**)calloc(resH, sizeof(int*));
        for(int i = 0;i<resH;i++){
            res[i] = (int*)calloc(resW, sizeof(int));
        }
        for(int i = 0;i<resH;i++){//先转置
            for(int j = 0;j<resW;j++){
                res[i][j] = pic[j][i];
            }
        }
        if(D==270){//反转行
            for(int i1=0,j1=resH-1;i1<j1;i1++,j1--){
                int* tmp = res[i1];
                res[i1] = res[j1];
                res[j1] = tmp;
            }
        }
        else if(D==90){//反转列
            for(int i = 0;i<resH;i++){
                for(int i1=0,j1=resW-1;i1<j1;i1++,j1--){
                    int tmp = res[i][i1];
                    res[i][i1] = res[i][j1];
                    res[i][j1] = tmp;
                }
            }
        }
    }
    return res;
}

int main()
{
    int W = 0 , H = 0 ,D = 0;
    char c = 0;
    scanf("%d %d %d %c",&W,&H,&D,&c);
    int** pic = (int**)calloc(H,sizeof(int*));
    for(int i = 0;i<H;i++){
        pic[i] = (int*)calloc(W,sizeof(int));
    }
    for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            scanf("%d",&pic[i][j]);
        }
    }

    int D1 = ColckWiseDegree(D, c);

    int** res = SpinnedPic(pic, W, H, D1);
    int resH = D1%180==0 ? H : W;
    int resW = D1%180==0 ? W : H;
    printf("%d %d\n",resW,resH);
    for(int i = 0;i<resH;i++){
        for(int j = 0;j<resW;j++){
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
