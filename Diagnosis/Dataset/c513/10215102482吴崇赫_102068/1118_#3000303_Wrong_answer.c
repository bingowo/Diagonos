#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 205


int main()
{
    int wid,height,ang;
    char c;
    scanf("%d%d%d\n",&wid,&height,&ang);
    scanf("%c",&c);
    ang %= 360;
    if(c=='L'){
        if(ang==90)ang=270;
        else if(ang==270)ang=90;
    }
    //printf("%d\n",ang);
    int a[N][N],b[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j)a[i][j]=b[i][j]=0;
    }
    for(int i=0;i<height;++i){
        for(int j=0;j<wid;++j){
            scanf("%d",&a[i][j]);
        }
    }
    if(ang==0){
        printf("%d %d\n",wid,height);
        for(int i=0;i<height;++i){
        for(int j=0;j<wid;++j){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    }
    if(ang==90){
        printf("%d %d\n",height,wid);
    for(int i=0;i<wid;++i){
        int bj=0;
        for(int j=height-1;j>=0;--j){
            b[i][bj]=a[j][i];
            printf("%d ",b[i][bj++]);
        }
        printf("\n");
    }
    }
    if(ang==180){
        printf("%d %d\n",wid,height);
        for(int i=0;i<height;++i){
            //int bj=0;
            for(int j=0;j<wid;++j){
                b[i][j]=a[height-1-i][wid-1-j];
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
    }
    if(ang==270){
        printf("%d %d\n",height,wid);
        int bj=wid-1;
        for(int i=0;i<wid;++i){

            for(int j=height-1;j>=0;--j){
                b[bj][j]=a[j][i];
                //printf("%d ",b[bj][j]);
            }
            //printf("\n");
            bj--;
        }
        for(int i=0;i<wid;++i){
            for(int j=0;j<height;++j){
                printf("%d ",b[i][j]);
                //printf("a");
            }
            printf("\n");
        }
    }
    return 0;
}

