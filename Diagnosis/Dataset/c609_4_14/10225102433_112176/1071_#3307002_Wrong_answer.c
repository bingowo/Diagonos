#include <stdio.h>
#include <math.h>

int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    int key = abs(x)+abs(y);
    if(key % 2){
        int ans = log(key-1)/log(2)+1;
        printf("%d",ans);
    }
    else printf("-1");
    return 0;
}