#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int input,base;
    scanf("%d %d",&input,&base);
    char ret[100];int idx=0;
    do{
        char temp=input%base;
        if(temp<0){temp=input-(input/base+1)*base;input=input/base+1;}
        else input/=base;
        if(temp<10)temp+='0';
        else temp=temp-10+'A';
        ret[idx++]=temp;
    }while(input!=0);
    for(int i=idx-1;i>=0;i--){
        printf("%c",ret[i]);
    }
}