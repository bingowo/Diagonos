#include <stdlib.h>
#include <stdio.h>
typedef unsigned long long int llu;
llu max(llu a,llu b)
{
    if(a>b) return a;
    else return b;
}
llu min(llu a,llu b)
{
    if(a<b) return a;
    else return b;
}
int main()
{
    llu x,y,out=0;
    scanf("%llu %llu",&x,&y);
    x=max(x,y);
    y=min(x,y);
    if(x%y==0){
        printf("%llu",(x/y)*4*y);
    }
    else{
    while(x%y!=0){
        out=out+(x/y)*4*y;
        x=max(x-(x/y)*y,y);
        y=min(x-(x/y)*y,y);
    }
    printf("%llu",out);
    }
}
