#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct alp
{
    char s[21];
    int num[21];
} alpha;

int get_in(struct alp * fake,const char* b) {

    int flag1 = 0, flag2 = 0;
    int i = 0;
    int count = 1;
    for (; b[i]; ++i) {
        if (b[i] == ' ') {
            flag1++;
            flag2 = 0;
            count++;
        }
        else { fake[flag1].s[flag2++] = b[i]; }
    }
    return count;
}

char band[26];

void find_num(struct alp fake){
    int flag = 0;
    for (int i = 0;fake.s[i]; ++i) {
        for (int j = 0; j < 26; ++j) {
            if(fake.s[i] >= 97){
                if(fake.s[i] == band[j] + 32)fake.num[flag++] = j;
            }else{
                if(fake.s[i] == band[j])fake.num[flag++] = j;
            }
        }
    }
}

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
    do{
    alpha all[100];char al[10000] = "";
    gets(band);
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
    printf("\n");}while(scanf("%c",g) != '\n');
}

