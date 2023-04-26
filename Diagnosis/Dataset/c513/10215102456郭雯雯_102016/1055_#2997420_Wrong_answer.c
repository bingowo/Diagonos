#include<stdio.h>
#include<string.h>

int main(){
    char s[1000001],ans[64];
    scanf("%s",s);
    int num[128],l=strlen(s),i=0,lm=0,ln=0;
    memset(num,0,sizeof(num));
    while(i<l){
        int n=i;
        while(num[s[n]]==0&&n<l){
            num[s[n]]++;
            ln++;
            n++;
        }
        if(ln>lm){
            lm=ln;
            strncpy(ans,s+i,lm);
            ans[lm]='\0';
        }
        memset(num,0,sizeof(num));
        ln=0;
        i=n;
    }
    printf("%s",ans);
}