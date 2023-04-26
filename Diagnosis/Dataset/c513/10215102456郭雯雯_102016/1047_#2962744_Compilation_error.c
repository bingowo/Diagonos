#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int t,a=0;
    scamf("%d",&t);
    while(a<t){
        char s[510],ans[510]
        printf("case #%d:\n",a);
        gets(s);
        int l=strlen(s),n=0;
        for(int i=0;i<l-1;i++){
            if(s[i]==s[i+1])n++;
            else{
                char ans[4];
                itoa(n+1,ans,10);
                printf("%s%c",ans,s[i]);
                n=0;
            }
        }
        printf("\n");
        a++;
    }
}