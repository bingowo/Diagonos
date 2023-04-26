#include <stdio.h>
#include <string.h>
typedef struct{
    char s[12];
    long long gra;
}stu;
int cmp(const void* a, const void* b){
    long long ga = (stu*)a->grade,gb = (stu*)b->grade;
    if(ga!=gb) return gb-ga>0?1:-1;
    else return strcmp(a->s,b->s);
}
int main()
{
    int T; scanf("%d",&T);
    for(int i = 0; i<T; i++)
    {
        printf("case #%d:\n",i);
        int N,M,G;
        scanf("%d%d%d",&N,&M,&G);
        stu a[N];//存储学生
        int m[M+1];//存储每道题的分数
        for(int j = 1; j<=M; j++)
        {
            scanf("%d",&m[j]);
        }
        for(int j = 0; j<N; j++)//读入学生
        {
            scanf("%s",a[j].s);//读入学生的学号
            int number;scanf("%d",&number);//学生做对的题目数
            long long sum = 0;
            for(int k = 0; k<number; k++)
            {
                int num; scanf("%d",&num);//题目序号
                sum+=m[num];
            }
            a[j].gra = sum;
        }
        qsort(a,N,sizeof(stu),cmp);
        int cnt = 0;
        while(a[cnt].gra>=G){
            cnt++;
        }
        if(!cnt){
            printf("%d",cnt);
            for(int k = 0; k<j; k++)
            {
                printf("%s %lld\n",a[k].s,a[k].gra);
            }
        }
        else printf("0\n");
    }
    return 0;
}