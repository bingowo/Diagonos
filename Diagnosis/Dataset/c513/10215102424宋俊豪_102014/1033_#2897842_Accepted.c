#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int val;   //表示日期“大小”的值
    int y;   //年
    int d;   //日
    char m[7];   //玛雅历的月份
} list;
int month2idx(char* m)
{
    //1-19月份数组，为静态字符串数组
    static char* month[]   =
    {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

    for (int i=0;; i++)
        if (!strcmp(m,month[i])) return i;   //返回月份编号i
}
int cmp(const void* a,const void* b)
{
     return ((list*)a)->val - ((list*)b)->val; }

int main()
{
    int n,n1,j,cnt;
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        scanf("%d",&n1);
        list *a=(list*)malloc(n1*sizeof(list));
        for (j=0; j<n1; j++)
        {
            scanf("%d.%s %d",&a[j].d,a[j].m,&a[j].y);
            a[j].val = a[j].y*1000 + month2idx(a[j].m)*20 + a[j].d;
        }
        qsort(a,n1,sizeof(list),cmp);
     printf("case #%d:\n",i);
     for (int q=0;q<n1;q++)
     printf("%d. %s %d\n",a[q].d,a[q].m,a[q].y);
     free(a);

    }
    return 0;
}

