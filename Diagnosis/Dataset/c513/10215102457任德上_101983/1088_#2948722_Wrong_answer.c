#include<stdio.h>
long long int cal(long long int left,long long int right){
    if(right==left)return right;
    return left*cal(left-1,right);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        long long int sum,m,n,a[41],son,mon;
        a[0]=1ll;
        a[1]=1ll;
        scanf("%lld%lld",&n,&m);
        if(m==0){printf("case #%d:\n1\n",i);continue;}
        son=cal(n,n-m+1ll);
        mon=cal(m,1ll);
        sum=son/mon;
        printf("case #%d:\n%lld\n",i,sum);
    }
    return 0;
}