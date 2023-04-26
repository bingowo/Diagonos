#include <stdio.h>
#include <string.h>
#define max(x,y) x > y ? x : y
#define min(x,y) x < y ? x : y
#define ll long long
unsigned long long ans;

ll GCD(unsigned long long x,unsigned long long y)
{
    ll mi = min(x,y);
    ll mx = max(x,y);
    while(mx%mi){
        ll res = mx%mi;
        mx = mi;
        mi = res;
    }
    return mi;
}

void count(unsigned long long x,unsigned long long y)
{
    if(x == y){
        ans += x*4;
        return;
    }
    else{
            if(x < y){
                ans += 4*x;
                count(x,y-x);
            }
            else{
                ans += 4*y;
                count(x-y,y);
            }
    }
}

int main()
{
    unsigned long long x,y;
    scanf("%llu %llu",&x,&y);
    unsigned long long time = GCD(x,y);
    x /= time;
    y /= time;
    if(x == 1 || y == 1) {
        ans = max(x,y);
        printf("%lld",ans*4);
    }
    else{
        count(x,y);
        printf("%llu",ans*time);
    }
    return 0;
}