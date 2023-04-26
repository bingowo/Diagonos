#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char num[13];
    int score;
}Stu;

int cmp(const void* m, const void* n) {
    Stu *a = (Stu*)m, *b=(Stu*)n;
    if(a->score != b->score)
        return b->score - a->score;
    else
        return strcmp(a->num,b->num);
}

int main()
{
    int T;
    scanf("%d",&T);
    int N,M,G;
    for(int t=0; t<T; ++t) {
        scanf("%d %d %d",&N,&M,&G);
        int a[11] = {0};
        for(int i=1; i<=M; ++i) scanf("%d",&a[i]);
        Stu s[500];

        for(int i=0; i<N; ++i) {
            s[i].score = 0;
            scanf("%s",s[i].num);
            int S; scanf("%d",&S);
            for(int j=0; j<S; ++j){
                int k; scanf("%d",&k);
                s[i].score += a[k];
            }
        }
        qsort(s,N,sizeof(Stu),cmp);
        int cnt = 0;
        while(s[cnt].score >= G) ++cnt;
        printf("case #%d:\n%d\n",t,cnt);
        for(int i=0; i<cnt; ++i)
            printf("%s %d\n",s[i].num,s[i].score);
    }
    return 0;
}
