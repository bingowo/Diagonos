#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n,m;
        scanf("%d%d",&n,&m);
        long long int *a1,*a2,*a3,sum=0ll;
        a1=(long long int*)malloc((n+1)*sizeof(long long int));
        a2=(long long int*)malloc(n*(n+1)/2*sizeof(long long int));
        a1[0]=0ll;
        for(int k=1;k<=n;k++){
            scanf("%lld",&a1[k]);
            a1[k]+=a1[k-1];
        }
        int tmp=0;
        for(int k=1;k<=n;k++){
            for(int len=0;len<=n-k;len++){
                a2[tmp++]=a1[len+k]-a1[len];
            }
        }
        printf("case #%d:\n",i);
        for(int k=0;k<m;k++){
            int L,U;
            scanf("%d%d",&L,&U);
            printf("%lld\n",a2[U-1]-a2[L-1]);
            
        }
     
    }
    return 0;
  
}