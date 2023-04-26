#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double f[27]; //使用频率
int cmp(const void *a, const void *b) {
    char *aa = (char *)a;
    char *bb = (char *)b;
    int p1,p2;
    if (*aa >= 'a' && *aa <= 'z') p1 = *aa - 'a'; else p1 = *aa - 'A';
    if (*bb >= 'a' && *bb <= 'z') p2 = *bb - 'a'; else p2 = *bb - 'A';

    if (f[p1] == f[p2]) return *bb - *aa;
    else if (f[p1] < f[p2]) return 1;
    else return -1;
}


int main()
{
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; i++) {

        char s[101];
        for (int j = 0; j < 26; j++) {scanf("%lf",&f[j]);}
        scanf("%s",s);
        int len = strlen(s);
        qsort(s, len, sizeof(s[0]), cmp);
        printf("case #%d:\n%s\n",i,s);
    }
    return 0;
}
