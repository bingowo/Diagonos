#include <stdio.h>
#include <stdlib.h>

long long ans=0;

void find(int x,int y){
    if (y==0) return;
    ans+=(x/y)*4*y;
    find(y,x%y);
}

int main()
{
    long long x,y;
    scanf("%d %d",&x,&y);
    if (x>y) find(x,y);
    else find(y,x);
    printf("%d",ans);
    return 0;
}
