#include<stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++){
        printf("case #%d:\n", t);
        int pro[5][5]={0},d[5][2]={{-1,0},{1,0},{0,0},{0,-1},{0,1}};
        for (int i=1; i<=3; i++) {
            for (int j=1; j<=3; j++) {
                int temp=0;
                scanf("%d", &temp);
                for (int k=0; k<5; k++){
                    pro[i+d[k][0]][j+d[k][1]]+=temp;
                }
            }
        }  
        for (int i=1; i<=3; i++) {
            for (int j=1; j<=2; j++) {
                printf("%d ", (pro[i][j]+1)%2);
            }
            printf("%d\n", (pro[i][3]+1)%2);
        }
    }
    return 0;
}