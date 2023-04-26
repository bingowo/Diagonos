#include <stdio.h>
#define INF 100000


int xm[4] = {1,0,-1,0},ym[4] = {0,1,0,-1};
int stll[10] = {1,2,4,8,16,32,64,128,256,512};
int x,y;

int min_plus(int a,int b,int c,int d){
    int min1;
    if(a > b)min1 = b;
    else min1  = a;
    int min2;
    if(c > d) min2 = d;
    else min2 = c;

    if(min1 > min2)return min2;
    else return min1;
}
int method(int xi,int yi,const int stl[],int flag);

int main(){
    scanf("%d %d",&x,&y);
    if(!((x + y)%2)){printf("-1");return 0;}
    int ans = method(0,0,stll,0);
    if(ans < INF)printf("%d",ans);
    else printf("-1");
}
int method(int xi,int yi,const int stl[],int flag){
    if(xi == x&&yi == y){return 0;}
    if(flag == 10){return INF;}

    int min;
    min = min_plus(method(xi + stl[flag]*xm[0],yi + stl[flag]*ym[0],stl,flag+1)+1,
                   method(xi + stl[flag]*xm[1],yi + stl[flag]*ym[1],stl,flag+1)+1,
                   method(xi + stl[flag]*xm[2],yi + stl[flag]*ym[2],stl,flag+1)+1,
                   method(xi + stl[flag]*xm[3],yi + stl[flag]*ym[3],stl,flag+1)+1);
    return min;
}