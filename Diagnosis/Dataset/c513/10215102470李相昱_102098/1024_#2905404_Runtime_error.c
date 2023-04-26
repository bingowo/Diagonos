#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char name[12];
    int S;
    int s[10];
    int sum;
    int pass;
}stu;
int cmp(const void *p1,const void *p2){
    stu *a = (stu*)p1;
    stu *b = (stu*)p2;
    if(a->sum!=b->sum){
        return b->sum - a->sum;
    }else {
        for(int i =0;i<11;i++){
            if(a->name[i]!=b->name[i]){
                return a->name[i]-b->name[i];
            }
        }
    }
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int passnum =0;
        int N,M,G;
        scanf("%d%d%d",&N,&M,&G);
        stu stu1[N];
        int score[M];
        for(int j = 0;j<M;j++){
            scanf("%d",&score[j]);
        }
        for(int student = 0;student<N;student++){
            for(int q = 0; q<11; q++){
                stu1[student].name[q]=getchar();
            }
            scanf("%d",&(stu1[student].S));
            stu1[student].sum =0;
            stu1[student].pass =0;
            for(int p=0;p<stu1[student].S;p++){
                scanf("%d",&stu1[student].s[p]);
                stu1[student].sum += score[(stu1[student].s[p])-1];
                if(stu1[student].sum>=G){
                    stu1[student].pass = 1;
                    passnum++;
                }
            }
        }
        qsort(stu1,N,sizeof(stu1),cmp);
        printf("case #%d:\n%d\n",i,passnum);
        for(int f = 0;((stu1[f].pass>0)&&(f<N));f++){
            for(int e= 0;e<11;e++){
                printf("%c",stu1[f].name[e]);
            }
            printf(" %d\n",stu1[f].sum);
        }
    }
    return 0;
}
