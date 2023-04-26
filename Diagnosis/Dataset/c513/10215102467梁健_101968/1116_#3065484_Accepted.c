#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    long long step[63];
    long long k=1;
    for(int i=0;i<63;i++){
        step[i]=k;
        k*=2;
    }
    long long x,y;scanf("%lld %lld",&x,&y);
    if(x==0&&y==0)printf("0");
    else if((llabs(x)+llabs(y))%2==0)printf("-1\n");
    else{
        int res=0;
        long long unsigned dis=llabs(x)+llabs(y);
        if(dis==1)res=1;
        else for(int i=0;i<62;i++){
            if(dis>step[i]&&dis<step[i+1]){
                res=i+1;break;
            }
        }
        printf("%d",res);
    }
    return 0;
}
