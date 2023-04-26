#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[1000100];
    scanf("%s",s);
    int len=strlen(s);
    int max=0,mb=0,me=0;int flag=1;
    while(flag){//双重循环，每个字母都作为begin
    int i=0;
    int  apha[128]={0},begin=i,end=i;//映射表
    for(int j=i;j<len;j++){
       if(apha[s[j]]==0){
          apha[s[j]]=1;
          end=j;
          if(end-begin>max){
            max=end-begin;
            mb=begin;me=end; //最长字串记录,要把me传出来
          }
       }
       else if(apha[s[j]]==1){
        begin=j;end=begin;
        for(int k=0;k<128;k++){
            apha[k]=0;//重置映射表
        }
        apha[s[begin]]=1;
        flag=0;
       }
    }
    i=me;}
    for(int i=mb;i<=me;i++)printf("%c",s[i]);
    return 0;
}