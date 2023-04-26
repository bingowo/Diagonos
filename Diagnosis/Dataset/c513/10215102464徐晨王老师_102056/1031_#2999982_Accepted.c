#include <stdio.h>
#include <stdlib.h>

int cmp1(const void*a,const void*b){
    int x=*(int*)a;
    int y=*(int*)b;
    return x<y;
}
int cmp2(const void*a,const void*b){
    int x=*(int*)a;
    int y=*(int*)b;
    return x>y;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n;
        scanf("%d",&n);
        int p1[n],p2[n];
        for(int i=0;i<n;i++){
            scanf("%d",&p1[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&p2[i]);
        }
        qsort(p1,n,sizeof(p1[0]),cmp1);
        qsort(p2,n,sizeof(p2[0]),cmp2);
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+p1[i]*p2[i];
        }
        printf("case #%d:\n%d\n",t,sum);
    }
}