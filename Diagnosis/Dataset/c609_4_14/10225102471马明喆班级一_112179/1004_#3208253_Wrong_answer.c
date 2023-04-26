#include <stdio.h>

int main(){
    char table[]="0123456789ABCDEF";
    int A,B,a[100];
    char s[100];
    scanf("%d %s %d\n",&A,&s,&B);
    int i=sizeof(s)/sizeof(s[0]);
    i--;
    int n=0,t;
    for(t=0;t<=i;t++){
        if(s[t]>='0'&&s[t]<='9')
            n=A*n+s[t]-'0';
        else if(s[t]>='a')
            n=A*n+s[t]-'a'+10;
        else
            n=A*n+s[t]-'A'+10;
    }
    for(i=0;n>0;i++){
        a[i]=n%B;
        n/=B;
    }
    i--;
    for(;i>=0;i--){
        printf("%c",table[s[i]]);
    }
    return 0;
}