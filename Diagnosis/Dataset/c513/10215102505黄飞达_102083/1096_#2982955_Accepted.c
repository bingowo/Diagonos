#include<stdio.h>
#include<string.h>

int main(){
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++){
        int in[105]={0},out[105]={0};
        int used[105][105]={0};
        int N, flag=1;;
        scanf("%d", &N);
        for (int n=0; n<N; n++){
            int a,b;
            scanf("%d %d", &a, &b);
            if (!used[a][b]) {
                in[b]++,out[a]++;
                used[a][b]=1;
            }
        }
        for (int i=1; i<=100; i++){
            if (in[i]>0&&out[i]>0 || out[i]>1) {flag=0;break;}
        }
        if (flag==0) printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
        memset(in,0,105*4);
        memset(out,0,105*4);
        memset(used,0,105*105*4);
    }
    return 0;
}