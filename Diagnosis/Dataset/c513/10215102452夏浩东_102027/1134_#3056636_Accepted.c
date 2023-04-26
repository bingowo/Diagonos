#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
  char L[11];
  int C,M,E,A;
};
int cmp1(const void*a,const void*b){
    struct student* c = (struct student*)a;
    struct student* d = (struct student*)b;
    if(c->A!=d->A) return d->A-c->A;
    else return strcmp(c->L,d->L);
}
int cmp2(const void*a,const void*b){
    struct student* c = (struct student*)a;
    struct student* d = (struct student*)b;
    if(c->C!=d->C) return d->C-c->C;
    else return strcmp(c->L,d->L);
}
int cmp3(const void*a,const void*b){
    struct student* c = (struct student*)a;
    struct student* d = (struct student*)b;
    if(c->M!=d->M) return d->M-c->M;
    else return strcmp(c->L,d->L);
}
int cmp4(const void*a,const void*b){
    struct student* c = (struct student*)a;
    struct student* d = (struct student*)b;
    if(c->E!=d->E) return d->E-c->E;
    else return strcmp(c->L,d->L);
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int mm=0;mm<cnt;mm++){
        int stunum=0;
        scanf("%d",&stunum);
        struct student SL[100];
        for(int j=0;j<stunum;j++){
            scanf("%s %d %d %d",SL[j].L,&SL[j].C,&SL[j].M,&SL[j].E);
            double temp = 1.0*(SL[j].C+SL[j].M+SL[j].E)/3;
            SL[j].A = temp-(int)temp>=0.5?(int)temp+1:(int)temp;
        }
        printf("case #%d:\n",mm);
        qsort(SL,stunum,sizeof(struct student),cmp1);
        printf("A:\n");
        printf("%s\n",SL[0].L);
        for(int i=1;i<stunum;i++){
            if(SL[i].A==SL[i-1].A) printf("%s\n",SL[i].L);
            else break;
        }
        
        qsort(SL,stunum,sizeof(struct student),cmp2);
        printf("C:\n");
        printf("%s\n",SL[0].L);
        for(int i=1;i<stunum;i++){
            if(SL[i].C==SL[i-1].C) printf("%s\n",SL[i].L);
            else break;
        }
        
        qsort(SL,stunum,sizeof(struct student),cmp3);
        printf("M:\n");
        printf("%s\n",SL[0].L);
        for(int i=1;i<stunum;i++){
            if(SL[i].M==SL[i-1].M) printf("%s\n",SL[i].L);
            else break;
        }
        
        qsort(SL,stunum,sizeof(struct student),cmp4);
        printf("E:\n");
        printf("%s\n",SL[0].L);
        for(int i=1;i<stunum;i++){
            if(SL[i].E==SL[i-1].E) printf("%s\n",SL[i].L);
            else break;
        }
    }
    return 0;
}