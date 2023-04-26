#include<stdio.h>
#include<stdlib.h>
int cmp(const void*p1,const void*p2){
    if( *(long long*)p1>*(long long*)p2)return 1;
    else return -1;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
       printf("case #%d:\n",i);
       int n,m;
       scanf("%d %d",&n,&m);
       long long my[n];
       long long final[n*(n+1)/2];
       for(int i=0;i<n*(n+1)/2;i++){
        final[i]=0;
       }
       for(int j=0;j<n;j++)scanf("%lld",&my[j]);
       int u=0;
       for(int i=0;i<n;i++){
        long long count=0;         //比较妙的数据处理,读入子数列之和
        for(int j=i;j<n;j++){
        count+=my[j];
        final[u++]=count;
        }
       }
       qsort(final,u,sizeof(int),cmp);
       int front,behind;long long ans;
       for(int k=0;k<m;k++){
       ans=0;
       scanf("%d %d",&front,&behind);
       for(int i=front-1;i<behind;i++){
        ans+=final[i];
       }   
       printf("%lld\n",ans);
       }
    }
    return 0;
}