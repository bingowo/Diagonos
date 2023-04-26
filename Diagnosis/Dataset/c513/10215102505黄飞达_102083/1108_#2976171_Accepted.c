#include<stdio.h>
int main(){
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++){
        printf("case #%d:\n", t);
        int n, m;
        scanf("%d %d", &n, &m);
        int mem[1005]={0}, res[100]={0};
        int end=0, index=0;
        while(1){
            res[index++]=n/m;
            n-=n/m*m;
            n*=10;
            if (mem[n]!=0){end=index-1;break;}
            else mem[n]=index;
            if (n==0) break;
        }
        printf("%d", res[0]);
        if (index>1) printf(".");
        for (int i=1; i<index; i++) printf("%d", res[i]);
        printf("\n");
        if (end!=0) printf("%d-%d\n", mem[n], end);
    }
    return 0;
}