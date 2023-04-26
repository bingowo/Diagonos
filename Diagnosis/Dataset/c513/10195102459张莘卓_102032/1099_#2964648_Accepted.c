#include <stdio.h>
#include <string.h>
char num[10][6] = {"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
char alpha[26][6] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

void find(char* s) {
    if(strlen(s) == 5) {
        for(int i=0; i<10; ++i)
            if(strcmp(s, num[i]) == 0){
                printf("%d",i);
                return;
            }
    }else {
        for(int i=0; i<26; ++i)
            if(strcmp(s, alpha[i]) == 0) {
                printf("%c",'A'+i);
                return;
            }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        char code[1001];
        scanf("%s",code);
        int i = 0;
        printf("case #%d:\n",j);
        while(code[i]) {
            char s[6];
            int index = 0, cnt = 0;
            while(code[i] && code[i]!='/')
                s[index++] = code[i++];
            s[index] = '\0';
            find(s);
            while(code[i] && code[i]=='/') {
                ++i;  ++cnt;
            }
            if(cnt == 5) printf(".");
            else if(cnt % 3 == 0) {
                for(int k=0; k<cnt/3; ++k) printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
