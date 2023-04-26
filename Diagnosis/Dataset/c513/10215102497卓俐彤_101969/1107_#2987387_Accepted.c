#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int turn(int i){
    if(i)return 0;
    else return 1;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int lights[9]={1,1,1,1,1,1,1,1,1};
        int operate[9];
        for(int i=0;i<9;i++)scanf("%d",&operate[i]);
        for(int i=0;i<9;i++){
            while(operate[i]--){
                if((i+1)%3)lights[i+1]=turn(lights[i+1]);
                if(i<6)lights[i+3]=turn(lights[i+3]);
                if(i%3)lights[i-1]=turn(lights[i-1]);
                if(i>2)lights[i-3]=turn(lights[i-3]);
                lights[i]=turn(lights[i]);
            }
        }
        printf("case #%d:\n",t);
        for(int i=0;i<9;i++){
            printf("%d%c",lights[i],(i+1)%3?' ':'\n');
        }
    }
    return 0;
}
