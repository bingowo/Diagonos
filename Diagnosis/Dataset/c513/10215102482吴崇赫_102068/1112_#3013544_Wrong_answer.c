#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define N 85

// 4w+3x+2y+z=n;

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        int n,cnt=0;
        scanf("%d",&n);
        for(int w=0;w<=n/4;++w){
            for(int x=0;x<=n/3;++x){
                for(int y=0;y<=n/2;++y){
                    if(4*w+3*x+2*y<=n)cnt++;
                }
            }
        }
        printf("case #%d:\n",x++);
        printf("%d\n",cnt);
    }
    return 0;
}