#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int f[1234];
struct stu{
    int score;
    long long num;
}student[1234];
int n;

int cmp(const void *st1,const void *st2){
    struct stu x=*(struct stu *)st1;
    struct stu y=*(struct stu *)st2;
    if (x.score==y.score) return x.num-y.num;
    else return y.score-x.score;
}

int main(){
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        int n,m,g;
        scanf("%d %d %d",&n,&m,&g);
        for (int i=1;i<=m;i++){
            scanf("%d",&f[i]);
        }
        for (int i=1;i<=n;i++){
            scanf("%lld",&student[i].num);
            int mm;
            scanf("%d",&mm);
            student[i].score=0;
            for (int j=1;j<=mm;j++){
                int x;
                scanf("%d",&x);
                student[i].score+=f[x];
            }
        }
        qsort(student+1,n,sizeof(student[1]),cmp);
        printf("case #%d:\n",l-1);
        if (student[1].score<g){
            printf("0\n");
            continue;
        }
        for (int i=1;i<=n;i++){
            if (student[i].score<g) break;
            printf("%lld %d\n",student[i].num,student[i].score);
        }
    }
    return 0;
}
