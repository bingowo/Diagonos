#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *s = (char*)malloc(sizeof(char) * 1000001);
    scanf("%s", s);
    char res[129] = {0}; int rlen = 0;
    int len = strlen(s);

    int table[130]; memset(table, -1, 520);
    char temp[129]; memset(temp, 0, 129); int tlen = 0;
    for (int i = 0; i != len; i++){
        if (table[s[i]] == -1){
            temp[tlen++] = s[i]; 
            table[s[i]]++;
        }
        else if (tlen > rlen){
            strcpy(res, temp);
            rlen = tlen;
            memset(table, -1, 520);
            memset(temp, 0, 129);
            tlen = 0;
        }
    }
    if (tlen > rlen) strcpy(res, temp);
    printf("%s\n", res);
    free(s);
    return 0;
}