#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
   char s[100010];
   scanf("%s",s);
   int len=strlen(s);
   int i=0, ans=0;
   int flag=0,flag1=0;
   //自动机
   int state=0;
   while(i<len){
   switch (state)
   {
   case 0:
        if(s[i]=='0'){
        state=1;}
        i++;  
        break;
        
   case 1:
        if(s[i]=='x'){
            state=2;}
        else if(s[i]=='0'){
            state=1;}
        else state=0;
            i++;
            break;

    case 2:
        if(s[i]>='0'&&s[i]<='9'){
            ans=ans*16+s[i]-'0';
            flag=1;
            if(i==len-1){
                printf("%d ",ans); 
                flag1++;
            }  
        }
        else if(s[i]>='a'&&s[i]<='f'){
            ans=ans*16+10+s[i]-'a';
            flag=1;
            if(i==len-1){
                printf("%d ",ans);
                flag1++; 
            }
        }
        else {
        if(flag)printf("%d ",ans); 
        state=0;
        ans=0;
        flag=0;
        }
        i++;
        break;
   }
   }
    if(!flag1)printf("-1");
    return 0;
}