#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Print(char x,char* s){
    if(strlen(s) == 0){
        printf("%c\n",x);
        return;
    }
    printf("%c\n",x);
    for(int i = 0;i < strlen(s);i++){
        print1(x,s + i);
    }
    Print(s[0],s + 1);
}

void print1(char x,char* s){
    char ss[16];
    ss[0] = x;
    ss[1] = 0;
    print2(ss,s);
    for(int i = 0;i < (int)strlen(s) - 3;i++){
        ss[i + 1] = s[i];
    }
    for(int i = strlen(s) - 2;i > 1;i--){
        ss[i] = 0;
        for(int j = i;j < strlen(s);j++)
            print2(ss,s + j);
    }
}

void print2(char* x,char* s){
    for(int i = 0;i < strlen(s);i++){
        printf("%s",x);
        for(int j = 0;j <= i;j++){
            printf("%c",s[j]);
        }
        printf("\n");
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    char s[16];
    for(int i = 0;i < T;i++){
        scanf("%s",s);
        int a[128] = {0};
        for(int j = 0;j < strlen(s);j++){
            a[s[j]]++;
        }
        char ss[16];
        memset(ss,0,sizeof(ss));
        int index = 0;
        for(int j = 0;j < 128;j++){
            if(a[j])ss[index++] = j;
        }
        ss[index] = 0;
        printf("case #%d:\n",i);
        Print(ss[0],ss + 1);
    }
    return 0;
}

