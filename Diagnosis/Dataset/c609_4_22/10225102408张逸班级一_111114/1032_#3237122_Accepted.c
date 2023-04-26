#include<stdio.h>
#include<string.h>
int main(){
    char s[51];
    scanf("%s",s);
    int len=strlen(s);
    int length=1;int tem=1;
    for(int i=0;i<len-1;i++){
        if(s[i]!=s[i+1]){
            tem++;
            if(tem>length)length=tem;
        }
        else tem=1;
    }
    printf("%d",length);
    return 0;
}