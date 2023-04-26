#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct alp
{
    char s[100];
    int num;
    int have;
} alpha;

alpha all[10000];



int cmp(const void* a,const void* b){

    struct alp * p1 = (struct alp*) a;
    struct alp * p2 = (struct alp*) b;
    
    if(p1->have != p2->have)
        return p1->have - p2->have;
    else{
        if((p1->have ==1)&&(p1->num != p2->num))
            return p1->num - p2->num;
        else
            return strcmp(p1 -> s,p2 -> s);
    }

}


int main() {

    for (int q = 0; q < 100; ++q) {
        all[q].have = 0;
    }
    char al[10000000];gets(al);

    int flag1 = 0,flag2 = 0;
    int i = 0;int count = 1;
    for (;al[i]; ++i) {
        if(al[i] == ' '){flag1++;flag2 = 0;count++;}
        else {all[flag1].s[flag2++] = al[i];}
    }
    for (int j = 0; j < count; ++j) {
        char w[10000];
        strcpy(w,all[j].s);
        char * stop;
        for (int l = 0; w[l] != '\0'; ++l) {
            if(isdigit(w[l]) == 0) w[l] = '0';
            else {all[j].have = 1;break;}}
        all[j].num =  strtol(w,&stop,10);
    }
    qsort(all,count,sizeof(struct alp),cmp);
    for (int j = 0; j < i; ++j) {
        printf("%s ",all[j].s);
    }
}
