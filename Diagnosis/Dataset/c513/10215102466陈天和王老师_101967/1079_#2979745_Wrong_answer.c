#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long int llu;
int cmp(const void*a,const void*b){
    int *p=(int*)a;
    int *q=(int*)b;
    if(*p>*q) return 1;
    else return -1;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int m,n;
        scanf("%d%d",&n,&m);
        int a[n];
        int b[n*(n+1)/2];
        
        int k=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=a[j];
                b[k]=sum;
                k++;
            }
        }
        
        qsort(b,k,sizeof (b[0]),cmp);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int _m=0;_m<m;_m++){
            int L,U;
            scanf("%d%d",&L,&U);
            llu sum1=0;
            for(long long int f=L-1;f<=U-1;f++){
                sum1+=b[f];
            }
            printf("%llu\n",sum1);
        }
    }
    return 0;
}