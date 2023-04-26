#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char date[11];
    char time[6];
    int size;
    char name[200];
}File;



int cmpName(const void *a,const void *b)
{
    File pa=*(File*)a,pb=*(File*)b;
    return strcmp(pa.name,pb.name);
}

int cmpSize(const void *a,const void *b)
{
    File pa=*(File*)a,pb=*(File*)b;
    if(pa.size!=pb.size){return (pa.size>pb.size)?1:-1;}
    else return strcmp(pa.name,pb.name);
}

int cmpTime(const void *a,const void *b)
{
    File pa=*(File*)a,pb=*(File*)b;
    if(strcmp(pa.date,pb.date)!=0) return strcmp(pa.date,pb.date);
    else if(strcmp(pa.time,pb.time)!=0) return strcmp(pa.time,pb.time);
    else return strcmp(pa.name,pb.name);
}




int main(void)
{
	int n;scanf("%d",&n);
	while(n!=0){
        File files[n];
        for(int i=0;i<n;i++){
            scanf("%s%s%d%s",&files[i].date,&files[i].time,&files[i].size,&files[i].name);
        }
        char list[5],type[6];
        scanf("%s%s",&list,&type);
        if(strcmp(type,"/NAME")==0){qsort(files,n,sizeof(File),cmpName);}
        else if(strcmp(type,"/SIZE")==0){qsort(files,n,sizeof(File),cmpSize);}
        else if(strcmp(type,"/TIME")==0){qsort(files,n,sizeof(File),cmpTime);}
        for(int i=0;i<n;i++){
            printf("%s %s%16d %s\n",files[i].date,files[i].time,files[i].size,files[i].name);
        }
        printf("\n");
        scanf("%d",&n);
	}

	return 0;
}
