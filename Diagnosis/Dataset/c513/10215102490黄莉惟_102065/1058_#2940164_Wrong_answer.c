#include<stdio.h>
#include<string.h>
int main(){
   char c1,c2;
   while((c1=getchar())!=EOF){
       if(c1=='/'){
           if((c2=getchar())=='*'){
               c1=getchar();
               c2=getchar();
               while(c1!='*'||c2!='/'){
                   c1=c2;
                   c2=getchar();
               }
           }else if(c2=='/'){
               while((c1=getchar())!='\n'){
                   putchar(c1);
               }
               putchar(c1);
           }else{
               putchar(c1);
               putchar(c2);
           }
       }else if(c1=='"'||c1=='\''){
           putchar(c1);
           while((c2=getchar())!=c1){
               putchar(c2);
           }
           putchar(c2);
       }else{
           putchar(c1);
       }
   }
   
}
