#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 201

int main()
{
    int w, h, d;
    char c;
    scanf("%d%d%d %c",&w,&h,&d,&c);
    d = d%360;

    int ori[M][M], res[M][M];
    memset(ori,0,M*M); memset(res,0,M*M);

    /***input***/
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) scanf("%d",&ori[i][j]);
    }

    /***process***/
    //0 180
    if(d == 180){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++)
                res[i][j] = ori[h-i-1][w-j-1];
        }
    }
    if(d == 0){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++)
                res[i][j] = ori[i][j];
        }
    }
    //output of 0 & 180
    if(d == 0 || d == 180){
        printf("%d %d\n",w,h);
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w-1; j++)
                printf("%d ",res[i][j]);
            printf("%d\n",res[i][w-1]);
        }
        return 0;
    }

    //90 270, w' = h, h' = w;
    printf("%d %d\n",h,w);
        //case 1
    if((d == 90 && c == 'R') || (d == 270 && c == 'L')){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++)
                res[j][h-i-1] = ori[i][j];
        }
    }
        //case 2
    else{
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++)
                res[w-j-1][i] = ori[i][j];
        }
    }

    //output
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h-1; j++)
            printf("%d ",res[i][j]);
        printf("%d\n",res[i][h-1]);
    }

    return 0;
}
