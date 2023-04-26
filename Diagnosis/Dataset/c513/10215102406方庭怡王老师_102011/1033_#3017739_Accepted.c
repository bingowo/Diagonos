#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char *mayamonth[19]={"pop", "no","zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
typedef struct
{
    int day,year;
    char month[10];
}MAYA;
int monthdigit(char * month);
int compar(const void *p1,const void *p2);
void myPrint(MAYA* a,int N);
int main()
{
    int T,N,i,j,temp;
    MAYA* a;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        a=(MAYA*)malloc(N*sizeof(MAYA));
        for(i=0;i<N;i++)
        {
            scanf("%d",&a[i].day);
            getchar();getchar();
            scanf("%s",a[i].month);
            scanf("%d",&a[i].year);
        }
        qsort(a,N,sizeof(MAYA),compar);
        myPrint(a,N);

        free(a);
    }
    return 0;
}
int monthdigit(char * month)
{
    int i;
    for(i=0;i<19;i++)
    {
        if(strcmp(month,mayamonth[i])==0)
            break;
    }
    return i+1;
}
int compar(const void *p1,const void *p2)
{
    int flag=0;
    MAYA *a=(MAYA*)p1,*b=(MAYA*)p2;
    if(a->year<b->year)
        flag=-1;
    else if(a->year>b->year)
        flag=1;
    else
    {
        if(monthdigit(a->month)<monthdigit(b->month))
            flag=-1;
        else if(monthdigit(a->month)>monthdigit(b->month))
            flag=1;
        else
        {
            if(a->day<b->day)
                flag=-1;
            else
                flag=1;
        }
    }
    return flag;
}
void myPrint(MAYA* a,int N)
{
    static int tim=0;
    int i=0;
    printf("case #%d:\n",tim++);
    for(i=0;i<N;i++)
    {
        printf("%d. %s %d\n",a[i].day,a[i].month,a[i].year);
    }

}