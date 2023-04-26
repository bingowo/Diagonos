#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st[7654321];

int main(){
    int len=0;
    while ((st[len++]=getchar())!=EOF);
    for (int i=0;i<len;i++){
        if (st[i]=='/' && st[i+1]=='/' && i<len){
            while (st[i]!='\n') i++;
        }
        if (st[i]=='/' && st[i+1]=='*'){
            while (!(st[i]=='*' && st[i+1]=='/') && i<len) i++;
        }
        if (i<len) printf("%c",st[i]);
    }
    return 0;
}
