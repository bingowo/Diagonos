#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data_
{
    char date[11];
    char time[6];
    int size;
    char name[70];
}DATA;

int cmp1(const void *F1_,const void *F2_)
{
    DATA F1=*(DATA *)F1_;
    DATA F2=*(DATA *)F2_;
    if(strcmp(F1.date,F2.date)==0)
        return strcmp(F1.time,F2.time);
    else
        return strcmp(F1.date,F2.date);
}
int cmp2(const void *F1_,const void *F2_)
{
    DATA F1=*(DATA *)F1_;
    DATA F2=*(DATA *)F2_;
    return F1.size>F2.size?1:-1;
}
int cmp3(const void *F1_,const void *F2_)
{
    DATA F1=*(DATA *)F1_;
    DATA F2=*(DATA *)F2_;
    return strcmp(F1.name,F2.name);
}

int main()
{
    int n;
    while(scanf("%d",&n)&&n!=0)
    {
        DATA *data;
        data=(DATA *)malloc(n*sizeof(DATA));
        for(int i=0;i<n;i++)
            scanf("%s%s%d%s",data[i].date,data[i].time,&data[i].size,data[i].name);
        char list[5],command[6];
        scanf("%s%s",list,command);
        if(strcmp(command,"/TIME")==0)
            qsort(data,n,sizeof(DATA),cmp1);
        else if(strcmp(command,"/SIZE")==0)
            qsort(data,n,sizeof(DATA),cmp2);
        else if(strcmp(command,"/NAME")==0)
            qsort(data,n,sizeof(DATA),cmp3);
        for(int i=0;i<n;i++)
            printf("%s %s %16d %s\n",data[i].date,data[i].time,data[i].size,data[i].name);
        free(data);
        printf("\n");
    }
    return 0;
}
