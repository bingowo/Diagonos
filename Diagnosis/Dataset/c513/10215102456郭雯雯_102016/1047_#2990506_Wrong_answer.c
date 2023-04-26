#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        char s[510],ans[510];
        scanf("%s",s);
        int num[510];
        memset(num,0,sizeof(num));memset(ans,0,sizeof(ans));
        int l=strlen(s),n=0;
        ans[0]=s[0];num[0]++;
        for(int i=1;i<l;i++){
            if(s[i]==s[i-1]){num[n]++;ans[n]=s[i];}
            else{n++;num[n]++;ans[n]=s[i];}
        }
        printf("case #%d:\n",a);
        for(int i=0;i<n;i++)printf("%d%c",num[i],ans[i]);
        printf("\n");
        a++;
    }
}