#include <stdio.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2){
    return *(int *)p1-*(int *)p2;
}
int main() {
    int T;
    scanf("%d",&T);
    while (T--){
        int n;
        scanf("%d",&n);
        int a1[200]={0},a2[100]={0};
        for(int i=0;i<n;i++){
            scanf("%d%d",&a1[i],&a2[i]);
        }
        qsort(a1,n,sizeof(int),cmp);
        qsort(a2,n,sizeof(int),cmp);
        int sign=0;
        for(int p=1;p<n;p++){
            if(a1[p]==a1[p-1]){
                sign=1;
                printf("Poor dxw!\n");
            }
        }
        if(sign){
            continue;
        }
        a1[n]=a2[0];
        int j=n+1;
        for(int m=1;m<n;m++){
            if(a2[m]!=a2[m-1]){
                a1[j] = a2[m];
            }
        }
        qsort(a1,j,sizeof(int),cmp);
        for(int t=1;t<j;t++){
            if(a1[t]==a1[t-1]){
                sign=1;
                break;
            }
        }
        if(sign){
            printf("Poor dxw!\n");
        }else{
            printf("Lucky dxw!\n");
        }
    }
    return 0;
}
