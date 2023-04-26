#include <stdio.h>

char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int b[1000];


void trans(int N,int R){
    int num=0;
    while (N>0){
        b[num++]=a[N%R];
        N=N/R;
    }
    num--;
    for(int j=num-1;j>=0;j--){
        printf("%c",b[num]);
    }
    printf("\n");
}
int main() {
    int t;
    int N,R;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        scanf("%d %d",&N,&R);
        if(N<0) printf("-");
        else {
            trans(N, R);
        }
    }
    return 0;
}