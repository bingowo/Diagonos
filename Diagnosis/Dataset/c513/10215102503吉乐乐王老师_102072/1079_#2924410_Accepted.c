#include<stdio.h>
#include<stdlib.h>
long long int *sum(long long int *pb,int a[],int n,int cnt){
    for(int i=0;i<n;i++){
        long long int ret=0;int j=i;
        if(j+cnt<=n){
            int k=cnt;
            while(k--){
                ret+=a[j];j++;
            }
            *pb=ret;pb++;
        }
        else break;
    }
    return pb;
}
int cmp(const void *a,const void *b){
    return *(long long int *)a-*(long long int *)b;
}
int main(){
    int t;scanf("%d",&t);getchar();int cas=0;
    while(t--){
        int n,m;scanf("%d %d",&n,&m);getchar();
        int *a=(int *)malloc(sizeof(int)*(n));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        long long int *b=(long long int *)malloc(sizeof(long long int )*1000005);
        long long int *pb=b;
        for(int i=1;i<=n;i++){
            pb=sum(pb,a,n,i);
        }
        long long int *p=b;int len=pb-p;
        qsort(b,len,sizeof(b[0]),cmp);
        printf("case #%d:\n",cas++);
        while(m--){
            int l,u;
            scanf("%d %d",&l,&u);long long int nsum=0;
            for(int i=l-1;i<=u-1;i++){
                nsum+=b[i];
            }
            printf("%lld\n",nsum);
        }
    }
}