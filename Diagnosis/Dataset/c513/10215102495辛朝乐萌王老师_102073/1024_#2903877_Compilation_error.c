#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int num[12];
    int solved;
    int total;
}class;

int cmp(const void *a,const void *b)
{
    class *pa,*pb;
    pa = (class *)a;
    pb = (class *)b;
    if(pa->total!=pb->total){
        return pa->total-pb->total;
    }
    else{
        return strcmp(pa->num, pb->num);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        int numstu,numques,line;
        scanf("%d %d %d",&numstu,&numques,&line);
        int scores[numques],temp,cnt=0;
        class stu[numstu];
        for (int j=0; j<numques; ) {
            scanf("%d",&scores[j]);
        }
        for (int j=0;j<numstu; j++) {
            scanf("%s %d",stu[j].num,stu[j].solved);
            stu[j].total=0;
        }
        for (<#initialization#>; <#condition#>; <#increment#>) {
            <#statements#>
        }
    }
}

