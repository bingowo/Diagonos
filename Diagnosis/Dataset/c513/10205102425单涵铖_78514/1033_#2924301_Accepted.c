#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int d;int m;int y;char month[10];
}Maya;

int cmp(const void* a,const void* b)
{
    Maya A,B;
    A = *(Maya*) a;
    B = *(Maya*) b;
    if(A.y!=B.y)  return A.y - B.y;
    else if(A.y==B.y&&A.m!=B.m)  return A.m - B.m;
    else    return A.d - B.d;
}

int change(char* m)
{
    int i;
    static char* month[] ={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    //顺序比较月份字符串，相同则返回编号i
    for (i=0;;i++) if (!strcmp(m,month[i])) return i;
}

int main()
{
    int t;
    int n;

    char date[20];

    scanf("%d",&t);

    Maya x[10000];

    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%d. %s %d\n",&x[j].d,&x[j].month,&x[j].y);
            int k=change(x[j].month);
            x[j].m = k;
        }

        qsort(x,n,sizeof(x[0]),cmp);

        printf("case #%d:\n",i);

        for(int j=0;j<n;j++)
        {
            printf("%d. %s %d\n",x[j].d,x[j].month,x[j].y);
        }
    }
}