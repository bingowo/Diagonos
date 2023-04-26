#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multi(int* list,int ans){
    for(int i=99;list[i]!=0;i--){
        list[i]=list[i]*ans;

    }
    for(int i=98;;i--){

        list[i]=list[i+1]/10+list[i];
        list[i+1]=list[i+1]%10;
        if(list[i]==0)break;
    }
}

int main(){
    char s[1000];
    scanf("%s",s);
    int len=strlen(s);
    int sum[100];
    sum[99]=1;
    for(int i=0;i<99;i++){
        sum[i]=0;
    }
    for(int i=0;i<len;i++){
        if(len==1)break;
        if(i==0){
            if(s[i]!=s[i+1])multi(sum,2);
            else continue;
        }
        else if(i==len-1){
            if(s[i]!=s[i-1])multi(sum,2);
            else continue;
        }
        else{
            if(s[i-1]==s[i]&&s[i+1]==s[i])continue;
            else{
                if(s[i-1]!=s[i]&&s[i+1]!=s[i]&&s[i-1]!=s[i+1])multi(sum,3);
                else multi(sum,2);
            }
        }
    }
    int j=0;
    for(;j<100;j++){
        if(sum[i]!=0)break;
    }
    for(;j<100;j++){
    printf("%d",sum[i]);}
    return 0;
}