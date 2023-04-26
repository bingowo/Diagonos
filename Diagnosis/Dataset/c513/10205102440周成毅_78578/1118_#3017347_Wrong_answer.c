#include <stdio.h>
#include <stdlib.h>

int main() {
    int w,h,d;
    char c;
    scanf("%d %d %d %c",&w,&h,&d,&c);
    int **p=(int **) malloc(sizeof (int *)*h);
    for(int i=0;i<h;i++){
        p[i]=(int *) malloc(sizeof (int)*w);
        for(int j=0;j<w;j++)
            scanf("%d",&p[i][j]);
    }
    int tag;
    d/=90;
    tag=d%4;
    if(tag==0){
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++)
                printf("%d ",p[i][j]);
            printf("\n");
        }
    } else if(tag==2){
        for(int i=h-1;i>=0;i--){
            for(int j=w-1;j>=0;j--)
                printf("%d ",p[i][j]);
            printf("\n");
        }
    } else if(c=='R' && tag==1 || c=='L' && tag==3){
        for(int i=0;i<w;i++){
            for(int j=h-1;j>=0;j--)
                printf("%d ",p[i][j]);
            printf("\n");
        }
    } else{
        for(int i=w-1;i>=0;i--){
            for(int j=0;j<w;j++)
                printf("%d ",p[i][j]);
            printf("\n");
        }
    }
    return 0;
}
