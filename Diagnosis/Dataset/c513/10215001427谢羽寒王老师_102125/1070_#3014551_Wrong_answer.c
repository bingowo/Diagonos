#include <stdio.h>

int main()
{
    int c,i,r,all,e;

    while(scanf("%d",&c)!=EOF && c!=-1){
        all=1;e=1;
    for(i=0;i<c;i++){all*=2;}
    for(i=0;i<c-3;i++){e*=2;}
    r=all-e*(c-2);
    printf("%d\n",r);

    }



}
