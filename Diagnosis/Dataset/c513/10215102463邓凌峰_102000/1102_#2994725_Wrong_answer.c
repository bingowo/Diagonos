#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 500500
#define BigNUm 10007

typedef long long lli;

int main()
{
    lli n;scanf("%lld",&n);

    n++;

    lli start=0;
    while(1){
        if((2*start+1)*(2*start+1)<=n && n<(2*start+3)*(2*start+3)) break;
        start++;
    }

    printf("%lld\n",start);

    lli len=2*start+3;
    lli x=start,y=start;
    lli cnt=(len-2)*(len-2);
    if(cnt==n);
    else{
        y++;cnt++;
        if(cnt==n);
        else{
            int c=1;
            while(c<len-1){
                x--;
                c++;
                cnt++;
                if(cnt==n) break;
            }
            if(cnt==n);
            else{
                int c=1;
                while(c<len){
                    y--;
                    c++;
                    cnt++;
                    if(cnt==n) break;
                }
                if(cnt==n);
                else{
                    int c=1;
                    while(c<len){
                        x++;
                        c++;
                        cnt++;
                        if(cnt==n) break;
                    }
                }
                if(cnt==n);
                else{
                    int c=1;
                    while(c<len){
                        y++;
                        c++;
                        cnt++;
                        if(cnt==n) break;
                    }
                }
            }
        }
    }

    printf("(%lld,%lld)",x,y);





    return 0;
}
