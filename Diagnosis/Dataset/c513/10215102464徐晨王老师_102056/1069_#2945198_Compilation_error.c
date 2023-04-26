#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int stt(char* b){
    long long int sum=0;
    for(int j=0;j<strlen(b);j++){
        sum=sum*10+b[j];
    }
    return sum;
}

void become(long long int a){
    char s[15];
    int i=0;
    while(x%10!=0){
        s[i]=x%10;
        i=i+1;
        x=x/10;
    }
    int len=0;
    for(int i=0;i<strlen(s);i++){
       if(ss[i]==ss[strlen(s)-i-1])len=len+1;
       else break;
    }
    if(len==strlen(ss))printf("%s",s);
    else return become(atoi(s)+a);
    
}
int main(){
    long long int n;
    scanf("%d",&n);
    become(n);
    return 0;
}