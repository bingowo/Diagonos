#include <stdio.h>
#include<stdlib.h>
int a[1001]; //存累计得到的
long long int b[500501];
int cmp(const void *a,const void *b){
    int* A = (int *)a;
    int* B = (int*)b;
    return *A - *B;

}

int main(){
    int set = 0;
    scanf("%d",&set);
    for (int i = 0; i < set;i++){
        int n = 0;//数列长度
        int m = 0;//lu求解个数
        scanf("%d %d",&n,&m);
        for (int j  = 1;j <= n;j++){
            scanf("%d",a+j);
            a[j]+=a[j-1];//完成前方求和
        }
        int cnt = 0;
        for(int len = 1; len <= n;len++){
            for(int k = 1; k <= n-len+1;k++){
                b[++cnt] = a[k+len-1]-a[k-1];
            }
        }
        qsort(b,n*(n+1)/2,sizeof(b[0]),cmp);
        for(int l = 0; l < cnt;l++){
            b[l] += b[l-1];
        }

        //解决U L
        printf("case #%d:\n",i);
        for(int u_i = 0; u_i < m;u_i++){
            int u = 0;
            int l = 0;
            scanf("%d %d",&l,&u);
            printf("%d\n",b[u]-b[l-1]);
        }

    }
}