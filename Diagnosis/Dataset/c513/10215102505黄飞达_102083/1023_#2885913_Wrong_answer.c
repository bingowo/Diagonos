#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s[100][31];

int getnum(char cc[]){
    int len = strlen(cc);
    int res = 0;
    int flag = 0;
    for (int i = 0; i < len; i++){
        if ('0' <= cc[i] && cc[i] <= '9'){
            flag = 1;
            res *= 10;
            res += cc[i] - '0';
        }
    }
    if (flag) return res;
    else return -1;
}

int cmp(const void *a, const void *b){
    char *x = (char*)a;
    char *y = (char*)b;
    int resx = getnum(x), resy = getnum(y);
    if (resx != -1 || resy != -1) return getnum(x) - getnum(y);
    else return strcmp(x, y);
}

int main(){
    char ctemp[31];
    int index = 0;
    while (scanf("%s", &ctemp) != EOF){
        strcpy(s[index++], ctemp);
    }
    qsort(s, index, sizeof(char[31]), cmp);
    for (int i = 0; i < index; i++) printf("%s ", s[i]);
    printf("\n");
    return 0;
}