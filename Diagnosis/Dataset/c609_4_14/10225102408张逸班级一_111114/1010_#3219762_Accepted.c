
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
char table[]="0123456789ABCDEFGHIJ";
int trans(int a,int b){

    int c=a/b;//a>0时，商和余数会正负交替
    int d=a%b;
    if(!c&&d>0){//c=0时，可能余数为负数，此时不应结束程序
        printf("%c",table[abs(a)]);
        return 0;
    }
   if(d<0){//保证余数为正
    c++;
    d-=b;
   }
    trans(c,b);
    printf("%c",table[abs(d)]);

}

int main(){
   int a,b;
   scanf("%d %d",&a,&b);
   if(a==0){
    printf("0");//特判
   }
   else trans(a,b);
   return 0;

}
