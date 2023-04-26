#include<stdio.h>
#include<string.h>
int main(){
   char c1;
   while((c1=getchar())!=EOF){
       recomment(c1);
   }
   return 0;
}
void recomment(char c1){
    char c2;
    if(c1=='/'){
        if((c2=getchar())=='*'){
            in_comment();
           }else if(c2=='/'){
               start_comment();
           }else{
               putchar(c1);
               putchar(c2);
           }
       }else if(c1=='"'||c1=='\''){
           quote(c1);
       }else{
           putchar(c1);
       }
}
void start_comment(){
    char c1,c2;
    while((c1=getchar())!='\n');
    putchar(c1);
}
void in_comment(){
     c1=getchar();
     c2=getchar();
     while(c1!='*'||c2!='/'){
        c1=c2;
        c2=getchar();
    }
}
void quote(char c1){
    char c2;
    putchar(c1);
    while((c2=getchar())!=c1){
        putchar(c2);
        if(c2=='\\'){
            putchar(getchar());
        }
    }
    putchar(c2);
}