#include<stdio.h>
#include<stdlib.h>
void get(int *bin,int **pic,int i,int j){
    bin[0]=pic[i+1][j-1]>=pic[i][j]?1:0;
    bin[1]=pic[i+1][j]>=pic[i][j]?1:0;
    bin[2]=pic[i+1][j+1]>=pic[i][j]?1:0;
    bin[3]=pic[i][j+1]>=pic[i][j]?1:0;
    bin[4]=pic[i-1][j+1]>=pic[i][j]?1:0;
    bin[5]=pic[i-1][j]>=pic[i][j]?1:0;
    bin[6]=pic[i-1][j-1]>=pic[i][j]?1:0;
    bin[7]=pic[i][j-1]>=pic[i][j]?1:0;
}
int judge(int *bin){
    int ret[8]={0};
    for(int i=0;i<8;i++){
        for(int j=i;j<8;j++){
            ret[i]=ret[i]*2+bin[j];
        }
        for(int k=0;k<i;k++){
            ret[i]=ret[i]*2+bin[k];
        }
    }
    int min=ret[0];
    for(int i=0;i<8;i++){
        min=ret[i]<min?ret[i]:min;
    }
    return min;
}
int main(){
    int w,h;
    scanf("%d%d",&w,&h);
    int **pic=(int**)malloc(sizeof(int*)*h);
    int **ans=(int**)malloc(sizeof(int*)*h);
    for(int i=0;i<h;i++){
        ans[i]=(int*)malloc(sizeof(int)*w);
        pic[i]=(int*)malloc(sizeof(int)*w);
        for(int j=0;j<w;j++){
            scanf("%d",&pic[i][j]);
        }
        getchar();
    }
    int bin[8]={0};
    for(int i=1;i<h-1;i++){
        for(int j=1;j<w-1;j++){
            get(bin,pic,i,j);
            ans[i][j]=judge(bin);
            printf("%d",ans[i][j]);
            if(j!=w-2)putchar(' ');
        }
        putchar('\n');
    }
}