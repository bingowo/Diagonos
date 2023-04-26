#include<stdio.h>
int cmp(const void *a,const void *b){
    long long int a1,a2;
    a1=*(long long int*)a;
    a2=*(long long int*)b;
    if(a1>a2)return 1;
    else return -1;
    
    
    
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n,m;
        scanf("%d%d",&n,&m);
        long long int *a1,*a2,*a3,sum=0ll;
        a1=(long long int*)malloc((n+1)*sizeof(long long int));
        a2=(long long int*)malloc((n*(n+1)/2+1)*sizeof(long long int));
        a1[0]=0ll;
        for(int k=1;k<=n;k++){
            scanf("%lld",&a1[k]);
            a1[k]+=a1[k-1];
        }
        int tmp=0;
        for(int k=1;k<=n;k++){
            for(int len=1;len<=n-k-1;len++){
                a2[++tmp]=a1[len+k-1]-a1[len-1];
            }
        }
        a2[0]=0ll;
        for(int k=1;k<=tmp;k++)a2[k]+=a2[k-1];
        qsort(a2+1,tmp,sizeof(a2[0]),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<m;k++){
            int L,U;
            scanf("%d%d",&L,&U);
            printf("%lld\n",a2[U]-a2[L-1]);
            
        }
     
    }
    return 0;
  
}