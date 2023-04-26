#include<stdio.h>
#include<string.h>
typedef struct{
    long long num[130];
    int p;
}bint;
bint init(long long a){
    bint ret={{0},0};
    do{
        ret.num[ret.p++]=a%10;
        a/=10;
    }while(a!=0);
    return ret;
}
bint mul(bint a,bint b,int n){
    bint ret={{0},n};
    for(int i=0;i<a.p && i<n;i++){
        for(int j=0;j<b.p && j<n;j++){
            ret.num[i+j]+=a.num[i]*b.num[j];
        }
    }
    long long carry=0;
    for(int i=0;i<n || carry!=0;i++){
        long long tmp=ret.num[i]+carry;
        ret.num[i]=tmp%10;
        carry=tmp/10;
    }
    while(ret.p>1 && ret.num[ret.p-1]==0)ret.p--;
    return ret;
}
bint pow(bint a,int b,int n){
    bint ret={{1},1};
    if(b==0)return ret;
    else if(b==1)return a;
    else{
        bint t=(pow(a,b/2,n));
        if(b%2==0)
            return mul(t,t,n);
        else
            return mul(mul(t,t,n),a,n);
    }
}
int main(){
    int pro;scanf("%d",&pro);
    for(int index=0;index<pro;index++){
        long long a,b,n;scanf("%lld%lld%lld",&a,&b,&n);
        bint na=init(a);
        bint ans=pow(na,b,n);
        printf("case #%d:\n",index);
        for(int i=n-1;i>=0;i--)printf("%d",ans.num[i]);
        printf("\n");
    }
    return 0;
}
