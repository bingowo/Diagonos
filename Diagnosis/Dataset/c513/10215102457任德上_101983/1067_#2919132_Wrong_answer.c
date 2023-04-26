#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    long long int n[74];
    n[0]=0ll;
    n[1]=1ll;
    n[2]=1ll;
    for(int i=0;i<t;i++){
        int m;
        scanf("%d",&m);
        if(m<3)printf("case #%d:\n%lld",i,n[m]);
        else{
            for(int i=3;i<=m;i++)n[i]=n[i-1]+n[i-2]+n[i-3];
            printf("case #%d:\n%lld",i,n[m]);
        }
    }
    return 0;
}