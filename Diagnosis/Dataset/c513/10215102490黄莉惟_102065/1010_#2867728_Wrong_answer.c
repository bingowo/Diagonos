#include<stdio.h>
#include<string.h>
int main(){
    int s[500];
    int i;
    scanf("%s",s);
    printf("0001");
    int num=strlen(s);
    for(i=9;i>-1;i--) printf("%d",(unsigned)num<<(31-i)>>31);
}
int cal(int a[]){
    
}