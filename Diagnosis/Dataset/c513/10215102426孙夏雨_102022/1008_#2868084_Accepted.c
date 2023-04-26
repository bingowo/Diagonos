#include <stdio.h>
#include <stdlib.h>

int f(int x,int y)
{
    int d=0;
    while(x>0||y>0){
        int x1=1&x,y1=1&y;
        if ((x1^y1)==1) d++;
        x=x>>1;
        y=y>>1;
    }
    return d;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        int res=f(x,y);
        printf("%d\n",res);
    }
    return 0;
}
