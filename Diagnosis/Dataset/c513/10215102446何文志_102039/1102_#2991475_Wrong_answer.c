#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Point{
    long long x;
    long long y;
}pt;

pt getPt(long long n){
    pt res; res.x = 0; res.y = 0;
    long long cnt = 0, step = 1;
    char drct = 'U';
    while(cnt<n){
        //printf("drct = %c ",drct);
        if(drct=='U'){
            res.y+=step;
            cnt+=step;

            drct = 'L';
        }
        else if(drct=='L'){
            res.x-=step;
            cnt+=step;
            step++;
            drct = 'D';
        }
        else if(drct=='D'){
            res.y-=step;
            cnt+=step;

            drct = 'R';
        }
        else if(drct=='R'){
            res.x+=step;
            cnt+=step;
            step++;
            drct = 'U';
        }

        //printf("(%lld, %lld), cnt = %lld\n",res.x,res.y,cnt);
    }


    return res;

}

int main()
{
    long long n = 0;
    scanf("%lld",&n);
    pt ans = getPt(n);
    printf("(%lld,%lld)\n",ans.x,ans.y);
    return 0;
}
