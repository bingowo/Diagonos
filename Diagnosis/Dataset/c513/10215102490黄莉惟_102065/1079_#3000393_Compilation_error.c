#include<stdio.h>#include<string.h>#include <stdlib.h>int cmp(const void* a,const void* b){       long long int ua=*(long long int*)a;    long long int ub=*(long long int*)b;    return ua<ub?1:-1;}int main(){    int T,i;    scanf("%d",&T);    for(i=0;i<T;i++){        int a[1001]={0};        long long int b[500501]={0};        int m,n;        int L,U;        printf("case #%d:\n",i);        scanf("%d %d",&m,&n);        for(int k=0;k<m;k++){            scanf("%d %d",&L,&U);            int cnt=0;            for(int j=1;j<=n;j++) {scanf("%d",a+j);a[j]+=a[j-1];}            for(int len=1;len<=n;len++)                for(int i=1;i<=n-len+1;i++)                    b[++cnt]=a[i+len-1]-a[i-1];            qsort(b,cnt,sizeof(b[0]),cmp);  //数组b排序            for(int i=1;i<=cnt;i++) b[i]+=b[i-1];            printf("%lld",b[U]-b[L-1]);        }            }} }