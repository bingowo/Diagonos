#include<stdio.h>
#include<string.h>

char trans(int a){
    char ans="0000000000";
    for(int i=9;i>0&&a>0;i--){
        y=a%2;
        a/=2;
        if(y==1)ans[i]='1';
        if(y==0)ans[i]='0';
    }
    return ans;
}
int main(){
    char que[500],ans[5000];
    scanf("%s",que);
    
    int len=strlen(que);
    if(len==2){
        int q=(que[0]-'0')*10+(que[1]-'0');
        
    }
}