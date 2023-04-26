#include <stdio.h>

char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int c;
    char s[100];
    int i=0;
    while(a!=0){
        c = a%b;
        if(c>=0){
            s[i]=table[c];
            i++;
            a/=b;
        }else{
             s[i]=table[c-b];
             a=a/b+1;
             i++;}
    }
    for(;i>=0;i--){
        printf("%c",s[i]);
    }
    return 0;
}
