#include <stdio.h>
#include <stdlib.h>

typedef struct alp
{
    char s[25];
    int num[25];
} alpha;

char band[26];

int int_cmp(const int *a ,const int* b){
    for (int i = 0;; ++i) {
        if(a[i] == b[i])continue;
        else if(a[i] != 0 && b[i] != 0){
            if(a[i] > b[i])return -1;
            else if(a[i] < b[i])return 1;
        }
        else {
            if(a[i] != 0 && b[i] == 0)return -1;
            else if(a[i] == 0 && b[i] != 0)return 1;
        }
    }
}

int cmp(const void *a,const void *b){
    struct alp * p1 = (struct alp*) a;
    struct alp * p2 = (struct alp*) b;
    return - int_cmp(p1->num,p2->num);
}

char g;
int main() {
    while(gets(band)){
    alpha all[1000];char al[10000] = "";
        gets(al);

        int flag1 = 0, flag2 = 0;
        int i = 0;
        int count = 1;
        for (; al[i]; ++i) {
            if (al[i] == ' ') {
                flag1++;
                flag2 = 0;
                count++;
            }
            else { all[flag1].s[flag2++] = al[i]; }
        }
int numb = count;
    for (int k = 0; k < numb; ++k) {
        int flag = 0;
        for (int z = 0; all[k].s[z]; ++z) {
            for (int j = 0; j < 26; ++j) {
                if (all[k].s[z] >= 97) {
                    if (all[k].s[z] == band[j] + 32)all[k].num[flag++] = j;
                } else {
                    if (all[k].s[z] == band[j])all[k].num[flag++] = j;
                }
            }
        }
    }
    qsort(all, numb, sizeof(struct alp), cmp);

    for (int j = 0; j < numb; ++j) {
        printf("%s ", all[j].s);
    }

        for (int j = 0;all[j].s[0]; ++j) {
            for (int k = 0;all[j].s[k]; ++k) {
                all[j].s[k] = '\0';
            }
        }
    printf("\n");
    }
}




