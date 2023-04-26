#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[1000100];
    scanf("%s",s);
    int len=strlen(s);
    int  apha[128]={0};//检测重复
    int max=0,begin=0,end=0,mb=0,me=0;
    for(int i=0;i<len;i++){
        if(apha[s[i]]==0){
              apha[s[i]]=1;
              end=i;
              if(end-begin>max){
                max=end-begin;
                mb=begin;me=end;
            }
           }
        else if(apha[s[i]]==1){
            end=i-1;
            if(end-begin>max){
                max=end-begin;
                mb=begin;me=end;
            }
            begin=i;
            for(int j=0;j<128;j++){//重置判断映射表
                apha[j]=0;
            }
            apha[s[begin]]=1;
        }      
    }
    for(int i=mb;i<=me;i++)
    {
        printf("%c",s[i]);
    }
    return 0;
}