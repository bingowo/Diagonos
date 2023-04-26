#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* tts(int x){
    char s[15];
    int i=0;
    while(x/10!=0){
        s[i]=x%10;
        i=i+1;
    }
    return s;
}

long long int stt(char* b){
    long long int sum=0;
    for(int j=0;j<strlen(b);j++){
        sum=sum*10+b[j];
    }
    return sum;
}

void become(long long int a){
    char* ss;
    ss=tts(a);
    int len=0;
    for(int i=0;i<strlen(ss);i++){
       if(ss[i]==ss[strlen(ss)-i-1])len=len+1;
       else break;
    }
    if(len==strlen(ss))printf("%s",ss);
    else return become(stt(ss));
    
}
int main(){
    long long int n;
    scanf("%d",&n);
    become(n);
    return 0;
}
