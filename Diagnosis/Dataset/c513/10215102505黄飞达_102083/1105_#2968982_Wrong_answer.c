#include<stdio.h>

int arr[101][101]={0};

int func(int i, int j){
    int base=arr[i][j];
    int temp[8]={0}, dis[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    for (int k=0; k<8; k++) temp[k]=arr[i+dis[k][0]][j+dis[k][1]]>=base?1:0;
    int len[8]={0};
    int lbp=0, maxlen=0, pos=0;
    len[0] = (temp[0]==0?1:0);
    for (int k=1; k<16; k++) {
        if (temp[k%8]==0) len[k%8]=len[(k-1)%8]+1;
        if (maxlen<len[k%8]) {maxlen=len[k%8];pos=k%8;}
    }
    for (int k=0; k<8; k++){
        lbp*=2;
        lbp+=temp[(pos-maxlen+9+k)%8];
    }
    return lbp;
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