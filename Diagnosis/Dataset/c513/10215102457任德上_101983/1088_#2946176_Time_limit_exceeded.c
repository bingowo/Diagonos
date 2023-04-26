#include<stdio.h>
long long int cal(long long int left,long long int right){
    if(right==left)return right;
    return left*cal(left-1,right);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        long long int sum,m,n,a[41],max,son,mon;
        a[0]=1;
        a[1]=1;
        scanf("%d%d",&n,&m);
        if(m==0){printf("case #%d:\n1\n");continue;}
        son=cal(n,n-m+1);
        mon=cal(m,1);
        sum=son/mon;
        printf("case #%d:\n%lld\n",i,sum);
    }
    return 0;
}
