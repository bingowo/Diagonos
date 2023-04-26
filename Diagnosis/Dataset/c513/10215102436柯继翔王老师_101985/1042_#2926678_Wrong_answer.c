#include <stdio.h>
#include <stdlib.h>

void print(char* s){
    if(strlen(s) == 0)return;
    for(int i = 0;i < strlen(s);i++){
        for(int j = 0;j <= i;j++){
            printf("%c",s[j]);
        }
        printf("\n");
    }
    print(s + 1);
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
        print(ss);
    }
    return 0;
}
