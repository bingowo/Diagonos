#include <stdio.h>
#include <string.h>
#include<ctype.h>
char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
    int n,r,k;
    char a[10000];
    scanf("%d %s %d",&n,a,&r);
    int t,numb = 0;
    for(int j = 0;j < strlen(a);j++){
        if(a[j] > '9')
            t = toupper(a[j]) - 'A' + 10;
        else
            t = a[j] - '0';
        numb = n*numb + t;
    }
       char answer[10000];
    for(k = 0;numb;k++){
        answer[k] = table[numb%r];
        numb /= r;
    }
    for(int i = strlen(answer) - 1;i>=0;i--){
        printf("%c",answer[i]);
    }
return 0;
}
