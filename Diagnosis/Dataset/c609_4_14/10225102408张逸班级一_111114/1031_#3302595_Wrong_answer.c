#include<stdio.h>
#include<stdlib.h>
int cmp(const void*p1,const void*p2){
    return *(int*)p1-*(int*)p2;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
       printf("case #%d:\n",i);
       int n,m;
       scanf("%d %d",&n,&m);
       int my[n];
       int final[n*(n+1)/2];
       for(int i=0;i<n*(n+1)/2;i++){
        final[i]=0;
       }
       for(int j=0;j<n;j++)scanf("%d",&my[j]);
       int u=0;
       for(int i=0;i<n;i++){
        int count=0;         //比较妙的数据处理,读入子数列之和
        for(int j=i;j<n;j++){
        count+=my[j];
        final[u++]=count;
        }
       }
       qsort(final,u,sizeof(int),cmp);
       int front,behind;int ans;
       for(int k=0;k<m;k++){
       ans=0;
       scanf("%d %d",&front,&behind);
       for(int i=front-1;i<behind;i++){
        ans+=final[i];
       }   
       printf("%d\n",ans);
       }
    }
    return 0;
}