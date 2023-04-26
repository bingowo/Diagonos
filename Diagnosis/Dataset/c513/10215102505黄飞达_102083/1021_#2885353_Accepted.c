#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char arr[256] = {0};

int mymin(int a, int b){
    return a < b ? a : b;
}

int cmp(const void*a, const void*b){
    char *x = (char*)a;
    char *y = (char*)b;
    int len = mymin(strlen(x), strlen(y));
    for (int i = 0; i < len; i++){
        if (arr[x[i]] < arr[y[i]]) return -1;
        else if (arr[x[i]] > arr[y[i]]) return 1;
    }
    return strlen(x) > strlen(y) ? 1 : -1;
}

int main(){
    char ch = '0';
    while (ch != EOF){
        char in[110][25] = {0};
        for (int i = 0; i < 26; i++) {
            ch = getchar();
            if (ch == EOF) return 0;
            arr[ch] = i;
            arr[ch + 32] = i;
        }
        getchar();
        int indexi = 0, indexj = 0;
        while ((ch = getchar()) != '\n'){
            if (ch == ' '){
                in[indexi][indexj] = '\0';
                indexi++;
                indexj = 0;
                continue;
            } 
            else if (ch == EOF) return 0;
            in[indexi][indexj++] = ch;
        }
        qsort(in, indexi+1, sizeof(char[25]), cmp);
        printf("%s", in[0]);
        for (int i = 1; i < indexi+1; i++) printf(" %s", in[i]);
        printf("\n");
    }
    return 0;
}
