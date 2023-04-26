#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char form[20];
typedef struct{int year;int month;int day;int hour;int sec;int byte;char file[100];} deal;
int cmp(const void* a,const void * b)
{
    deal aa=*(deal*)a;
    deal bb=*(deal*)b;
    if(strcmp(form,"LIST /NAME")==0){return strcmp(aa.file,bb.file);}
    if(strcmp(form,"LIST /SIZE")==0){if(aa.byte==bb.byte)return strcmp(aa.file,bb.file);
    else return aa.byte-bb.byte;}
    if(strcmp(form,"LIST /TIME")==0){
        if(aa.year==bb.year){
            if(aa.month==bb.month){
                if(aa.day==bb.day){
                    if(aa.hour==bb.hour){
                            if(aa.sec==bb.sec)return strcmp(aa.file,bb.file);
                        else return aa.sec-bb.sec;
                    }
                    else return aa.hour-bb.hour;
                }
                else return aa.day-bb.day;
            }
            else return aa.month-bb.month;
        }
        else return aa.year-bb.year;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    deal* s;
    while(n){
            s=(deal*)malloc(sizeof(deal)*n);
    for(int i=0;i<n;i++){
        scanf("%d-%d-%d%d:%d%d%s",&s[i].year,&s[i].month,&s[i].day,&s[i].hour,&s[i].sec,&s[i].byte,s[i].file);
    }
    getchar();
    gets(form);
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++){
        printf("%04d-%02d-%02d %02d:%02d %16d %s\n",s[i].year,s[i].month,s[i].day,s[i].hour,s[i].sec,s[i].byte,s[i].file);
    }
    scanf("%d",&n);
    if(n)printf("\n");
    free(s);
    }

    return 0;

}
