#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char *w;
    int len;
}Word;

typedef struct{
    int len;
    int num;
}Num;

void Process(int n){
    Word s[2001]; int len = 0;

    do{
        char temp[n]; scanf("%s", temp);
        int tlen = strlen(temp);
        (s[len].w) = (char *)malloc(sizeof(char) * tlen);
        strcpy(s[len].w, temp); s[len++].len = tlen;
    }while(getchar() != '\n');

    int temp = 0, nlen = 0, tlen = 0;
    Num num[len]; 
    for (int i = 0; i != len; i++) num[i].len = 0, num[i].num = 0;
    for (int i = 0; i != len; i++){
        temp += s[i].len + 1; tlen++;
        if (temp > n + 1){
            num[nlen].num = tlen - 1;
            num[nlen++].len = temp - s[i].len - 1;
            i--;
            temp = 0; tlen = 0;
        }
    }

    int sum = 0; for (int i = 0; i != nlen; i++) sum += num[i].num;
    if (sum < len) num[nlen++].num = len - sum;

    int index = 0;
    for (int i = 0; i != nlen - 1; i++){
        int blank = n - (num[i].len - num[i].num);
        int alblank = num[i].num - 1;
        for (int j = 0; j != num[i].num; j++){
            printf("%s", s[index+j].w);
            if (alblank){
                for (int k = 0;k < blank / alblank; k++)
                    printf(" ");
                blank -= blank / alblank;
                alblank--;
            }
        }
        printf("\n");
        index += num[i].num;
    }
    for (int j = 0; j != num[nlen-1].num; j++)
        printf("%s%c", s[index + j].w, ((index + j) == len - 1? '\n': ' '));
    for (int i = 0; i != len; i++) free(s[i].w);
}

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        int t; scanf("%d", &t); getchar();
        printf("case #%d:\n", i);
        Process(t);
    }
    return 0;
}