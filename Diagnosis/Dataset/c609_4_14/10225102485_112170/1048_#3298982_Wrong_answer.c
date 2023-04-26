#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,T,n,ans;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&n);
        if(n==0) ans=0;
        else if(n==1||n==2) ans=1;
        else{
            int n1=1,n2=1;
            for(int j=n-2;j>0;j--){
                ans=n1+n2;
                n1=n2;
                n2=ans;
            }
            printf("case #%d:\n%d\n",i,ans);
        }
    }
    return 0;
}
