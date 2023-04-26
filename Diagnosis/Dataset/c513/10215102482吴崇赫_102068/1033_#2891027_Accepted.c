#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 10005

char month[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

typedef struct
{
    int day;int year;
    char month[10];
}date;

int getMonth(char* s)
{
    for(int i=0;i<19;++i){
        if(strcmp(s,month[i])==0)return i;
    }
    return -1;
}

int cmp(const void* a,const void* b)
{
    date *da=(date*)a;date* db=(date*)b;
    if(da->year!=db->year)return da->year>db->year?1:-1;
    else if(getMonth(da->month)!=getMonth(db->month))return getMonth(da->month)>getMonth(db->month)?1:-1;
    else return da->day>db->day?1:-1;
}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        date d[N];
        for(int i=0;i<N;++i){
            d[i].year=d[i].day=0;
            for(int j=0;j<10;++j)d[i].month[j]='\0';
        }
        int n;scanf("%d\n",&n);
        for(int i=0;i<n;++i)scanf("%d. %s %d",&d[i].day,d[i].month,&d[i].year);
        qsort(d,n,sizeof(d[0]),cmp);
        printf("case #%d:\n",x++);
        for(int i=0;i<n;++i)printf("%d. %s %d\n",d[i].day,d[i].month,d[i].year);
    }
    return 0;
}
