#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct information{
    char time1[11];
    char time2[6];
    int  size;
    char name[150];
};
typedef struct information info;
int cmpt(const void* a,const void* b){
    char *a1=((info*)a)->time1,*b1=((info*)b)->time1;
    char *a2=((info*)a)->time2,*b2=((info*)b)->time2;
    if (strcmp(a1,b1)>0) return 1;
    else if (strcmp(a1,b1)<0) return -1;
    else if (strcmp(a2,b2)>0) return  1;
    else return  -1;
}
int cmps(const void* a,const void* b){
    int a1=((info*)a)->size,b1=((info*)b)->size;
    if (a1>b1) return 1;
    else return -1;
}
int cmpn(const void* a,const void* b){
     char *a1=((info*)a)->name,*b1=((info*)b)->name;
     if (strcmp(a1,b1)>0) return 1;
        else return -1;
}
int main()
{
    char s1[13];
    info *email;
    int n;
    while(scanf("%d",&n)!=0){
        if (n==0) break;
        email=(info*)malloc(n*sizeof(info));
        for (int i=0;i<n;i++)
            scanf("%s%s%d%s",email[i].time1,email[i].time2,&email[i].size,email[i].name);
        scanf("%*s%s",s1);
        if(strcmp(s1,"/TIME")==0)
        qsort(email,n,sizeof(info),cmpt);
        else if((s1,"/SIZE")==0)
        qsort(email,n,sizeof(info),cmps);
        else if (strcmp(s1,"/NAME")==0)
        qsort(email,n,sizeof(info),cmpn);
        for (int i=0;i<n;i++)
            printf("%s %s%17d %s\n",email[i].time1,email[i].time2,email[i].size,email[i].name);
        printf("\n");
        free(email);
    }
    return 0;
}
