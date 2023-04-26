#include <stdio.h>
int L[200][200];
int NL[200][200];

int main()
{
    int W,H,D;
    char c;
    scanf("%d %d %d %c",&W,&H,&D,&c);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            scanf("%d",&L[i][j]);
        }
    }
    int NW,NH,num=(D/90)%4;
    if(c=='L') num=(4-num)%4;
    if(num==1 || num==3) {NW=H;NH=W;}
    else {NW=W;NH=H;}
    if(num==2){
        for(int i=0;i<=H/2;i++){
            for(int j=0;j<W;j++){
                int temp = L[i][j];
                L[i][j] = L[H-i-1][W-j-1];
                L[H-i-1][W-j-1]=temp;
            }
        }
        for(int i=0;i<NH;i++){
            for(int j=0;j<NW;j++){
                NL[i][j]=L[i][j];
            }
        }
    }else if(num==1){
        int m=NW-1, n=0;
        for(int i=0;i<H;i++){
            n=0;
            for(int j=0;j<W;j++){
                NL[n++][m]=L[i][j];
            }
            m--;
        }
    }else if(num==3){
        for(int i=0;i<=H/2;i++){
            for(int j=0;j<W;j++){
                int temp = L[i][j];
                L[i][j] = L[H-i-1][W-j-1];
                L[H-i-1][W-j-1]=temp;
            }
        }
        int m=NW-1, n=0;
        for(int i=0;i<H;i++){
            n=0;
            for(int j=0;j<W;j++){
                NL[n++][m]=L[i][j];
            }
            m--;
        }
    }else if(num==0){
    	for(int i=0;i<H;i++){
    		for(int j=0;j<W;j++){
    			NL[i][j]=L[i][j];
			}
		}
	}
    printf("%d %d\n",NW,NH);
    for(int i=0;i<NH;i++){
        for(int j=0;j<NW;j++){
            printf("%d%c",NL[i][j],j==NW-1?'\n':' ');
        }
    }
    return 0;
}