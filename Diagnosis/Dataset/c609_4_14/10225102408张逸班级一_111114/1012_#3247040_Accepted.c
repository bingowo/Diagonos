#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
   int a;
   scanf("%d",&a);
   for(int i=0;i<a;i++)
{
    char s[55];//八进制的字符串
    char num[160];//结果的字符串
    scanf("%s",s);
    int time=0;//time is to mark the number of the answer
    int temp;
    int len=strlen(s)-1;
    for(;len>1;len--){
        int digit=s[len]-'0';//最后数位的取出
        int now=0;
        while(digit!=0||now<time){
           if(now<time){
            temp=digit*10+num[now]-'0';
           }
           else temp=digit*10;
           num[now++]=temp/8+'0';//更新商
           digit=temp%8;
        }
        time=now;
    }
    num[time]='\0';
    printf("case #%d:\n",i);
    printf("0.%s\n",num);
}
return 0;
}