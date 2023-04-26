#include <stdio.h>

int main(){
    char table[]="0123456789ABCDEF";
    int A,B,b[100];
    char s[100];
    int a[128];
    for(int i=0;i<128;i++) a[i]=-1;
    for(int i='a',b=10;i<'z';i++,b++) a[i]=b;
    for(int i='A',b=10;i<'Z';i++,b++) a[i]=b;
    for(int i='0',b=0;i<'9';i++,b++) a[i]=b;
    scanf("%d %s %d\n",&A,&s,&B);
    int n=0,t;
    char *p=s;
    while(*p){
        n=n*A+a[*p++];
    }
    if(n!=0){
    for(t=0;n>0;t++){
        b[t]=n%B;
        n/=B;
    }
    t--;
    for(;t>=0;t--)
        printf("%c",table[b[t]]);
    }
    else printf("0");
    return 0;
}