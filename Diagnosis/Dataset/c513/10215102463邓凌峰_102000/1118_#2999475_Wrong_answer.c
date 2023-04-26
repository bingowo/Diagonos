#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 200
#define BigNUm 10007
#define Max 1000000

typedef long long lli;


int picture[LEN][LEN]={0};
int ans[LEN][LEN]={0};




int main(){
    int W,H,D;char type;
    scanf("%d %d %d %c",&W,&H,&D,&type);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            scanf("%d",&picture[i][j]);
        }
    }
    if((D/90)%4==0){
        printf("%d %d\n",W,H);
        for(int r=0;r<H;r++){
            for(int c=0;c<W;c++){
                printf("%d%c",picture[r][c],c==W-1?'\n':' ');
            }
        }
    }

    // else if((D/90)%4==2){
    //     printf("%d %d\n",W,H);
    //     for(int r=H-1;r>=0;r--){
    //         for(int c=W-1;c>=0;c--){
    //             printf("%d%c",picture[r][c],c==0?'\n':' ');
    //         }
    //     }
    // }

    else if((type=='R'&&(D/90)%4==1)||(type=='L'&&(D/90)%4==3)){

    }








    return 0;

}
