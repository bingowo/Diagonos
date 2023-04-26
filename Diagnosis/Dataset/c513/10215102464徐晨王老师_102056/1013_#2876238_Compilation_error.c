#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char a[30];
    scanf("%s",a);
    int b=strlen(a);
    int i=0;
    int sum1=0;
    int c;
    for(i=0;a[i]!='.';i++){
        if(a[i]=='0')c=0;
        if(a[i]=='1')c=1;
        if(a[i]=='2')c=-1;
        sum1=sum1*3+c;
    }
    int sum2=0;
    int d=(b-i-1)*3;
    for(i=i+1;i<b;i++){
        if(a[i]=='0')c=0;
        if(a[i]=='1')c=1;
        if(a[i]=='2')c=-1;
        sum2=sum2*3+c;
    }
    int B,C=trans(sum2,d);
    
}