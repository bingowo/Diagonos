#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char table[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       char s[110];
       int ans[1000];
       for(int i=0;i<1000;i++){
        ans[i]=0;
       }
       scanf("%s",s);
       int len=strlen(s);//三个字符可以完全转化为4个64base，末尾多出的1/2个字符填入=
     printf("case #%d:\n",i);
     int remain=len%3;
     int end=len/3;
     int index=0;
     for(int k=0;k<len;k++){//将原来的字符串全部转化到二进制数组里面
       int j=7,c=s[k];//二进制填入
        while(j>=0){
           ans[index+j]=c%2;
           c/=2;
           j--;
         }
       index+=8;}
     for(int i=0;i<len*8;i++){
      //  printf("ans[%d]=%d\n",i,ans[i]);
     }
    index=0;//打印时的index重置为0
    int sum=0;
    while(index<end*8*3){//打印可完全转化的部分
        sum=0;
        for(int i=index;i<index+6;i++){
             sum=ans[i]+sum*2; 
        }
        printf("%c",table[sum]);
        index+=6;
    }

     if(remain==0)printf("\n");
      
     else if(remain==1){
        sum=0;
        for(int i=index;i<index+6;i++){
        sum=ans[i]+sum*2;
        }
        printf("%c",table[sum]);
        sum=0;
        sum=ans[index+6]*32+ans[index+7]*16;
        printf("%c",table[sum]); 
        printf("==\n");
     }
     else if(remain==2){
        while(index<len*8-4){
          sum=0;
        for(int i=index;i<index+6;i++){
          sum=ans[i]+sum*2;
        }
        printf("%c",table[sum]);
        index+=6;
     } 
     sum=0;
     sum=ans[index]*32+ans[index+1]*16+ans[index+2]*8+ans[index+3]*4;
     printf("%c",table[sum]);
     printf("=\n");
    }
}
return 0;
}