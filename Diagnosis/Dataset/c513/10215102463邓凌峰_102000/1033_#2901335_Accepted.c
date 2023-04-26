#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int day;
    char month[7];
    int year;
}Time;

int order(char month[])
{
    int ans=-1;
    if(strcmp(month,"pop")==0) ans=1;
    if(strcmp(month,"no")==0) ans=2;
    if(strcmp(month,"zip")==0) ans=3;
    if(strcmp(month,"zotz")==0) ans=4;
    if(strcmp(month,"tzec")==0) ans=5;
    if(strcmp(month,"xul")==0) ans=6;
    if(strcmp(month,"yoxkin")==0) ans=7;
    if(strcmp(month,"mol")==0) ans=8;
    if(strcmp(month,"chen")==0) ans=9;
    if(strcmp(month,"yax")==0) ans=10;
    if(strcmp(month,"zac")==0) ans=11;
    if(strcmp(month,"ceh")==0) ans=12;
    if(strcmp(month,"mac")==0) ans=13;
    if(strcmp(month,"kankin")==0) ans=14;
    if(strcmp(month,"muan")==0) ans=15;
    if(strcmp(month,"pax")==0) ans=16;
    if(strcmp(month,"koyab")==0) ans=17;
    if(strcmp(month,"cumhu")==0) ans=18;
    if(strcmp(month,"uayet")==0) ans=19;
    return ans;
}


int cmp(const void *a,const void *b)
{
    Time pa=*(Time*)a,pb=*(Time*)b;
    int oa=order(pa.month),ob=order(pb.month);
    if(pa.year!=pb.year) return pa.year>pb.year?1:-1;
    else if(strcmp(pa.month,pb.month)!=0) return oa>ob?1:-1;
    else return pa.day-pb.day;
}

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;scanf("%d",&N);
        Time times[N];
        for(int j=0;j<N;j++){
            scanf("%d.%s%d",&times[j].day,&times[j].month,&times[j].year);
        }
        qsort(times,N,sizeof(Time),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++){
            printf("%d. %s %d\n",times[j].day,times[j].month,times[j].year);
        }

    }


	return 0;
}
