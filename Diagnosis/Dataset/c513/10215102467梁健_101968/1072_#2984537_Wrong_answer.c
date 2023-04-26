#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
long long step;
int time;
long long res[66];
char order[65];char direct[65];
//确定正方向；
char xd1,xd2,yd1,yd2,xres,yres;
void solve(long long x,long long y)
{
    if(llabs(x)>llabs(y)){
        if(order[time-1]==0){
            x=x+step*xres;
            direct[time-1]=xd1;
        }
        else{
            x=x-step*xres;
            direct[time-1]=xd2;
        }
    }
    else{
        if(order[time-1]==0){
            y=y+step*yres;
            direct[time-1]=yd1;
        }
        else{
            y=y-step*yres;
            direct[time-1]=yd2;
        }
    }
    step/=2;
    time--;
    if(x!=0||y!=0)solve(x,y);
    else printf("%s",direct);
}
//确定一共走多少步
void times(long long x,long long y)
{
    long long unsigned dis=llabs(x)+llabs(y);
    if (dis==1)time=1;
    else{
        for(int i=2;i<64;i++){
            if(dis==res[i]){
                time=i;break;
            }
            else if(dis>res[i-1]&&dis<res[i]){
                time=i;break;
            }
        }
    }
}
//确定每一步正着走还是反着走 1反着走，0正着走
void ORD(long long x,long long y,int time)
{
    long long unsigned ord=res[time]-llabs(x)-llabs(y);
    ord/=2;
    for(int i=0;i<time;i++){
        order[i]=ord%2;
        ord/=2;
        printf("%d",order[i]);
    }
    printf("\n");
}
int main()
{
    long long k=2;res[1]=1;
    for(int i=2;i<65;i++){
        res[i]=k+res[i-1];
        k*=2;
    }
    long long x,y;scanf("%lld %lld",&x,&y);
    if(x==0&&y==0)printf("0");
    else if(x%2&&y%2)printf("-1");
    else if(x%2==0&&y%2==0)printf("-1");
    else {
        if(x>0){
            xd1='E';xd2='W';xres=-1;
        }
        else {
            xd1='W';xd2='E';xres=1;
        }
        if(y>0){
            yd1='N';yd2='S';yres=-1;
        }
        else {
            yd1='S';yd2='N';yres=1;
        }
        times(x,y);
        ORD(x,y,time);
        step=(res[time]+1)/2;
        direct[time]=0;
        solve(x,y);
    }
    return 0;
}
