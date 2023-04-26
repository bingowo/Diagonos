#include <stdio.h>
#include <stdlib.h>

#define maxstr 501

void binary10(int n){
    int res[10];
    for(int i=0;i<10;i++)res[i]=0;
    int d=9;
    while(n){
        res[d--]=n%2;
        n/=2;
    }
    for(int i=0;i<10;i++)printf("%d",res[i]);
}
void binary7(int n){
    int res[7];
    for(int i=0;i<7;i++)res[i]=0;
    int d=6;
    while(n){
        res[d--]=n%2;
        n/=2;
    }
    for(int i=0;i<7;i++)printf("%d",res[i]);
}
void binary4(int n){
    int res[4];
    for(int i=0;i<4;i++)res[i]=0;
    int d=3;
    while(n){
        res[d--]=n%2;
        n/=2;
    }
    for(int i=0;i<4;i++)printf("%d",res[i]);
}

int main(){
    char n[maxstr];
    scanf("%s",n);
    int i;
    for(i=0;n[i]!='\0';i++);
    printf("0001");
    binary10(i);
    int num=0;
    for(i=0;n[i]!='\0';i++){
        num=num*10+n[i]-'0';
        if(!((i+1)%3)){
            binary10(num);
            num=0;
        }
    }
    if(i%3==1){
        num=n[i-1]-'0';
        binary4(num);
    }
    if(i%3==2){
        num=(n[i-2]-'0')*10+n[i-1]-'0';
        binary7(num);
    }
    printf("\n");
    return 0;
}


