#include <stdio.h>
#include <string.h>
#define max(x,y) x > y ? x : y
#define min(x,y) x < y ? x : y

long long int ans;

void count(long long int x,long long int y)
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
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    count(x,y);
    printf("%lld",ans);
    return 0;
}