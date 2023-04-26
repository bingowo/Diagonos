#include<stdio.h>
int main(){
    int a;
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&a);
     while(a--){
        int b,c;
        scanf("%d %d",&b,&c);
        if (b<0){
            printf("-");
            b=-b;
        }
        int n=b/c+1;
        char s[n];
        int i=0;
        while(b/c){
            s[i]=table[b%c];
            b/=c;
            i++;
        };
        for(int k=i;k>=0;k--){
            printf("%c",s[k]);
        }
        printf("%c\n",table[b]);
        return 0;
     }