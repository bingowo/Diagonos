#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* duplicate(const char *s){
    int len = strlen(s);
    char *b = (char *)malloc(sizeof(char) * 101); int blen = 0;
    if (s[0] != s[1]) b[blen++] = s[0];
    for (int i = 1; i < len - 1; i++){
        if (s[i] == s[i+1]) continue;
        else if (s[i] == s[i - 1]) continue;
        else b[blen++] = s[i];
    }
    if (s[len - 2] != s[len - 1]) b[blen++] = s[len - 1];
    b[blen] = 0;
    int jud = 0;
    for (int i = 0; i < blen - 1; i++){
        if (b[i] == b[i + 1]){
            jud = 1;
            break;
        }
    }
    if (jud){
        char temp[101]; strcpy(temp, b);
        free(b); return duplicate(temp);
    }
    else return b;
}

void Insert(char *s, char alp, int idx){
    int len = strlen(s);
    s[len+1] = 0;
    for (int i = len; i != idx; i--)
        s[i] = s[i-1];
    s[idx] = alp;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; i++){
        char s[101]; scanf("%s", s);
        int len = strlen(s);
        int removal = 0;
        for (int j = 0; j < len; j++){
            char s1[102]; strcpy(s1, s);
            Insert(s1, 'A', j);
            char *a1 = duplicate(s1);
            int disa = strlen(s1) - strlen(a1); 
            if (disa > removal) removal = disa;
            free(a1);

            char s2[102]; strcpy(s2, s);
            Insert(s2, 'B', j);
            char *a2 = duplicate(s2);
            disa = strlen(s2) - strlen(a2); 
            if (disa > removal) removal = disa;
            free(a2);

            char s3[102]; strcpy(s3, s);
            Insert(s3, 'C', j);
            char *a3 = duplicate(s3);
            disa = strlen(s3) - strlen(a3); 
            if (disa > removal) removal = disa;
            free(a3);
        }
        printf("case #%d:\n", i);
        printf("%d\n", removal);
    }
    return 0;
}