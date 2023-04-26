#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct STU {
    char number[12];//学号
    long long grade;
}stu1[500], stu2[500];

int cmp(const void *a, const void *b) {
    struct STU *aa = (struct STU *)a;
    struct STU *bb = (struct STU *)b;
    //printf("----%s %lld ----%s %lld\n", aa->number,aa->grade,bb->number,bb->grade);
    if (aa->grade != bb->grade) return bb->grade - aa->grade;
    else return strcmp(aa->number, bb->number);
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; i++) {
        int n,m,g;//学生人数，考试题目数,分数线
        scanf("%d %d %d",&n,&m,&g);
        long long a[m+1]; //M题的分值
        for (int j = 0; j < m; j++) {
            scanf("%lld", &a[j]);
        }
        for (int j = 0; j < n; j++) {
            int S;//学生解出的题目总数
            scanf("%s %d",stu1[j].number, &S);
            stu1[j].grade = 0;
            for (int k = 0; k < S; k++) {
                int tmp; //答对的题号
                scanf("%d", &tmp);
                stu1[j].grade += a[tmp - 1];
            }
        }

        int cnt = 0;
        for (int j = 0; j < n; j++) {

            if (stu1[j].grade >= g) {
                stu2[cnt] = stu1[j];
                cnt++;

            }
        }
        qsort(stu2, cnt, sizeof(stu2[0]), cmp);

        printf("case #%d:\n%d\n", i, cnt);
        for (int j = 0; j < cnt; j++) {
            printf("%s %lld\n", stu2[j].number, stu2[j].grade);
        }

    }
    return 0;
}
