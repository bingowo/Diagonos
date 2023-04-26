#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *duplicate(char *s){
    int slen = strlen(s);
    char* temp = (char *)malloc(sizeof(char) * slen);
    int len = 0;
    if (s[0] != s[1]) temp[len++] = s[0];
    for (int i = 1; i != slen - 1; i++)
        if (s[i] != s[i+1]) temp[len++] = s[i];
    temp[len++] = s[slen-1];
    temp[len] = 0;
    return temp;
}

int cmp(const void *p1, const void* p2){
    return *(int*)p1 - *(int *)p2;
}

long long int calMin(int *arrl, int len){
    int mid = len / 2;
    int meven = mid;
    if (!(mid%2)) meven--;
    int m = arrl[mid], me = arrl[meven];
    long long int res = 0, rese = 0;
    for (int i = 0; i != mid; i++)
        res += m - arrl[i];
    for (int i = mid + 1; i != len; i++)
        res += arrl[i] - m;

    for (int i = 0; i != meven; i++)
        rese += me - arrl[i];
    for (int i = meven+1; i !=len; i++)
        rese += arrl[i] - me;
    return res > rese? rese: res;
}

int main(){
    int n; scanf("%d", &n);
    char **p = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i != n; i++){
        char temp[101]; scanf("%s", temp);
        p[i] = (char *)malloc(sizeof(char) * strlen(temp));
        strcpy(p[i], temp);
    }
    for (int i = 0; i != n - 1; i++){
        char *t1 = duplicate(p[i]), *t2 = duplicate(p[i+1]);
        if (strcmp(t1, t2)){
            free(t1), free(t2);
            printf("-1\n"); return 0; 
        } 
        free(t1), free(t2);
    }


    char *gab = duplicate(p[0]);
    int len = strlen(gab);
    int *arrl = (int*)malloc(sizeof(int) * n);
    int *location = (int*)malloc(sizeof(int) * n);

    memset(arrl, 0, 4 * n);
    memset(location, 0, 4 * n);
    long long int res = 0;

    for (int i = 0; i != len; i++){
        for (int j = 0; j != n; j++){
            int tlen = strlen(p[j]);
            for (; location[j] < tlen; location[j]++){
                if (p[j][location[j]] == gab[i]) arrl[j]++;
                else break;
            }
        }
        qsort(arrl, n, sizeof(int), cmp);
        res += calMin(arrl, n);
        memset(arrl, 0, 4*n);
    }
    free(gab), free(arrl), free(location);
    for (int i = 0; i != n; i++) free(p[i]);
    free(p);
    printf("%lld\n", res);
    return 0;
}