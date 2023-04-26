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

        //printf("(%lld, %lld), cnt = %lld, drct = %c\n",res.x,res.y,cnt,drct);
    }
    long long dif = cnt-n;
    //printf("dif = %lld\n",dif);
    if(drct=='U'){//上次为R
        res.x-=dif;
    }
    else if(drct=='L'){//上次为U
        res.y-=dif;
    }
    else if(drct=='D'){//上次为L
        res.x+=dif;
    }
    else if(drct=='R'){//上次为D
        res.y+=dif;
    }
    //printf("(%lld, %lld), cnt = %lld, drct = %c\n",res.x,res.y,cnt,drct);
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
