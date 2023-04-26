#include <stdio.h>
#define INF 100000


int xm[4] = {1,0,-1,0},ym[4] = {0,1,0,-1};
int stll[40] = {1};
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
int stan(int a,int b){
    if(a > b){
        return a - b;
    }
    else return b - a;
}
void perf(){
    for (int i = 1; i < 40; ++i) {
        stll[i] = 2*stll[i-1];
    }
}
int cou(int xe,int ye){
    if(xe < 0)xe = -xe;
    if(ye < 0)ye = -ye;
    int sum = xe + ye;int cnt = 0;
    while(sum){sum /=2;cnt++;}
    return cnt;
}

int main(){
    perf();
    scanf("%d %d",&x,&y);
    if(!((x + y)%2)){printf("-1");return 0;}
    int ans = method(0,0,stll,0);
    if(ans < INF)printf("%d",ans);
    else printf("-1");
}
int method(int xi,int yi,const int stl[],int flag){
    if(xi == x&&yi == y){return 0;}

    if(flag > cou(x,y)+1){return INF;}
    int min;
    min = min_plus(method(xi + stl[flag]*(-1),yi,stl,flag+1)+1,
                   method(xi + stl[flag],yi,stl,flag+1)+1,
                   method(xi ,yi + stl[flag],stl,flag+1)+1,
                   method(xi ,yi + stl[flag]*(-1),stl,flag+1)+1);
    return min;
}