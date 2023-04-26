#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
long long a=0,b=0,step=2;
int time;
long long res[66];
void solve(long long x,long long y)
{
    step*=2;
    if(a!=x&&b!=y)solve(x,y);
    else printf("%d",time);
}
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
    printf("%d\n",time);
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
        times(x,y);
        solve(x,y);
    }
    return 0;
}
