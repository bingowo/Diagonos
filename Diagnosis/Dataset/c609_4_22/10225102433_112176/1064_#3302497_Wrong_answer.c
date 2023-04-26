#include <stdio.h>
#include <string.h>
#define max(x,y) x > y ? x : y
#define min(x,y) x < y ? x : y

int ans;

void count(int x,int y)
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
    int x,y;
    scanf("%d %d",&x,&y);
    count(x,y);
    printf("%d",ans);
    return 0;
}