#include <stdio.h>

int mm[100][100];
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};
int bit[8];

void solve(int x, int y){
    for(int i=0;i<8;i++){
        if(mm[x+dx[i]][y+dy[i]]>=mm[x][y])
            bit[i]=1;
        else
            bit[i]=0;
    }
    int place=0,num=0,tmp=0,tmp1=0;
    for(int i=0;i<16;i++){
        if(!bit[i%8]){
            tmp++;
        } else{
            if(tmp>num) {
                num = tmp;
                place = tmp1;
            }
            tmp=0;
            tmp1=i%8+1;
        }
    }
    if(num>8)
        printf("0 ");
    else{
        int sum=0;
        for(int i=place;i<place+8;i++)
            sum=2*sum+bit[i%8];
        printf("%d ",sum);
    }
}

int main() {
    int w,h;
    scanf("%d %d",&w,&h);
    for(int i=0;i<h;i++)
        for (int j = 0; j < w; ++j)
            scanf("%d",&mm[i][j]);
    for(int i=1;i<h-1;i++){
        for(int j=1;j<w-1;j++)
            solve(i,j);
        printf("\n");
    }

    return 0;
}
