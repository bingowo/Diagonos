#include<stdio.h>
#include<stdlib.h>

struct data{
    int year;
    int month;
    int day;
    char mamo[6];
};


int mamoTOmanth(char* m){
static char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
for (int i=0;;i++) if (!strcmp(m,month[i])) return i;
}

int cmp(const void* a,const void* b){
struct data a1=*(struct data*)a;
struct data b1=*(struct data*)b;
if(a1.year==b1.year){
if(a1.month==b1.month){
    return a1.day>b1.day;
}
else return a1.month>b1.month;
}
else return a1.year>b1.year;
}

int main(){
    int T;
    for(int i=0;i<T;i++){
        int N;
        struct data p[N];
        for(int j=0;j<N;j++){
            scanf("%d.%s %d\n", &p[j].day, p[j].mamo, &p[j].year);
            p[j].month=mamoTOmanth(p[j].mamo);
        }
        qsort(p,N,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++){
            printf("%d. %s %d\n",p[j].day,p[j].mamo,p[j].year);
        }
    }


    return 0;
}
