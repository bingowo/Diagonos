#include<stdio.h>

int process(int *item){
    int res = 256;
    for (int i = 0; i != 8; i++){
        int temp = 0;
        for (int j = 0; j != 8; j++)
            temp = (item[(i+j)%8]) + temp*2;
        res = temp > res? res: temp;  
    }
    return res;
}



int main(){
    int pix[100][100];
    int h, w; scanf("%d%d", &w, &h);
    for (int i = 0; i != h; i++)
        for (int j = 0; j != w; j++)
            scanf("%d", &pix[i][j]);

    for (int i = 1; i < h - 1; i++){
        for (int j = 1; j < w - 1; j++){
            int temp[8];
            temp[0] = pix[i-1][j-1], temp[1] = pix[i-1][j], temp[2] = pix[i-1][j+1], 
            temp[3] = pix[i][j+1], temp[4] = pix[i+1][j+1], temp[5] = pix[i+1][j],
            temp[6] = pix[i+1][j-1], temp[7] = pix[i][j-1];
            for (int k = 0; k != 8; k++)
                temp[k] = temp[k] >= pix[i][j]? 1: 0;
            printf("%d%c", process(temp), j == w - 2? '\n': ' ');
        }
    }
    return 0;
}