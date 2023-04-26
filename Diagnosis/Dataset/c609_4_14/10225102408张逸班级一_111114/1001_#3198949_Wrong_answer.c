#include<stdio.h>
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int transfer(int a,int b);
int main(){
    int a,b,n;
    scanf("%d",&n);
    while(n--){
    scanf("%d %d",&a,&b);
    transfer(a,b);
    }
    return 0;
}
int transfer(int a,int b){
    if(a/b){
        transfer(a/b,b);
    }
    printf("%c",table[a%b]);
    return 0;
}