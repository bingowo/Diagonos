#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int calFac(char*s){
    int table[130] = {0};
    int res = 0;
    for (int i = 0; i != strlen(s); i++)
        if (table[s[i]] == 0) res++, table[s[i]] = 1;
    return res;
}

long long int trans(char *s){
    int table[130]; memset(table, -1, 520);
    int fac = calFac(s);
    long long int res = 0;
    int t = 0;
    for (int i = 0; i != strlen(s); i++){
        if (table[s[i]] == -1){
            int temp = (t == 0? 1: (t == 1? 0: t));
            res = res * fac + temp;
            table[s[i]] = temp;  
            t++;
        }
        else res = res * fac + table[s[i]];
    }
    return res;
}

int cmp(const void *p1, const void *p2){
    char *s1 = *(char**)p1, *s2 = *(char**)p2;
    long long int ll1 = trans(s1), ll2 = trans(s2);
    if (ll1 == ll2) return strcmp(s1, s2);
    return ll1 > ll2? 1: -1;
}
int main(){
    int n; scanf("%d", &n);
    char **s = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i != n; i++){
        char temp[16]; scanf("%s", temp);
        s[i] = (char*)malloc(sizeof(char) * strlen(temp));
        strcpy(s[i], temp);
    }
    qsort(s, n, sizeof(s[0]), cmp);
    for (int i = 0; i != n; i++) printf("%s\n", s[i]);
    for (int i = 0; i != n; i++) free(s[i]);
    free(s);
    return 0;
}