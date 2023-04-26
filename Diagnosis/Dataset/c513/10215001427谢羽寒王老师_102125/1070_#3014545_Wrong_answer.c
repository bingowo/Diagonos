#include <stdio.h>

int main()
{
    int c,i,r,all,e;

    while(scanf("%d",&c)!=EOF && c!=-1){
        all=1;
    for(i=0;i<c;i++){all*=2;}
    e=all*3/4;
    printf("%d\n",e);

    }



}