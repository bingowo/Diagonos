#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int value;//记录月份
    int day;
    char mouth[8];
    int year;
}code;
int month2idx(char* m)
{
    int i=0;//1-19月份数组，为静态字符串数组
    char month[20][10]=
    {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    //顺序比较月份字符串，相同则返回编号i
    for (i=0;i<21;i++) if(strcmp(m,month[i])==0) return i;
}
int cmp(const void *a,const void *b)
{
    code *s1=(code *)a,*s2=(code *)b;
    if(s1->year>s2->year) return 1;
    else if(s1->value>s2->value) return 1;
    else if(s1->day>s2->day) return 1;
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
            scanf("%d. %s%d\n", &p[j].day, &p[j].mouth, &p[j].year);
            p[i].value=month2idx(p[i].mouth);
        }
        qsort(p,n,sizeof(code),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            printf("%d. %s %d\n",p[j].day,p[j].mouth,p[j].year);
        }
        free(p);
    }
    return 0;
}
