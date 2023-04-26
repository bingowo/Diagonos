#include<stdio.h>
#include<string.h>

int main(){
    char s[1000001],ans[64];
    scanf("%s",s);
    int num[128],l=strlen(s),i=0,lm=0,ln=0;
    memset(num,0,sizeof(num));
    while(i<l){
        int n=i;
        while(num[s[n]]==0){
            num[s[n]]++;
            ln++;
            n++;
        }
        if(ln>lm){lm=ln;strncpy(ans,s+i,lm);}
        memset(num,0,sizeof(num));
        i=n;
    }
    printf("%s",ans);
}