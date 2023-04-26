#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int value;
    int day;
    char mouth[8];
    int year;
}code;
int month2idx(char* m)
{
    int i;//1-19月份数组，为静态字符串数组
    static char* month[] =
    {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    //顺序比较月份字符串，相同则返回编号i
    for (i=0;;i++) if (!strcmp(m,month[i])) return i;
}
int cmp(const void *a,const void *b)
{
    code *s1=(code *)a,*s2=(code *)b;
    if(s1->value>s2->value) return 1;
    else return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        code *p=(code *) malloc(n*sizeof(code));
        for(int j=0;j<n;j++)
        {
            scanf("%d.%s %d\n", &p[j].day, p[j].mouth, &p[j].year);
            p[i].value=p[i].year*500+month2idx(p[i].mouth)*21+p[i].day;
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            printf("%d.%s %d\n",p[j].day,p[j].mouth,p[j].year);
        }
        free(p);
    }
    return 0;
}
