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
        int a1[100]={0},a2[100]={0};
        for(int i=0;i<n;i++){
            scanf("%d",&a1[i]);
            scanf("%d",&a2[i]);
        }
        qsort(a1,n,sizeof(int),cmp);
        qsort(a2,n,sizeof(int),cmp);
        int a[2*n];
        a[0]=a1[0];
        a[1]=a2[0];
        int p=2;
        int sign=0;
        for(int j=1;j<n;j++){
            if(a1[j]!=a1[j-1]){
                a[p]=a1[j];
                p++;
            }else{
                printf("Poor dxw!\n");
                return 0;
            }
            if(a2[j]!=a2[j-1]){
                a[p]=a2[j];
                p++;
            }
        }
        qsort(a,p,sizeof(int),cmp);
        for(int j=1;j<p;j++){
            if(a[j]==a[j-1]){
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
