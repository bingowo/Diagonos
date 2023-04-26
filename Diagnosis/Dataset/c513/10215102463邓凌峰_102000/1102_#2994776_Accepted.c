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
    lli a=sqrt(n);
    while(1){
        if((2*start+1)<=a && a<(2*start+3)) break;
        start++;
    }


    lli len=2*start+3;
    lli x=start,y=start;
    lli cnt=(len-2)*(len-2);
    if(cnt==n);
    else{
        y++;cnt++;
        if(cnt==n);
        else{
            if(cnt+len-2<=n){
                cnt+=len-2;
                x-=len-2;
            }
            else{
                lli c=1;
                while(c<len-1){
                    x--;
                    c++;
                    cnt++;
                    if(cnt==n) break;
                }
            }
            if(cnt==n);
            else{
                if(cnt+len-1<=n){
                    cnt+=len-1;
                    y-=len-1;
                }
                else{
                   lli c=1;
                    while(c<len){
                        y--;
                        c++;
                        cnt++;
                        if(cnt==n) break;
                    }
                }
                if(cnt==n);
                else{
                    if(cnt+len-1<=n){
                        cnt+=len-1;
                        x+=len-1;
                    }
                    else{
                      lli c=1;
                        while(c<len){
                            x++;
                            c++;
                            cnt++;
                            if(cnt==n) break;
                        }
                    }
                }
                if(cnt==n);
                else{
                    lli c=1;
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
