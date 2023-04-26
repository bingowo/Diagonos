#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char time1[20];
    char time2[12];
    int size;
    char name[64];
}DOCU;

int name_cmp(const void *a,const void *b)
{
    return strcmp((*(DOCU *)a).name,(*(DOCU *)b).name);
}

int time1_cmp(const void *a,const void *b)
{
    if(strcmp((*(DOCU *)a).time1,(*(DOCU *)b).time1)!=0)
        return strcmp((*(DOCU *)a).time1,(*(DOCU *)b).time1);
    else if(strcmp((*(DOCU *)a).time2,(*(DOCU *)b).time2)!=0)
        return strcmp((*(DOCU *)a).time2,(*(DOCU *)b).time2);
    else
        return strcmp((*(DOCU *)a).name,(*(DOCU *)b).name);
}

/*int time2_cmp(const void *a,const void *b)
{
    if((*(DOCU *)a).time1==(*(DOCU *)b).time1)
        return strcmp((*(DOCU *)a).time2,(*(DOCU *)b).time2);
    else
        return 0;
}*/

int size_cmp(const void *a,const void *b)
{
    return (*(DOCU *)a).size>(*(DOCU *)b).size;
}

int main()
{
    int n;
    char request1[11],request2[5];
    DOCU file[101];
    while((scanf("%d",&n))!=EOF)
    {
        //printf("n is %d\n",n);
        if(n==0)
            break;
        for(int i=0;i<n;i++)
            scanf("%s%s%d%s",file[i].time1,file[i].time2,&file[i].size,file[i].name);
        scanf("%s%s",request1,request2);
       // printf(">>>>>>>>>>>>>>>>>>");
        //printf("%s\n",file[0].time1);
        //scanf("%d",&n);
        switch(request2[1])
        {
        case 'T':
            qsort(file,n,sizeof(DOCU),time1_cmp);
            break;
        case 'N':
            qsort(file,n,sizeof(DOCU),name_cmp);
            break;
        case 'S':
            qsort(file,n,sizeof(DOCU),size_cmp);
            break;
        }
        for(int i=0;i<n;i++)
        {
            printf("%s %s %16d %s\n",file[i].time1,file[i].time2,file[i].size,file[i].name);
        }
        printf("\n");
    }
    return 0;
}
