#include <stdio.h>
#include <stdlib.h>

int main()
{
    int W=0,H=0,D=0;
    char c;
    scanf("%d %d %d %c",&W,&H,&D,&c);
    D=D%360;
    D/=90;
    int** p=(int** )malloc(H*sizeof(int*));
    for(int h=0;h<H;h++){
        p[h]=(int* )malloc(W*sizeof(int));
        for(int w=0;w<W;w++){
            scanf("%d",&p[h][w]);
        }
    }
    if(D==0){
        printf("%d %d\n",W,H);
        for(int hh=0;hh<H;hh++){
            for(int ww=0;ww<W;ww++){
                printf("%d ",p[hh][ww]);
            }
            printf("\n");
        }
    }
    else if(D==2){
        printf("%d %d\n",W,H);
        for(int hh=H-1;hh>=0;hh--){
            for(int ww=W-1;ww>=0;ww--){
                printf("%d ",p[hh][ww]);
            }
            printf("\n");
        }
    }
    else if((D==1&&c=='R')||(D==3&&c=='L')){
        printf("%d %d\n",H,W);
        for(int ww=0;ww<W;ww++){
            for(int hh=H-1;hh>=0;hh--){
                printf("%d ",p[hh][ww]);
            }
            printf("\n");
        }
    }
    else{
        printf("%d %d\n",H,W);
        for(int ww=W-1;ww>=0;ww--){
            for(int hh=0;hh<H;hh++){
                printf("%d ",p[hh][ww]);
            }
            printf("\n");
        }
    }
    for(int i=0;i<H;i++){
        free(p[i]);
    }
    free(p);
    return 0;
}
