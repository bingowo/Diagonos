//string\1056.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    
*/

#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

int xlen,ylen,k;

int input[200][200];
int Srow[200][200];
int Scol[200][200];
struct init_place{
    int x,y;
    char isx_pos,isy_pos;
};
typedef struct init_place init;

int calc_point(const int y,const int x)
{
    int ret=0;
    int nowx,nowy;
    int temsum=input[y][x];
    /* B##
        ##
         #  x->xlen,y->ylen*/
    for(int dlen=1;(nowx=x+dlen)<xlen&&(nowy=y+dlen)<ylen;++dlen){
        if(y>=1)
            temsum+=Scol[nowy][nowx]-Scol[y-1][nowx];
        else
            temsum+=Scol[nowy][nowx];
        if(temsum>=k){
            int leftx=xlen-nowx;
            int lefty=ylen-nowy;
            ret+=leftx>lefty?lefty:leftx;
            break;
        }
    }
    temsum=input[y][x];
    /*#
      ##
      ##B*/
    for(int dlen=1;(nowx=x-dlen)>=0&&(nowy=y-dlen)>=0;++dlen){
        if(nowy>=1)
            temsum+=Scol[y][nowx]-Scol[nowy-1][nowx];
        else
            temsum+=Scol[y][nowx];
        if(temsum>=k){
            int leftx=nowx+1;
            int lefty=nowy+1;
            ret+=leftx>lefty?lefty:leftx;
            break;
        }
    }
    temsum=input[y][x];
    for(int dlen=1;(nowx=x-dlen)>=0&&(nowy=y+dlen)<ylen;++dlen){
        if(nowx>=1)
            temsum+=Srow[nowy][x]-Srow[nowy][nowx-1];
        else
            temsum+=Srow[nowy][x];
        if(temsum>=k){
            int leftx=nowx+1;
            int lefty=ylen-nowy;
            ret+=leftx>lefty?lefty:leftx;
            break;
        }
    }
    temsum=input[y][x];
    for(int dlen=1;(nowx=x+dlen)<xlen&&(nowy=y-dlen)>=0;++dlen){
        if(x>=1)
            temsum+=Srow[nowy][nowx]-Srow[nowy][x-1];
        else
            temsum+=Srow[nowy][nowx];
        if(temsum>=k){
            int leftx=xlen-nowx;
            int lefty=nowy+1;
            ret+=leftx>lefty?lefty:leftx;
            break;
        }
    }
    return ret;
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    scanf("%d%d%d",&ylen,&xlen,&k);
    for(int iy=0;iy<ylen;++iy){
        for(int ix=0;ix<xlen;++ix){
            scanf("%d",&input[iy][ix]);
        }
    }
    for(int iy=0;iy<ylen;++iy){
        int tem=0;
        for(int ix=0;ix<xlen;++ix){
            tem+=input[iy][ix];
            Srow[iy][ix]=tem;
        }
    }
    for(int ix=0;ix<xlen;++ix){
        int tem=0;
        for(int iy=0;iy<ylen;++iy){
            tem+=input[iy][ix];
            Scol[iy][ix]=tem;
        }
    }
    long long ans=0;
    for(int iy=0;iy<ylen;++iy){
        for(int ix=0;ix<xlen;++ix){
            ans+=calc_point(iy,ix);
        }
    }
    printf("%lld",ans);
}