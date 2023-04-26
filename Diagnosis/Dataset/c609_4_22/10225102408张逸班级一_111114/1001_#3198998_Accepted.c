#include<stdio.h>
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int transfer(int a,int b);
int main(){
    int a,b,n;
    scanf("%d",&n);
    while(n--){
    scanf("%d %d",&a,&b);
    if(a<0){
        a=-a;
        printf("-");
    }
    transfer(a,b);
    putchar('\n');
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