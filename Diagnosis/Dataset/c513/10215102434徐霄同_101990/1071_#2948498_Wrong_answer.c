#include <stdio.h>
#include <string.h>
int ss[999][2];
int ss0(int k)
{
    int i,j,f,n;
    memset(ss,0,sizeof(ss));
    n=0;
    for(i=2;i<=k;i++){
        f=0;
        for(j=1;j<=i/2;j++)
            if(i%j==0)
                f++;
        if(f==1){
            ss[n][0]=i;
            n++;
        }
    }
    return n;
}
long long ckn(int k,int n)
{
    int i,i0,j,ns;
    long long x;
    ns=ss0(k);
    for(i=k;i>k-n;i--){
        i0=i;
        while(i0>1)
            for(j=0;j<ns;j++)
                if(i0%ss[j][0]==0){
                    ss[j][1]++;
                    i0=i0/ss[j][0];
                    break;
                }
    }
    for(i=2;i<=n;i++){
        i0=i;
        while(i0>1)
            for(j=0;j<ns;j++)
                if(i0%ss[j][0]==0){
                    ss[j][1]--;
                    i0=i0/ss[j][0];
                    break;
                }
    }
    x=1;
    for(i=0;i<ns;i++)
        for(j=0;j<ss[i][1];j++)
            x=(x*ss[i][0])%10007;
    return x;
}
int main()
{
    int t,a,b,k,n,m,i,j,ns;
    long long x;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        printf("cans #%d:\n",i);
        if(k==0)
            printf("1\n");
        else{
            ns=ss0(k);
            x=ckn(k,n);
            for(j=0;j<n;j++)
                x=(x*a)%10007;
            for(j=0;j<m;j++)
                x=(x*b)%10007;
            printf("%lld\n",x);
            }
    }
    return 0;
}