#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char date[11];
    char time[6];
    int size;
    char name[128];
}file;

int cmpN(const void*a,const void *b)
{
    file *a1=(file*)a;
    file *b1=(file*)b;
    return strcmp(a1->name,b1->name);
}
int cmpT(const void*a,const void *b)
{
    file *pa = (file *)a;
	file *pb = (file *)b;
	if(strcmp(pa->date, pb->date) != 0){
		return strcmp(pa->date, pb->date);
	}else if(strcmp(pa->time, pb->time) != 0){
		return strcmp(pa->time, pb->time);
	}else{
		return strcmp(pa->name, pb->name);
	}
}
int cmpS(const void*a,const void *b)
{
    file *a1=(file*)a;
    file *b1=(file*)b;
    if(a1->size != b1->size){
		return a1->size - b1->size;
	}else{
		return strcmp(a1->name, b1->name);
	}
}

int main(void)
{
    int n;
    int i,j;
    scanf("%d", &n);
    while(n!=0)
    {
        file f[n];
        char instruction[5], temp[5];
        for(i = 0 ;i < n ; i ++){
			scanf("%s %s %d %s", f[i].date, f[i].time, &f[i].size, f[i].name);
		}
        scanf("%s %s",temp,instruction);
        if(strcmp(instruction,"/NAME")==0)
            qsort(f,n,sizeof(f[0]),cmpN);
        else if(strcmp(instruction, "/SIZE")==0)
            qsort(f,n,sizeof(f[0]),cmpS);
        else if(strcmp(instruction, "/TIME")==0)
            qsort(f,n,sizeof(f[0]),cmpT);
        for(j=0;j<n;j++)
        {
            printf("%s %s %16d %s\n", f[j].date, f[j].time, f[j].size, f[j].name);
		}
        printf("\n");
        scanf("%d", &n);
    }
    return 0;
}
