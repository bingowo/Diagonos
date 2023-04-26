#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char num[12];
    int score;
}student;

int cmp(const void *a,const void *b)
{
    student x=*(student*)a;
    student y=*(student*)b;
    if(x.score!=y.score)return y.score-x.score;
    else return strcmp(x.num,y.num);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        student a[509];
        int n,m,g;
        scanf("%d%d%d",&n,&m,&g);
        int x[11];
        for(int j=1;j<=m;j++){
            scanf("%d",&x[j]);
        }
        for(int j=0;j<n;j++){
            scanf("%s",a[j].num);
            a[j].score=0;
            int temp;
            scanf("%d",&temp);
            for(int k=0;k<temp;k++){
                int o;
                scanf("%d",&o);
                a[j].score+=x[o];
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        int cnt=0;
        for(int j=0;j<n;j++){
            if(a[j].score>=g)cnt++;
            else break;
        }
        printf("%d\n",cnt);
        for(int j=0;j<cnt;j++){
            printf("%s %d\n",a[j].num,a[j].score);
        }
    }
    return 0;
}
