#include <stdio.h>
#include <stdlib.h>

void Print(char x,char* s){
    if(strlen(s) == 0){
        printf("%c\n",x);
        return;
    }
    printf("%c\n",x);
    for(int i = 0;i < strlen(s);i++){
        print(x,s + i);
    }
    Print(s[0],s + 1);
}

void print(char x,char* s){
    for(int i = 0;i < strlen(s);i++){
        printf("%c",x);
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
