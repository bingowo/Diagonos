#include<stdio.h>
#include<string.h>
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    char s[51];
    gets(s);
    int n=strlen(s);
    int ret=0;int maxl=0;
    for(int i=1;i+1<n;i++){
        char pre=s[i-1],now=s[i],next=s[i+1];
        if(now!=pre&&now!=next)maxl++;
        else {
            ret=max(ret,maxl);
            maxl=0;}
    }
    ret=ret==0?1:ret+2;
    printf("%d",ret);
}