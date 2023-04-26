#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a, const void*b){
    return *(int*)a < *(int*)b ? -1 : 1;
}


int main(){
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++){
        int n, m;
        scanf("%d %d", &n, &m);
        int oldarr[1001] = {0};
        int newarr[500500] = {0};
        for (int i=0; i<n; i++) scanf("%d", &oldarr[i]);
        int index = 0;

        for (int i=0; i<n; i++){//长度
            for (int j=0; j+i<n; j++){//起始位
                for (int k=0; k<=i; k++){
                    newarr[index] += oldarr[j+k];
                }
                index++;
            }
        }
        qsort(newarr, index, sizeof(int), cmp);
        printf("case #%d:\n", t);
        for (int i=1; i<index; i++) newarr[i] += newarr[i-1];
        for (int i=0; i<m; i++){
            int l, u;
            scanf("%d %d", &l, &u);
            printf("%d\n", newarr[u-1]-newarr[l-2]);
        }
    }
    return 0;
}