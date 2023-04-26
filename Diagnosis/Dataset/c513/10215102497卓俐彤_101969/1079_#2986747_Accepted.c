#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b){
    return *((int*)a)-*((int*)b);
}


int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n,m,l,u;
        scanf("%d %d",&n,&m);
        int len=n*(n+1)/2;
        int num[n];
        int new_num[len];
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
            new_num[i]=num[i];
        }
        for(int i=0,index=n;i<n;i++){
            for(int j=i+1;j<n;j++){
                new_num[index]=num[j]+new_num[index-n+i];
                index++;
            }
        }
        qsort(new_num,len,sizeof(new_num[0]),cmp);
        printf("case #%d:\n",t);
        for(int i=0;i<m;i++){
            scanf("%d %d",&l,&u);
            long long int sum=0;
            for(int j=l-1;j<u;j++){
                sum+=new_num[j];
            }
            printf("%lld\n",sum);
        }
    }
    return 0;
}

