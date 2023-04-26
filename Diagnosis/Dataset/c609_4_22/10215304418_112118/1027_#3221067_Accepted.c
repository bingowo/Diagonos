#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int f[1234];
struct stu{
    int score;
    char num[123];
}student[1234];
int n;

int cmp(const void *st1,const void *st2){
    struct stu x=*(struct stu *)st1;
    struct stu y=*(struct stu *)st2;
    if (x.score==y.score) return strcmp(x.num,y.num);
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
            scanf("%s",student[i].num);
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
        int j=0;
        while (student[j+1].score>=g) j++;
        printf("%d\n",j);
        for (int i=1;i<=j;i++){
            if (student[i].score<g) break;
            printf("%s %d\n",student[i].num,student[i].score);
        }
    }
    return 0;
}