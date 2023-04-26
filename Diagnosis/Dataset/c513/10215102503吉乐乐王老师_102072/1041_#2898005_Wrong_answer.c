#include<stdio.h>
#include<string.h>
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    char s[51];
    gets(s);
    int n=strlen(s);
    int ret=1;int maxl=1;
    for(int i=1;i<n;i++){
        char pre=s[i-1],now=s[i];
        if(now!=pre)maxl++;
        else {
            ret=max(ret,maxl);
            maxl=1;}
    }
    printf("%d",ret);
}