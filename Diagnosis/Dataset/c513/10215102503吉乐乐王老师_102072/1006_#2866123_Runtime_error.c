#include<stdio.h>
#include<string.h>
#include<math.h>
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
            if(s[i]=='1')ret+=pow(3,wei);
            if(s[i]=='-')ret-=pow(3,wei);
            wei--;
        }
        printf("case #%d:\n%lld%n",idx++,ret);
    }
}