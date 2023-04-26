#include<stdio.h>
int MAX(int a,int b){
    if(a>b)
        return a;
    else return b;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        long long n;
        scanf("%lld",&n);
        int a[32],len=0;
        for(int i=0;n;i++){
            a[i]=n%2;
            n/=2;
            len++;
        }
        int count=1,max=1;
        for(int i=1;i<len;i++){
            if(a[i]!=a[i-1])
                count++;
            else{
                max=MAX(max,count);
                count=1;
            }
        }
        printf("case #%d:\n%d\n",t,MAX(max,count));
    }
    return 0;
}