#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char date[15];
    char time[7];
    int size;
    char name[70];
} FIL;

int cmp1(const void* p3,const void* p4)
{
    FIL* p1=(FIL* )p3;
    FIL* p2=(FIL* )p4;
    int i=strcmp(p1->name,p2->name);
    if(i<0) return -1;
    else return 1;
}

int cmp2(const void* p3,const void* p4)
{
    FIL* p1=(FIL* )p3;
    FIL* p2=(FIL* )p4;
    if((p1->size)>(p2->size)) return 1;
    else if((p1->size)<(p2->size)) return -1;
    else{
        int i=strcmp(p1->name,p2->name);
        if(i<0) return -1;
        else return 1;
    }
}

int cmp3(const void* p3,const void* p4)
{
    FIL* p1=(FIL* )p3;
    FIL* p2=(FIL* )p4;
    int i=strcmp(p1->date,p2->date);
    if(i<0) return -1;
    else if(i>0) return 1;
    else{
        int j=strcmp(p1->time,p2->time);
        if(j<0) return -1;
        else if(j>0) return 1;
        else{
            int t=strcmp(p1->name,p2->name);
            if(t<0) return -1;
            else return 1;
        }
    }
}

int main()
{
    int n=0;
    while(scanf("%d",&n)){
    if(n==0) break;
    FIL* p=(FIL* )malloc(n*sizeof(FIL));
    for (int i=0;i<n;i++) {
            scanf("%s %s %d",(p+i)->date,(p+i)->time,&((p+i)->size));
            int k=0;
            char c;
            getchar();
            while((c=getchar())!='\n') {
                (p+i)->name[k]=c;
                k++;
            }
            (p+i)->name[k]=0;
    }
    char order[12],order1[7];
    scanf("%s %s",order,order1);
    if(order1[1]=='N') qsort(p,n,sizeof(FIL),cmp1);
    else if(order1[1]=='S') qsort(p,n,sizeof(FIL),cmp2);
    else if(order1[1]=='T') qsort(p,n,sizeof(FIL),cmp3);
    for (int j=0;j<n;j++) printf("%s %s %16d %s\n",(p+j)->date,(p+j)->time,(p+j)->size,(p+j)->name);
    free(p);}
    return 0;
}
