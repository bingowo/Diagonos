#include<stdio.h>
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int t;
    scanf("%d",&t);
    int idx=0;
    while(t--){
        int n;
        scanf("%d",&n);
        char s[64];
        int cnt=0;
        do{
            s[cnt++]=n%2;
            n/=2;
        }while(n!=0);
        int pre=s[cnt-1],cur;
        int ret,maxl;
        ret=maxl=1;
        for(int i=cnt-2;i>=0;i--){
            cur=s[i];
            if(cur!=pre){
                maxl++;
                pre=cur;
            }
            else{
                ret=max(maxl,ret);
                pre=cur;
                maxl=1;
            }
        }
        ret=max(maxl,ret);
        printf("case #%d:\n%d\n",idx++,ret);
    }
}