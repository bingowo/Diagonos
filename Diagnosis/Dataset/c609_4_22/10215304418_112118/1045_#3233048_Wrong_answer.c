#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st[7654321];

int main(){
    int len=0;
    int f=0;
    while ((st[len++]=getchar())!=EOF);
    for (int i=0;i<len;i++){
        if (st[i]=='\'')
            if (f==1) f=0;
            else f=1;
        if (st[i]=='"')
            if (f==2) f=0;
            else f=2;
        if (f==1 || f==2) {
            printf("%c",st[i]);
            continue;
        }
        if (st[i]=='/' && st[i+1]=='/' && i<len){
            while (st[i]!='\n') i++;
        }
        if (st[i]=='/' && st[i+1]=='*'){
            while (!(st[i]=='*' && st[i+1]=='/') && i<len) i++;
            i+=2;
        }
        if (i<len) printf("%c",st[i]);
    }
    return 0;
}
