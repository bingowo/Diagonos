#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void* a, const void* b){
    return strcmp((char*)a, (char*)b);
}

void func(int i, int lastj, char news[], char res[]){
    if (i >= strlen(news)) return;
    for (int j = lastj+1; j < strlen(news); j++){
        res[i] = news[j];
        for (int k = 0; k < strlen(res); k++) printf("%c", res[k]);
        printf("\n");
        func(i+1, j, news, res);
        res[i+1] = '\0';
    }
    return;
}

int main(){
    int T;
    scanf("%d ", &T);
    for (int t = 0; t < T; t++){
        char s[17] = {0}, res[17] = {0}, news[17] = {0};
        gets(s);
        qsort(s, strlen(s), sizeof(char), cmp);
        news[0]=s[0];
        int index = 1;
        for (int i = 1; i < strlen(s); i++){
            while (s[i]==s[i-1]) {i++;continue;}
            news[index++] = s[i];
        }
        printf("case #%d:\n", t);
        func(0, -1, news, res);        
    }
    return 0;
}