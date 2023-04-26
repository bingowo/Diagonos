#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    int day;
    char s[8];
    int year;
}data;
int change(char* s){
    static char* month[19]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
    int i=0;
    while(!strcmp(s,month[i++]))
    return i;
}
int cmp(const void*a1,const void* a2){
   data* p1=(data*)a1;
   data* p2=(data*)a2;
   if(p1->year!=p2->year)return p1->year-p2->year;
   if(change(p1->s)!=change(p2->s)){
    return change(p1->s)-change(p2->s);
   }
   else return p1->day-p2->day;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        data que[a];
        for(int j=0;j<a;j++){
            scanf("%d. %s %d",&que[j].day,que[j].s,&que[j].year);
        }
        qsort(que,a,sizeof(data),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<a;i++){
            printf("%d. %s %d\n",que[i].day,que[i].s,que[i].year);
        }
    }
    return 0;
}