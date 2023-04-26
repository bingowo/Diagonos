//simu\1105.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    one word pressure test
*/

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

int picture[101][101];
int LBP[101][101];

int near[8][2]={{0,-1},{1,-1},{1,0},// //!left is row!
            {1,1},{0,1},{-1,1},{-1,0},{-1,-1}};
            //
            //bottom is in the front
int calc_LBP(int x,int y)
{
    int temarr[8];
    int temlen=0;
    for(int i=0;i<8;++i){
        if(picture[x+near[i][0]][y+near[i][1]]>=picture[x][y]){
            temarr[temlen++]=1;
        }else{
            temarr[temlen++]=0;
        }
    }
    int ret=INT_MAX;
    for(int i=0;i<8;++i){
        int temret=0;
        for(int k=0;k<8;++k){
            temret+=temarr[(i+k)%8]<<k;
        }
        if(temret<ret)
            ret=temret;
    }
    return ret;
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int W,H;
    scanf("%d%d",&W,&H);
    for(int iH=0;iH<H;++iH){
        for(int iW=0;iW<W;++iW){
            scanf("%d",&picture[iH][iW]);
        }
    }
    for(int ix=1;ix<H-1;++ix){
        for(int iy=1;iy<W-1;++iy){
            LBP[ix][iy]=calc_LBP(ix,iy);
        }
    }
    for(int ix=1;ix<H-1;++ix){
        for(int iy=1;iy<W-2;++iy){
            printf("%d ",LBP[ix][iy]);
        }
        printf("%d\n",LBP[ix][W-2]);
    }

}

