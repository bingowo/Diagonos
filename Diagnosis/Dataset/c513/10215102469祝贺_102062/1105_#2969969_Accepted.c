#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
int lbp(int s[]){
    int ret=300,num=0;
    for(int i=0;i<8;i++){
        num=num*2+s[i];
    }
    ret=num;
    for(int i=1;i<8;i++){
        num=(num-128*s[i-1])*2+s[i-1];
        if(ret>num)ret=num;
    }
    return ret;
}
int main(){
    int w,h;scanf("%d%d",&w,&h);
    int bmp[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&bmp[i][j]);
        }
    }
    for(int i=1;i<h-1;i++){
        for(int j=1;j<w-1;j++){
            int s[10]={0};
            s[0]=bmp[i-1][j-1]>=bmp[i][j];
            s[1]=bmp[i-1][j]>=bmp[i][j];
            s[2]=bmp[i-1][j+1]>=bmp[i][j];
            s[3]=bmp[i][j+1]>=bmp[i][j];
            s[4]=bmp[i+1][j+1]>=bmp[i][j];
            s[5]=bmp[i+1][j]>=bmp[i][j];
            s[6]=bmp[i+1][j-1]>=bmp[i][j];
            s[7]=bmp[i][j-1]>=bmp[i][j];
            if(j!=w-2)printf("%d ",lbp(s));
            else printf("%d\n",lbp(s));
        }
    }
    return 0;
}

