#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){
    int *p=(int*)a;
    int *q=(int*)b;
    if(*p>*q) return 1;
    else return -1;
}
void ppprint(int n,int *a,int L,int  U){
    int b[1000000]={0};
    int k=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            b[k]=sum;
//            printf("%d\n",b[k]);
            k++;
        }
    }

//    qsort(b,k,sizeof (b[0]),cmp);
    int c=0;
    while(b[c]==0) c++;
//    for(int f=c;f<c+n;f++){
//        printf("%d\n",b[c]);
//    }

    int sum1=0;
    for(int f=c+L-1;f<=c+U-1;f++){
        sum1+=b[f];
    }
    printf("%d\n",sum1);
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
            int L,U;
            scanf("%d %d",&L,&U);
            ppprint(n,a,L,U);
        }
    }
    return 0;
}