#include<stdio.h>
int main(){
    int a;
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&a);
     while(a--){
        int b,c,n=0;
        int cb=b;
        scanf("%d %d",&b,&c);
        if (b<0){
            printf("-");
            b=-b;
        }
        while(cb/b){
            n+=1;
            cb/=b;
        }
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
        
     }
    return 0;
}