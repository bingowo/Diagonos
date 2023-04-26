#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 205


int main()
{
    int wid,height,ang;
    char c;
    scanf("%d%d%d%c\n",&wid,&height,&ang,&c);
    ang %= 360;
    if(c=='L'){
        if(ang==90)ang=270;
        if(ang==270)ang=90;
    }
    int a[N][N],b[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j)a[i][j]=b[i][j]=0;
    }
    for(int i=0;i<height;++i){
        for(int j=0;j<wid;++j)scanf("%d",&a[i][j]);
    }
    int ci=ang/90;
    for(int i=0;i<wid;++i){
        int bj=0;
        for(int j=height-1;j>=0;--j){
            b[i][bj++]=a[j][i];
            printf("%d ",a[j][i]+1);
        }
        printf("\n");
    }
    return 0;
}
