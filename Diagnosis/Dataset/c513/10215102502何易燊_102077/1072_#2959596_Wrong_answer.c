#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    char ans[71] = {}; int index = 0;
    if (!(x+y)&1) {printf("-1\n"); return 0;}
    if (x==0&&y==0) {printf("0\n"); return 0;}
    while (x||y)
    {
        if (x&1)
        {
            if (x==1) {ans[index++] = 'E'; x--;}
            else if (x==-1) {ans[index++] = 'W'; x++;}
            else if (((x+1)/2+y/2)&1) {ans[index++] = 'W'; x++;}
            else {ans[index++] = 'E'; x--;}
        }
        else
        {
            if (y==1) {ans[index++] = 'N'; y--;}
            else if (y==-1) {ans[index++] = 'S'; y++;}
            else if (((y+1)/2+x/2)&1) {ans[index++] = 'S'; y++;}
            else {ans[index++] = 'N'; y--;}
        }
        x /= 2; y /= 2;
    }
    printf("%d\n%s\n",index,ans);
    return 0;
}