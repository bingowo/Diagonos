#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[1000100];
    scanf("%s",s);
    int len=strlen(s),mb=0,me=0;int index=0;
    if(len==1){printf("%s",s);return 0;}
    int max=0,length=0,flag=0,i=0;//max最长串的长度，length当前串的长度，now当前下标位置
    while(!flag){//还要记录最长字符串的头和尾mb，me
    int apha[128]={0};
    for(int now=i;now<len;now++){
        if (now==len-1)flag=1;
        if(apha[s[now]]==0){
            apha[s[now]]=now+1;
            length++;
            if(length>max){max=length;mb=i;me=now;}
        }
        else {index=now;break;}
    }
    i=apha[s[index]];length=0;}  
    for(int i=mb;i<=me;i++)printf("%c",s[i]);
    return 0;
}