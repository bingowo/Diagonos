#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ways(int now,int t,int m,int n,int time){
    if(time==m){
        if(now==t) return 1;
        else return 0;
    }
    if(now==1) return ways(2,t,m,n,time+1);
    if(now==n) return ways(n-1,t,m,n,time+1);
    else return ways(now+1,t,m,n,time+1)+ways(now-1,t,m,n,time+1);
}


int main()
{
    int cas;scanf("%d",&cas);
    for(int i=0;i<cas;i++){
        int n,p,m,t;scanf("%d%d%d%d",&n,&p,&m,&t);
        printf("%d\n",ways(p,t,m,n,0));

    }
    return 0;

}
