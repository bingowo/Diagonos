#include<stdio.h>
#include <string.h>
#define N 155
#define L 55
void fuc(char* a,char *b){
int carry=0;
int t;
int len=strlen(a)-1;
for(;len!=1;--len){
    int digit=a[len]-'0';
    int j=0;
    do{ if(j<carry){
       t=digit*10+b[j]-'0';
       }
       else
        t=digit*10;
        b[j++]=t/8+'0';
        digit=t%8;
        }while(digit!=0||j<carry);
    carry= j;
}
b[carry]='\0';

}
int main(){
int T;
scanf("%d",&T);
for(int i=0;i<T;i++){
    char a[L];
    char b[N];
    scanf("%s",a);
    printf("case #%d:\n",i);
    fuc(a,b);
    printf("0.");
    printf("%s",b);
    printf("\n");
}
}
