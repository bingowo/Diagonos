#include <stdio.h>
typedef struct{
    int dig[8];
    int num[8];
    int min;
}vec;
int main() {
    int W,H;
    scanf("%d%d",&W,&H);
    int a[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            scanf("%d",&a[i][j]);
        }
    }
    vec ret[(H-2)*(W-2)];
    int p=0;
    for(int i=1;i<H-1;i++){
        for(int j=1;j<W-1;j++){
            ret[p].dig[0] = a[i-1][j-1]>=a[i][j]?1:0;
            ret[p].dig[1] = a[i-1][j]>=a[i][j]?1:0;
            ret[p].dig[2] = a[i-1][j+1]>=a[i][j]?1:0;
            ret[p].dig[3] = a[i][j+1]>=a[i][j]?1:0;
            ret[p].dig[4] = a[i+1][j+1]>=a[i][j]?1:0;
            ret[p].dig[5] = a[i+1][j]>=a[i][j]?1:0;
            ret[p].dig[6] = a[i+1][j-1]>=a[i][j]?1:0;
            ret[p].dig[7] = a[i][j-1]>=a[i][j]?1:0;
            for(int t=0;t<8;t++){
                int m=0;
                ret[p].num[t]=0;
                for(int cnt=t;cnt<8;cnt++,m++){
                    ret[p].num[t] =ret[p].num[t]*2+ret[p].dig[cnt];
                }
                if(m<8){
                    for(int cnt=0;8-m-cnt>0;cnt++){
                        ret[p].num[t] =ret[p].num[t]*2+ret[p].dig[cnt];
                    }
                }
                if(t!=0){
                    if(ret[p].num[t]<ret[p].min){
                        ret[p].min=ret[p].num[t];
                    }
                }else{
                    ret[p].min=ret[p].num[0];
                }
            }
            printf("%d%c",ret[p].min,j==W-2?'\n':' ');
            p++;
        }
    }
    return 0;
}
