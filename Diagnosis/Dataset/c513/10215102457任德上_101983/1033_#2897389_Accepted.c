#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[][7]={"pop","no","zip","zotz", "tzec", "xul", "yoxkin","mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax","koyab","cumhu","uayet"};
struct maya{
    int year;
    char month[7];
    int day;
};
int get_month(char *s){
    int month;
    for(int i=0;i<19;i++){
        if(strcmp(a[i],s)==0)return i+1;
    }
}
int cmp(const void *a,const void *b){
    struct maya *m1,*m2;
    m1=(struct maya *)a;
    m2=(struct maya *)b;
    int n1,n2;
    if(m1->year==m2->year){
        n1=get_month(m1->month);
        n2=get_month(m2->month);
        if(n1==n2){
            return m1->day-m2->day;
        }
        return n1-n2;
    }
    if(m1->year>m2->year)return 1;
    return -1;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;
        scanf("%d",&N);
        struct maya *t;
        t=(struct maya *)malloc(N*sizeof(struct maya));
        for(int n=0;n<N;n++){
            scanf("%d. %s%d",&(t+n)->day,(t+n)->month,&(t+n)->year);
        }
        qsort(t,N,sizeof(struct maya),cmp);
        printf("case #%d:\n",i);
        for(int n=0;n<N;n++){
            printf("%d. %s %d\n",(t+n)->day,(t+n)->month,(t+n)->year);
        }



    }
    return 0;




}
