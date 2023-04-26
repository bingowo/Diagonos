#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char num[12];
    int solved;
    int total;
}class;

int cmp(const void *a,const void *b)
{
    class *pa,*pb;
    pa = (class *)a;
    pb = (class *)b;
    if(pa->total!=pb->total){
        return pb->total-pa->total;
    }
    else{
        return strcmp(pa->num, pb->num);
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        int numstu,numques,line;
        scanf("%d %d %d",&numstu,&numques,&line);
        int scores[numques],temp,cnt=0;
        class stu[numstu];
        for (int j=0; j<numques;j++) {
            scanf("%d",&scores[j]);
        }
        for (int j=0;j<numstu; j++) {
            scanf("%s %d",stu[j].num,&stu[j].solved);
            stu[j].total=0;
            for (int k=0; k<stu[j].solved; k++) {
                scanf("%d",&temp);
                stu[j].total += scores[temp-1];
            }
        }
        qsort(stu, numstu, sizeof(class), cmp);
        for (; stu[cnt].total>=line; cnt++) ;
        printf("case #%d:\n",i);
        printf("%d\n",cnt);
        for (int j=0; j<numstu; j++) {
            if(stu[j].total>=line){
                printf("%s %d\n",stu[j].num,stu[j].total);
            }
        }
    }
    return 0;
}