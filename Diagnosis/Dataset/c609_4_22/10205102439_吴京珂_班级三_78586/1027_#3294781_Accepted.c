#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    char stu[11];//学号
    int s;//总成绩
} node;

int cmp(const void* a, const void* b)
{
    node p1=*(node *)a;
    node p2=*(node *)b;
    if(p1.s!=p2.s) return p2.s-p1.s;
    else return strcmp(p1.stu,p2.stu);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        int n,m,g;
        scanf("%d %d %d",&n,&m,&g);

        int a[m];//满分
        for(int j=0; j<m; j++)
        {
            scanf("%d",&a[j]);
        }

        node p[n];//结构体
        int count=0;//符合条件学生数
        for(int j=0; j<n; j++)
        {
            int num;//题目数
            scanf("%s %d",p[j].stu,&num);

            p[j].s=0;
            for(int k=0; k<num; k++)
            {
                int x;
                scanf("%d",&x);
                p[j].s+=a[x-1];
            }
            if(p[j].s>=g) count++;
        }
        qsort(p,n,sizeof(p[0]),cmp);

        printf("case #%d:\n",i);
        printf("%d\n",count);
        for(int j=0; j<count; j++)
        {
            printf("%s %d\n",p[j].stu,p[j].s);
        }
    }

    return 0;
}



