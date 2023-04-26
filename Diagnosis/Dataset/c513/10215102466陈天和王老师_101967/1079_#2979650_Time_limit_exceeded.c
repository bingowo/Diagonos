#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){
    int *p=(int*)a;
    int *q=(int*)b;
    if(*p>*q) return 1;
    else return -1;
}
void ppprint(int n,int *a,long long int L,long long int  U){
    int b[n*(n+1)/2];
//    qsort(a,n,sizeof (a[0]),cmp);
    int k=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            b[k]=sum;
            k++;
        }
    }
//    for(int f=0;f<k;f++){
//        printf("%d\n",b[f]);
//    }

    qsort(b,k,sizeof (b[0]),cmp);
//    while(b[c]==0) c++;
//    for(int f=c;f<c+n;f++){
//        printf("%d\n",b[c]);
//    }

    long long int sum1=0;
    for(long long int f=L-1;f<=U-1;f++){
        sum1+=b[f];
    }
    printf("%llu\n",sum1);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int m,n,a[1001]={0};
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int _m=0;_m<m;_m++){
            long long int L,U;
            scanf("%llu %llu",&L,&U);
            ppprint(n,a,L,U);
        }
    }
    return 0;
}