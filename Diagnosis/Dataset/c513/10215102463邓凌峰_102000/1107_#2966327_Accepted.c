#include <stdio.h>
#include <stdlib.h>
#include <string.h>y




void doIt(int lights[3][3],int r,int c){
    lights[r][c]=1-lights[r][c];

    int tmpr=r+1,tmpc=c;
    if(tmpr>-1 && tmpr<3 && tmpc>-1 && tmpc<3){
        lights[tmpr][tmpc]=1-lights[tmpr][tmpc];
    }

    tmpr=r;tmpc=c+1;
    if(tmpr>-1 && tmpr<3 && tmpc>-1 && tmpc<3){
        lights[tmpr][tmpc]=1-lights[tmpr][tmpc];
    }

    tmpr=r-1;tmpc=c;
    if(tmpr>-1 && tmpr<3 && tmpc>-1 && tmpc<3){
        lights[tmpr][tmpc]=1-lights[tmpr][tmpc];
    }

    tmpr=r;tmpc=c-1;
    if(tmpr>-1 && tmpr<3 && tmpc>-1 && tmpc<3){
        lights[tmpr][tmpc]=1-lights[tmpr][tmpc];
    }
}

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        int lights[3][3];;
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
                lights[r][c]=1;
            }
        }

        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
                int dos;scanf("%d",&dos);
                while(dos--) doIt(lights,r,c);
            }
        }

        printf("case #%d:\n",i);
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
                printf("%d%c",lights[r][c],c==2?'\n':' ');
            }
        }


    }

    return 0;
}
