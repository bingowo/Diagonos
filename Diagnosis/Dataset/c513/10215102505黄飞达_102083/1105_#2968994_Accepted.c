#include<stdio.h>

int arr[101][101]={0};

int func(int i, int j){
    int base=arr[i][j];
    int temp[8]={0}, dis[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    for (int k=0; k<8; k++) temp[k]=arr[i+dis[k][0]][j+dis[k][1]]>=base?1:0;

    int lbp[8]={0},min=256;
    for (int k=0; k<8; k++){
        for (int m=0; m<8; m++){
            lbp[k]*=2;
            lbp[k]+=temp[(k+m)%8];
        }
        if (min>lbp[k]) min=lbp[k];
    }
    return min;
}
int main(){
    int w, h;
    scanf("%d %d", &w, &h);
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i=1; i<h-1; i++) {
        for (int j=1; j<w-2; j++){
            printf("%d ",func(i,j));
        }
        printf("%d\n", func(i, w-2));
    }
    return 0;
}