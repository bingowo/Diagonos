#include<stdio.h>
#include<stdlib.h>
char *month[] =
{
    "pop","no","zip", "zotz", "tzec", "xul",
    "yoxkin", "mol", "chen", "yax", "zac",
    "ceh", "mac", "kankin", "muan", "pax",
    "koyab", "cumhu","uayet"
};
struct date
{
    int y;//年
    char m;//月
    int d;//日
    int m_num;
}d[10000];

int cmp(const void* e1, const void* e2)
{
    struct date* a=(struct date*)e1;
    struct date* b=(struct date*)e2;
    if((*a).y == (*b).y)
    {
        if((*a).m_num == (*b).m_num)
        {return ((*a).d < (*b).d);}
        return((*a).m_num < (*b).m_num);
    }
    return ((*a).y < (*b).y);
}
int main()
{
    int t;//问题数
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;//每个问题
        scanf("%d",&n);
        for(int k=0;k<n;k++){
            //struct D[k].d;
            getchar();
            //struct D[k].m;
            //struct D[k].y;
            scanf("%d",&d[k].d);
            getchar();//读取‘.’符号
            scanf("%s",&d[k].m);
            getchar();//读取‘ ’符号
            scanf("%d",&d[k].y);
            for(int i = 0; i < 19; i++)
            {
                if(d[i].m == *month[i])
                    d[i].m_num = i;
            }
        }
        qsort(d,n,sizeof(d),cmp);
        printf("case #%d:\n",i);
        for(int j = 0; j < n; j++)
        {
            printf("%d.%s %d\n",d[j].d,d[j].m,d[j].y);
        }

    }
    return 0;
}