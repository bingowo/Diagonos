#include<stdio.h>
#include<string.h>

int cmp(const void* a,const void* b){
    int m=*(int *)a,n=*(int *)b;
    int t=m-n;
    return t;
}

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        int n,m;
        scanf("%d%d",&n,&m);
        int num[n],l=n*(n+1)/2;
        int sum[l];
        for(int i=0;i<n;i++)scanf("%d",&num[i]);
        for(int i=0;i<l;i++)sum[i]=0;
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                sum[k]+=num[j];
                if(j!=i)sum[k]+=sum[k-1];
                k++;
            }
        }
        qsort(sum,l,sizeof(int),cmp);
        printf("case #%d:\n",a);
        while(m--){
            int l,u;long long s=0;
            scanf("%d%d",&l,&u);
            for(int i=l-1;i<u;i++)s+=sum[i];
            printf("%lld\n",s);
        }
        a++;
        
    }
}