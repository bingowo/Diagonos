#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int ret;
    int year;
    char month[8];
    int day;
}record;
int cmp(const void *p1,const void *p2){
    return ((record*)p1)->ret - ((record*)p2)->ret;

}
int main() {
    int t;
    scanf("%d",&t);
    char a[19][7] = {"pop", "no", "zip", "zotz", "tzec", "xul",
                     "yoxkin", "mol", "chen", "yax", "zac", "ceh",
                     "mac", "kankin", "muan", "pax", "koyab","uayet"};
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        record b[n];
        for(int j =0;j<n;j++){
            scanf("%d",&(b[j].day));
            getchar();
            scanf("%s%d",b[j].month,&(b[j].year));
            int months;
            for(int p=0;p<19;p++){
                if(!strcmp(b[j].month,a[p])){
                    months = p;
                }
            }
            b[j].ret = (b[j].year-2000)*20*20+months*20+b[j].day;
        }
        qsort(b,n,sizeof(b[0]),cmp);
        printf("case #%d:\n",i);
        for(int m = 0;m<n;m++){
            printf("%d.%s %d\n",b[m].day,b[m].month,b[m].year);
        }
    }

    return 0;
}
