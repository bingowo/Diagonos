#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double table[26];
int cmp(const void *a, const void *b){
    char A = *(char*)a, B = *(char*)b;
    return fabs(table[A-'A']-table[B-'A'])>1e-10;
}
int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        memset(table,0,26*sizeof(double));
        for(int j = 0;j<26;j++){
            scanf("%lf",&table[j]);
        }
        char s[110];memset(s,0,110*sizeof(char));
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}
