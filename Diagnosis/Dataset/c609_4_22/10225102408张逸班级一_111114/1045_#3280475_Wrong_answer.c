#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char c;
    int state=0;int flag=0;
    c=getchar();
    while(c!=EOF){
      switch(state){
      case 0:
          if(c=='/')state=1;
          else if(c=='\''){state=5;putchar(c);}
          else if(c=='\"'){state=7;putchar(c);}
          else putchar(c);
          break;

      case 1:
         if(c=='*')state=2;//进入块注释部分
         else if(c=='/')state=3;
         else {state=0;
               putchar('/');
               putchar(c);}
         break;

      case 2:
          if(c=='*')state=4;//打算退出注释部分
          break;

      case 3:
        if(c=='\n'){state=0;putchar(c);}//单行注释的换行符照旧输出
        break;

      case 4:
        if(c=='*')state=4;
        else if(c=='/')state=0;//确实退出注释部分
        else if(c=='\n'&&flag==0){putchar(c);state=2;flag=1;}//块注释中的换行符只保留1个
        else state=2;//重回状态2
        break;

      case 5:

          if(c=='\\'){state=6;putchar(c);}
          else if(c=='\''){state=0;putchar(c);}
          else putchar(c);
          break;

      case 6:
          state=5;//避免出现转义时的误触
          putchar(c);
          break;

      case 7:
          if(c=='\\'){state=8;putchar(c);}
          else if(c=='\"'){state=0;putchar(c);}
          else putchar(c);
          break;

      case 8:
          state=7;//避免出现转义时的误触
          putchar(c);
          break;
      }
      c=getchar();
      flag=0;
     }
   return 0;
    
}