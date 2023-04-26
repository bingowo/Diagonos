#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void add(char s[], int i, char new_s[]){
    strcpy(new_s, s);
    for (int j = strlen(s); j-1 > i; j--) {
        new_s[j] = new_s[j-1];
    }
    new_s[i+1] = new_s[i];
    return;
}

int check(char s[]){
    for (int i = 0; i+1 < strlen(s); i++){
        if (s[i]==s[i+1]) return 1;
    }
    return 0;
}

int mydelete(char s[]){
    int slen = strlen(s);
    int flag = 0;
    for (int i = 0; i < slen; i++){
        flag = 0;
        for (int j = 1; i+j<slen; j++){
            if (s[i]==s[i+j]) {
                flag = 1;
                s[i+j]='D';
                if (i+j==slen-1) s[i] = 'D';
            }
            else {
                if (flag == 1) s[i] = 'D';
                i += j-1;
                flag = 2;
                break;
            }
        }
    }
    int index = 0;
    for (int i = 0; i < slen; i++){
        if (s[i] != 'D'){
            s[index++] = s[i];
        }
    }
    s[index] = '\0';
    return slen - index;
}

int main(){
    int T;
    scanf("%d ", &T);
    for (int t = 0; t < T; t++){
        printf("case #%d:\n", t);
        char s[105] = {0};
        gets(s);
        int slen = strlen(s);
        int res = 0;
        for (int i = 0; i < slen; i++){
            int count = 0;
            char new_s[105] = {0};
            add(s, i, new_s);
            while (check(new_s)){
                count += mydelete(new_s);
            }
            if (res < count) res = count;
        }
        printf("%d\n", res);
    }
    return 0;
}

