#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long long a[1234567];
long long sum[1234567];
long long pre[12345];
int n,m;

int cmp(const void *st1,const void *st2){
    long long x=*(long long*)st1;
    long long y=*(long long*)st2;
    return x-y;
}

void work(){
    int num=0;
    for (int i=1;i<=n;i++){
        long long s=0;
        for (int j=i;j<=n;j++){
            s+=pre[j];
            num++;
            a[num]=s;
        }
    }
    qsort(a+1,num,sizeof(long long),cmp);
    sum[0]=0;
    for (int i=1;i<=num;i++)
        sum[i]=sum[i-1]+a[i];
}

int main(){
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        scanf("%d %d",&n,&m);
        printf("case #%d:\n",l-1);
        for (int i=1;i<=n;i++){
            scanf("%d",&pre[i]);
        }
        work();
        for (int i=1;i<=m;i++){
            int l,r;
            scanf("%d %d",&l,&r);
            long long ans=sum[r]-sum[l-1];
            printf("%lld\n",ans);
        }
    }
    return 0;
}
