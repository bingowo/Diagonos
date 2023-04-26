//思路：用十进制数转换后的二进制数与1按位与计算，若不为1，表示其最后一位不是1
//将1的64位2进制表示整体左移一位检查倒数第二位是否为1
#include<stdio.h>
#include<stdlib.h>
int binary(long long int a){
    int m=0;
    long long int n=1;
    for(int i=64;i>0;i--,a>>1)m+=(a&n);
    return m;
}
int cmp(const void*a,const void *b){
    int m,n;
    long long int a1,b1;
    a1=*(long long int*)a,b1=*(long long int *)b;
    m=binary(a1);
    n=binary(b1);
    if(m>n)return -1;
    if(m<n)return 1;
    else return -1;
}
int main(){
    int T,N,order=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        long long int m[10000];
        int i=0;
        while(N--)scanf("%lld",&m[i++]);
        qsort(m,i,sizeof(long long int),cmp);
        printf("case #%d:\n",order++);
        for(int p=0;p<i;p++)printf("%lld",m[p]);
        printf("\n");
    }
    return 0;
}