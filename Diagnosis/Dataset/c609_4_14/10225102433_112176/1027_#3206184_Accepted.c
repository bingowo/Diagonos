#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char s[20];
    int mark;
}student;

int cmp(const void *a,const void *b)
{
    int ka = (*(student*)a).mark;
    int kb = (*(student*)b).mark;
    char *pa = (*(student*)a).s;
    char *pb = (*(student*)b).s;
    int res = strcmp(pa,pb);
    if(ka != kb)
        return kb-ka;
    else
        return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        int N,M,G;
        scanf("%d %d %d",&N,&M,&G);
        student *ch = malloc(N*sizeof*ch);
        int *bh = malloc(M*sizeof*bh);
        for(int j = 0;j < M;j++){
            scanf("%d",&bh[j]);
        }
        for(int j = 0;j < N;j++){
            ch[j].mark = 0;
            scanf("%s",ch[j].s);
            int S;
            scanf("%d",&S);
            for(int k = 0;k < S;k++){
                int res;
                scanf("%d",&res);
                ch[j].mark += bh[res-1];
            }
        }
        qsort(ch,N,sizeof*ch,cmp);
        int cnt = 0;
        for(int l = 0;l < N;l++){
            if(ch[l].mark >= G)
                cnt++;
            else
                break;
        }
        printf("case #%d:\n%d\n",i,cnt);
        for(int l = 0;l < cnt;l++){
            printf("%s %d\n",ch[l].s,ch[l].mark);
        }
        free(bh);
        free(ch);
    }

    return 0;
}