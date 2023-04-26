#include <stdio.h>
#include <string.h>
#include <time.h>

const char *table[11] = {"ZERO\0","ONE\0","TWO\0","THREE\0","FOUR\0","FIVE\0","SIX\0","SEVEN\0","EIGHT\0","NINE\0"};
int res[10] = {0}, pro_s[128] = {0};//把s字符个数映射过来

int equal(int pro_s[], const char tab[]){
    int tlen = strlen(tab), flag = 1;
    for (int i=0; i<tlen; i++) {
        pro_s[tab[i]]--;
        if (pro_s[tab[i]] < 0) flag = 0;
    }
    for (int i=0; i<tlen; i++) pro_s[tab[i]]++;
    return flag;
}

int isempty(int pro_s[]){
    for (int i = 65; i < 91; i++){
        if (pro_s[i]>0) return 0;
    }
    return 1;
}

int search(int i, int j){
    if (isempty(pro_s)) return i;
    int flag = 0;
    for (j; j < 10; j++) {
        if (equal(pro_s, table[j])) {
            res[i] = j;
            int tlen = strlen(table[j]);
            for (int k = 0; k < tlen; k++) pro_s[table[j][k]]--;
            flag = search(i+1, j);
            if (flag == 0) for (int k = 0; k < tlen; k++) pro_s[table[j][k]]++;
        }
    }
    return flag;
}

int main(){
    // clock_t begin, end;
    // begin = clock();
    int T;
    scanf("%d ", &T);
    for (int t=0; t<T; t++){
        printf("case #%d:\n", t);
        char s[21] = {0};
        gets(s);
        int slen = strlen(s);
        for (int i=0; i<slen; i++) pro_s[s[i]]++;
        int depth = search(0, 0);
        for (int i = 0; i < depth; i++) printf("%d", res[i]);
        printf("\n");
    }
    // end = clock();
    // printf("time:%lf\n", (double)end - begin);
    return 0;
}