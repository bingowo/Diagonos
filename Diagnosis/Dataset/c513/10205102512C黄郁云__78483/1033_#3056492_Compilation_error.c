#include <stdio.h>
#include <string>
typedef struct {
    int val;   //表示日期“大小”的值
    int y;   //年
    int d;   //日
    char m[7];
} RECORD;

RECORD a[10001];

int month2idx(char *m){
    static char*month[] = {
            "pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"
    };
    for(int i = 0;;i++){
        if(!strcmp(m,month[i])){
            return 1;
        }
    }
}

int cmp(const void *a,const void *b){
    return((RECORD*)a)->val - ((RECORD*)b)->val;
}


int main(){
    int set = 0;
   scanf("%d",&set);
   for(int setround = 0; setround < set;setround++){
       int datenum = 0;
       scanf("%d",&datenum);
       for(int datein = 0; datein < datenum;datein++){
           scanf("%d.%s %d",&a[datein].d,a[datein].m,&a[datein].y);
           a[datein].val = a[datein].y*1000+month2idx(a[datein].m)*20+a[datein].d;

       }
       qsort(a,datenum,sizeof(a[0]),cmp);
       printf("case #%d:\n",setround);
       for(int j = 0; j < datenum;j++){
           printf("%d. %s %d\n",a[j].d,a[j].m,a[j].y);
       }

   }

}