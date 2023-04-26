#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>


int main()
{
    int W,H,D;char c;
    //W:width H:height D:degree c:direction
    scanf("%d %d %d %c",&W,&H,&D,&c);
    int pic[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            scanf("%d",&pic[i][j]);
        }
    }
    D/=90;
    if(D%2)printf("%d %d\n",H,W);
    else printf("%d %d\n",W,H);
    if(c=='R'){
        if(D%4==0){
            for(int i=0;i<H;i++){
                for(int j=0;i<W;j++){
                    printf("%d ",pic[i][j]);
                }
                printf("\n");
            }
        }
        else if(D%4==1){

        }
        else if(D%4==2){

        }
        else if(D%4==3){

        }
    }
    else if(c=='L'){
        if(D%4==0){
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++)
                    printf("%d ",pic[i][j]);
                printf("\n");
            }
        }
        else if(D%4==1){

        }
        else if(D%4==2){

        }
        else if(D%4==3){

        }
    }
    return 0;
}
