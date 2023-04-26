#include <stdio.h>
#include <stdlib.h>

int main()
{
    int W=0,H=0;
    scanf("%d %d",&W,&H);
    int** yuan=(int** )malloc(H*sizeof(int* ));
    for(int h=0;h<H;h++){
        yuan[h]=(int* )malloc(W*sizeof(int));
        for(int w=0;w<W;w++) scanf("%d",&yuan[h][w]);
    }
    int* p=(int* )malloc(8*sizeof(int));
    for(int i=1;i<H-1;i++){
        for(int j=1;j<W-1;j++){
            p[0]= yuan[i-1][j-1]>=yuan[i][j] ? 1:0;
            p[1]= yuan[i-1][j]>=yuan[i][j] ? 1:0;
            p[2]= yuan[i-1][j+1]>=yuan[i][j] ? 1:0;
            p[3]= yuan[i][j+1]>=yuan[i][j] ? 1:0;
            p[4]= yuan[i+1][j+1]>=yuan[i][j] ? 1:0;
            p[5]= yuan[i+1][j]>=yuan[i][j] ? 1:0;
            p[6]= yuan[i+1][j-1]>=yuan[i][j] ? 1:0;
            p[7]= yuan[i][j-1]>=yuan[i][j] ? 1:0;
            int jieguo=0,min=0;
            for(int k=0;k<8;k++){
                for(int l=0;l<8;l++){
                    int ci= k+l>=8? k+l-8:k+l;
                    jieguo=jieguo*2+p[ci];
                }
                if(k==0) min=jieguo;
                if(jieguo<min) min=jieguo;
                jieguo=0;
            }
            printf("%d",min);
            if(j<W-2) printf(" ");
        }
        printf("\n");
    }
    free(p);
    for(int e=0;e<H;e++){
        free(yuan[e]);
    }
    free(yuan);
    return 0;
}
