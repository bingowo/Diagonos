#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    return strcmp((char*)a,(char*)b);
}

int main(){
    int T;
    scanf("%d ", &T);
    for (int t = 0; t < T; t++){
        char s[501];
        gets(s);
        char words[501][501];
        memset(words, 0, 501*501);
        int p=0, q=0;
        for (int i = 0; i < strlen(s); i++){
            if (s[i]==','||s[i]=='.'||s[i]=='!'||s[i]=='?'||s[i]==' ') {
                words[p][q]='\0';p++;q=0;continue;
            }
            words[p][q++] = s[i];
        }
        qsort(words, p, sizeof(char[501]), cmp);
        int i;
        for (i = 0; words[i+1][0] != '\0'; i++) {
            if (strcmp(words[i], words[i+1]) == 0) {
                puts(words[i]);
                while (strcmp(words[i], words[i+1]) == 0) i++;
            }
            else puts(words[i]);
        }
        if (i == 0) puts(words[i]);
        else if (strcmp(words[p-1], words[p]) != 0) puts(words[p]);
        

    }
    
    return 0;
}