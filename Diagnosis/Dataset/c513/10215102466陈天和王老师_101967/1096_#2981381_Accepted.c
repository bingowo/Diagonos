#include <stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int N=0;
        int in[101]={0},out[101]={0},visit[101][101]={{0,0}};
        int isEqual = 1, a, b;

        scanf("%d",&N);
        for(int n=0;n<N;n++) {
            scanf("%d %d", &a, &b);
            if (visit[a][b] == 0) {
                visit[a][b] = 1;
                in[a]++, out[b]++;
            }
        }

        for(int i=0;i<101;i++){
            if(in[i]>1){
                isEqual=0;
                break;
            }
            else if(in[i] && out[i]){
                isEqual=0;
                break;
            }
        }

        if(isEqual){
            printf("Lucky dxw!\n");
        }else{
            printf("Poor dxw!\n");
        }

    }
    return 0;
}