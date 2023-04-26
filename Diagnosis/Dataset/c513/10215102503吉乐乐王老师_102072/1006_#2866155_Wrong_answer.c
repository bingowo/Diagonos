#include<stdio.h>
#include<string.h>
#include<math.h>
long long int get(int wei){
    long long int ret=1;
    for(int i=0;i<wei;i++){
        ret*=3;
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    int idx=0;
    while(t--){
        char s[1000];
        scanf("%s",s);
        int n=strlen(s);
        long long int ret=0;
        int wei=n-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1')ret+=get(wei);
            if(s[i]=='-')ret-=get(wei);
            wei--;
        }
        printf("case #%d:\n%lld%n",idx++,ret);
    }
}