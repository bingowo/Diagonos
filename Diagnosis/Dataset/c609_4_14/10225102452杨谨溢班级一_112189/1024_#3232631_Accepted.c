#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int YEAR;
int MOUTH;
int DAY;
int HOUR;
int MINI;
int SIZE;
char NAME[70];
}FIL;

int cmpname(const void*a,const void*b)  // 文件名均不相同
{
    FIL A = *(FIL*)a,B = *(FIL*)b;
    char *stra = A.NAME,*strb = B.NAME;
    return strcmp(stra,strb);
}

int cmpsize(const void*a,const void*b)
{
    FIL A = *(FIL*)a,B = *(FIL*)b;
    char *stra = A.NAME,*strb = B.NAME;
    int aa = A.SIZE,bb = B.SIZE;
    if (aa == bb)  return strcmp(stra,strb);
    return aa-bb;
}

int cmptime(const void*a,const void*b)
{
    FIL A = *(FIL*)a,B = *(FIL*)b;
    char *stra = A.NAME,*strb = B.NAME;
    int ya = A.YEAR,yb = B.YEAR,ma = A.MOUTH,mb = B.MOUTH,da = A.DAY,db = B.DAY,ha = A.HOUR,hb = B.HOUR,na = A.MINI,nb = B.MINI;
    if (ya != yb) return ya-yb;
    if (ma != mb) return ma-mb;
    if (da != db) return da - db;
    if (ha != hb) return ha - hb;
    if (na != nb) return na -nb;
    return  strcmp(stra,strb);
}

int main()
{
    int TEAM;
    while(scanf("%d",&TEAM))
    {
        if (TEAM == 0)  break;
        FIL* files = malloc(TEAM * sizeof(FIL));
        for (int ord = 0;ord<TEAM;++ord)
        {
            scanf("%4d-%02d-%2d",&files[ord].YEAR,&files[ord].MOUTH,&files[ord].DAY);
            scanf("%d:%d",&files[ord].HOUR,&files[ord].MINI);
            scanf("%d",&files[ord].SIZE);
            scanf("%s",files[ord].NAME);
        }
        char way[10];
        scanf("%s",way); scanf("%s",way);
        switch (way[1])
        {
            case 'N': {
                qsort(files,TEAM,sizeof(files[0]),cmpname);
                break;}
            case 'S':{
                qsort(files,TEAM,sizeof(files[0]),cmpsize);
                break;}
            case 'T':{
                qsort(files,TEAM,sizeof(files[0]),cmptime);
                break;}
        }
        for (int ord = 0;ord<TEAM;++ord)
        {
            printf("%4d-%02d-%02d %02d:%02d%17d %s\n",files[ord].YEAR,files[ord].MOUTH,files[ord].DAY,files[ord].HOUR,files[ord].MINI,files[ord].SIZE,files[ord].NAME);
        }
        printf("\n");
    }
    return 0;
}
