#include <stdio.h>
#include <stdlib.h>

int main(){
    int W,H,D;
    char ch;
    scanf("%d%d%d %c",&W,&H,&D,&ch);
    int p[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            scanf("%d",&p[i][j]);
        }
    }
    int d=(D/90)%4;
    if(ch=='R'){
        if(d==1){
            int w=H,h=W;
            printf("%d %d\n",w,h);
            for(int i=0;i<W;i++){
                for(int j=H-1;j>=0;j--){
                    printf("%d ",p[j][i]);
                }
                printf("\n");
            }
        }
        if(d==3){
            int w=H,h=W;
            printf("%d %d\n",w,h);
            for(int i=W-1;i>=0;i--){
                for(int j=0;j<H;j++){
                    printf("%d ",p[j][i]);
                }
                printf("\n");
            }
        }
        else if(d==0){
            printf("%d %d\n",W,H);
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                        printf("%d ",p[i][j]);
                }
                printf("\n");
            }
        }
        else if(d==2){
            printf("%d %d\n",W,H);
            for(int i=H-1;i>=0;i--){
                for(int j=0;j<W;j++){
                        printf("%d ",p[i][j]);
                }
                printf("\n");
            }
        }
    }
    else if(ch=='L'){
        if(d==3){
            int w=H,h=W;
            printf("%d %d\n",w,h);
            for(int i=0;i<W;i++){
                for(int j=H-1;j>=0;j--){
                    printf("%d ",p[j][i]);
                }
                printf("\n");
            }
        }
        if(d==1){
            int w=H,h=W;
            printf("%d %d\n",w,h);
            for(int i=W-1;i>=0;i--){
                for(int j=0;j<H;j++){
                    printf("%d ",p[j][i]);
                }
                printf("\n");
            }
        }
        else if(d==0){
            printf("%d %d\n",W,H);
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                        printf("%d ",p[i][j]);
                }
                printf("\n");
            }
        }
        else if(d==2){
            printf("%d %d\n",W,H);
            for(int i=H-1;i>=0;i--){
                for(int j=0;j<W;j++){
                        printf("%d ",p[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
