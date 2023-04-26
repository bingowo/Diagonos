#include <stdio.h>
char s[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void f(int a,int b){
    if(a/b>0){
        f(a/b,b);
        putchar(s[a%b]);
    }
    if(a/b==0) {
        putchar(s[a%b]);
    }

}
int main(){
    int n,i,k=0,c,d;
    char s[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&c,&d);
        if(c<0){
            c=-c;
            printf("-");
        }
        f(c,d);
        printf("\n");





    }
    return 0;

}

