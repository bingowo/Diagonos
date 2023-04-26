#include<stdio.h>
long long int Pow(long long int a,long long int n){
    if(n==0LL)return 1LL;
    else if(n==1LL)return a;
    else{
        long long int r=1LL;
        while(n>0LL){
            if(n%2LL)r=(a*r)%10007LL;
            a=(a*a)%10007LL;
            n/=2LL;
        }
        return r;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        long long int a,b,k,n,m,a1[1020];
        a1[0]=1LL;
        scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
        a=Pow(a,n);
        b=Pow(b,m);
        for(int w=1;w<=k;w++)a1[w]=(a1[w-1]%10007LL)*w%10007LL;
        long long int res1=a*b%10007LL,res2=a1[k]*Pow(a1[n]*a1[k-n]%10007LL,10005LL)%10007LL;
        printf("%lld\n",res1*res2%10007LL);

    }
}
