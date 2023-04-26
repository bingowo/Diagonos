#include<stdio.h>
#include <stdlib.h>


typedef struct stu{
    long long int id;
    int sum;
    int point_sum;
}student;

int cmp(const void* a,const void*b){
    student* p1 = (student*)a;
    student* p2 = (student*)b;
    if(p2->point_sum == p1->point_sum){
        if(p1->id - p2->id > 0)return 1;
    }
    return p2->point_sum - p1->point_sum;

}

int main()
{
    int loop;
    scanf("%d",&loop);

    for (int i = 0; i < loop; ++i) {
        int cnt = 0;
        int stu_num,que_num,line;
        scanf("%d %d %d",&stu_num,&que_num,&line);
        int point[que_num];
        for (int j = 0; j < que_num; ++j) {scanf("%d",&point[j]);}

        student st[stu_num];
        for (int j = 0; j < stu_num; ++j) {st[j].point_sum = 0;}

        for (int j = 0; j < stu_num; ++j) {
            scanf("%lld %d",&st[j].id,&st[j].sum);
            for (int k = 0; k < st[j].sum; ++k) {
                int it;scanf("%d",&it);
                st[j].point_sum = st[j].point_sum + point[it - 1];
            }if(st[j].point_sum >= line)cnt++;
        }
        printf("case #%d:\n%d\n",i,cnt);
        qsort(st,stu_num,sizeof(student),cmp);
        for (int j = 0; j < stu_num; ++j) {
            if(st[j].point_sum >= line)
            {
                
                if(st[j].id < 10000000000)printf("%d",0);
                if(st[j].id < 1000000000)printf("%d%d",0,0);
                printf("%lld %d\n",st[j].id,st[j].point_sum);
            }
        }

    }
}



