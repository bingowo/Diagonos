#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_n 101
int main(){
  char s[max_n];
  char ans[2*max_n];
  scanf("%s",s);
  int index=0;
  int len=strlen(s);int count=0;
  for(int i=0;i<len;i++){
     count++;
     if(i+1<len&&s[i]!=s[i+1]){
        if(s[i]>s[i+1]){
           for(int j=0;j<count;j++){
              ans[index+j]=s[i];
           }
           index+=count;count=0;
        }
        else if(s[i]<s[i+1]){
            for(int j=0;j<2*count;j++){
              ans[index+j]=s[i];
            }
            index+=2*count; count=0;
        }
     }
     else if(i+1==len){
    for(int j=0;j<count;j++)
    {ans[index+j]=s[i];
     index++;}
     }
  }
  for(int i=0;i<index;i++){
    printf("%c",ans[i]);
  } 
  return 0;
}