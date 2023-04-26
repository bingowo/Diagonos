#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void divide(int s0[1100],int d){
   for(int i=0;i<strlen(s0)-1;i++){
       s0[i]=(s0[i]-48)/2+48;
       s0[i+1]=s0[i+1]+(s0[i]-48)%2;
   }
   s0[strlen(s0)-1]=(s0[strlen(s0)-1]-48)/2+48;
}

void tentotwo(int s0[1100],s1[1100],int len){
    if((s0[strlen(s0)-1]-48)%2==1)s1[len]='1';
    else s1[len]='0';
    divide(s0,2);
    int flag=0;
    for(int i=0;i<strlen(s0);i++){
        if(s0[i]!='0'){
            flag=1;
            break;
        }
    }
    if(flag)tentotwo(s0,s1,len+1);
    else return;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s0[1100];
        scanf("%s",s0);
        char s1[1100];
        tentotwo(s0,s1,0);
        printf("case #%d:\n",t);
    }
}