#include<stdio.h>

int main(){
    int T,n,r,sum=0,len=0;
    char digit[16]="0123456789ABCDEF",ans[100];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d%d",&n,&r);
        while(n){
            sum+=n%r;
            n/=r;
        }
        while(sum){
            sum/=r;
            len+=1;
        }
        while(sum){
            ans[--len]=sum%r;
        }
        printf("case #%d\n",i);
        for(int j=0;j<len;j++){
            printf("%s",ans[j]);
        }
    }
    return 0;
}