#include <stdio.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2){
    int *a= (int *)p1;
    int *b= (int *)p2;
    return *a -*b;
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        //getchar();
        int a[n];
        int b[n];
        for(int j = 0;j<n;j++){
            scanf("%d",&a[j]);
            //getchar();
        }
        for(int p = 0;p<n;p++){
            scanf("%d",&b[p]);
            getchar();
        }
        qsort(a,n,sizeof(int),cmp);
        qsort(b,n,sizeof(int),cmp);
        int sum =0;
        for(int q =0;q<n;q++){
            sum = sum+a[q]*b[n-q-1];
        }
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;
}
