#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct alp
{
    char s[100];
    int num;
} alpha;

alpha all[100];

int cmp(const void* a,const void* b){

    struct alp * p1 = (struct alp*) a;
    struct alp * p2 = (struct alp*) b;

    if((p1->num != 0) && (p2 -> num != 0))
        return p1->num - p2->num;
    else if((p2 -> num == 0) && (p1 -> num == 0))
        return strcmp(p1  -> s,p2 -> s);
    else if(p2 -> num == p1 -> num)
        return strcmp(p1 -> s,p2 -> s);
    else if((p1->num != 0) && (p2 -> num == 0))
        return 1;
    else if((p2->num != 0) && (p1 -> num == 0))
        return -1;

}


int main() {

    char al[100000];gets(al);

    int flag1 = 0,flag2 = 0;
    int i = 0;int count = 1;
    for (;al[i]; ++i) {
        if(al[i] == ' '){flag1++;flag2 = 0;count++;}
        else {all[flag1].s[flag2++] = al[i];}
    }
    for (int j = 0; j < count; ++j) {
        char w[100];
        strcpy(w,all[j].s);
        char * stop;
        for (int l = 0; w[l] != '\0'; ++l) {
            if(isdigit(w[l]) == 0) w[l] = '0';
            else break;}
        all[j].num =  strtol(w,&stop,10);
    }
    qsort(all,count,sizeof(struct alp),cmp);
    for (int j = 0; j < i; ++j) {
        printf("%s ",all[j].s);
    }
}
