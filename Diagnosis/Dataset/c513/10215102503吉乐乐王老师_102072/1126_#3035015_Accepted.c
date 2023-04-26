#include<stdio.h>
#include<stdlib.h>
#define N 64
typedef unsigned long long int ull;
typedef struct{
    int a[N];
    ull num;
}node;
int main(){
    int n;
    scanf("%d",&n);
    node d[10000];
    for(int i=0;i<n;i++){
        scanf("%llu",&d[i].num);
        ull t=d[i].num;
        for(int k=N-1;k>=0;k--){
            d[i].a[k]=t&1;
            t>>=1;
        }
    }
    int flag=1;
    for(int i=N-1;i>=0;i--){
        int t=0;
        for(int k=0;k<n;k++){
            t^=d[k].a[i];
        }
        if(t){
            flag=0;break;
        }
    }
    if(flag==1){
        ull ret[20]={0};
        ull min=0xFFFFFFFFFFFFFFFF;
        for(int i=0;i<n;i++){
            if(d[i].num<min)min=d[i].num;
        }
        int add=0;
        for(int i=0;i<n;i++){
            if(d[i].num==min){
                if(add==0){
                    add=1;continue;
                }
            }
            ret[19]+=d[i].num;
            for(int k=19;k>0;k--){
                ret[k-1]+=ret[k]/10;
                ret[k]%=10;
            }
        }
        for(int i=0;i<20;i++){
            if(ret[i]!=0){
                while(i<20)printf("%d",ret[i++]);
            }
        }
    }
    else{
        printf("-1");
    }
}