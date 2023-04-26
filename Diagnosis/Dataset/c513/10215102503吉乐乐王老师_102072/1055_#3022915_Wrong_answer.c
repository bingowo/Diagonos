#include<stdio.h>
#include<string.h>
int main(){
    char s[1000001];
    scanf("%s",s);
    int alp[128]={0};
    int aa=0,bb=0;
    int ret=0;
    int a=0,b=0;
    int len=strlen(s);
    while(b<len){
        if(alp[s[b]]){
            if(b-a>ret){
                aa=a;bb=b;
                ret=bb-aa;
            }
            char *p=s+a;
            int t=a+strchr(p,s[b])-p;
            for(int i=a;i<=t;i++){
                alp[s[i]]--;
            }
            a=t;
        }
        alp[s[b]]++;
        b++;
    }
    if(b-a>ret){aa=a;bb=b;}
    for(int i=aa;i<bb;i++){
        putchar(s[i]);
    }
}