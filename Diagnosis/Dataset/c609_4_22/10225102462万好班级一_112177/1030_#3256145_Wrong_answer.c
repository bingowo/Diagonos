#include<stdio.h>
#include <stdlib.h>

typedef  struct alpha
{
    int c;
    double pri;
}al;

int cmp(const void* a,const void* b){
    al* p1 = (al*)a;
    al* p2 = (al*)b;
    return (int)((p2->pri)*10*10 - (p1->pri)*10*10);
}

char alpha[26] = "abcdefghijklmnopqrstuvwxyz";
char ALPHA[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main() {
    int loop;al alpb[26];
    scanf("%d",&loop);
    for (int i = 0; i < loop; ++i) {
        for (int j = 0; j < 26; ++j) {
            double tmp;scanf("%lf",&tmp);
            alpb[j].c = j;alpb[j].pri = tmp;}getchar();
        char s[100];gets(s);
        qsort(alpb,26,sizeof(al),cmp);
        printf("case #%d:\n",i);
        for (int j = 0; j < 26; ++j) {
            for (int k = 0;s[k] != '\0'; ++k) {
                if(alpha[alpb[j].c] == s[k]||ALPHA[alpb[j].c] == s[k])
                    printf("%c",s[k]);
            }
        }printf("\n");
    }
}