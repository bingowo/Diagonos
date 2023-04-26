#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char date[11];
    char time[6];
    unsigned size;
    char name[64];
}F;

int cmpname(const void *p1,const void *p2);
int cmptime(const void *p1,const void *p2);
int cmpsize(const void *p1,const void *p2);

int main(void)
{
    int T;
    scanf("%d",&T);
    
    for(; T != 0; scanf("%d",&T)){
        F data[T];
        for(int i = 0; i < T; i++){
            scanf("%s",data[i].date);
            scanf("%s",data[i].time);
            scanf("%u",&data[i].size);
            scanf("%s\n",data[i].name);
        }
    
        char field[6];
        scanf("%*5s%s",field);
        if(strcmp(field,"/NAME") == 0) qsort(data,T,sizeof(F),cmpname);
        else if(strcmp(field,"/SIZE") == 0) qsort(data,T,sizeof(F),cmpsize);
        else qsort(data,T,sizeof(F),cmptime);
    
        for(int i = 0; i < T; i++){
            printf("%s ",data[i].date);
            printf("%s ",data[i].time);
            printf("%16u ",data[i].size);
            printf("%s\n",data[i].name);
        }
        printf("\n");
    }
        
    return 0;
}

int cmpname(const void *p1,const void *p2)
{
    F a = *(F*)p1;
    F b = *(F*)p2;
	return strcmp(a.name,b.name);
}

int cmptime(const void *p1,const void *p2)
{
    F a = *(F*)p1;
    F b = *(F*)p2;
    if(strcmp(a.date,b.date)) return strcmp(a.date,b.date);
    else if (strcmp(a.time,b.time)) return strcmp(a.time,b.time);
    else return strcmp(a.name,b.name);
}

int cmpsize(const void *p1,const void *p2)
{
    F a = *(F*)p1;
    F b = *(F*)p2;
    return a.size > b.size?1:a.size < b.size?-1:strcmp(a.name,b.name);
}