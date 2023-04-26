#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char date[11];
    char time[6];
    int size;
    char name[64];
} fi;

int cmp1name(const void*a,const void*b)
{
    fi x1=*(fi*)a;
    fi x2=*(fi*)b;
    return strcmp(x1.name,x2.name);//*(fi*)b.name 错，(*(fi*)b).name对
}

int cmp2size(const void*a,const void*b)
{
    fi x1=*(fi*)a;
    fi x2=*(fi*)b;
    if(x1.size!=x2.size)
        return x1.size-x2.size;
    else return strcmp(x1.name,x2.name);
}

int cmp3time(const void*a,const void*b)
{

    fi x1=*(fi*)a;
    fi x2=*(fi*)b;
    if(strcmp(x1.date,x2.date)!=0)
        return strcmp(x1.date,x2.date);
    else if(strcmp(x1.time,x2.time)!=0)
        return strcmp(x1.time,x2.time);
    else return strcmp(x1.name,x2.name);
}





int main()
{
    int n;
    scanf("%d",&n);//number of files
    int i;
    char list[7];
    fi*fils;
    while(n!=0){
        fils=(fi*)malloc(sizeof(fi)*n);
    for(i=0;i<n;i++)

        scanf("%s%s%d%s",fils[i].date,fils[i].time,&fils[i].size,fils[i].name);
       
        scanf("%s",list);//read "LIST" first
        scanf("%s",list);
        if(strcmp(list,"/NAME")==0)
            qsort(fils,n,sizeof(fils[0]),cmp1name);
        else if(strcmp(list,"/SIZE")==0)
            qsort(fils,n,sizeof(fils[0]),cmp2size);
        else
            qsort(fils,n,sizeof(fils[0]),cmp3time);
        for(int k=0;k<n-1;k++)
            printf("%s %s %16d %s\n", fils[k].date, fils[k].time, fils[k].size, fils[k].name);
        printf("%s %s %16d %s", fils[n-1].date, fils[n-1].time, fils[n-1].size, fils[n-1].name);
        printf('\n');
        free(fils);
    scanf("%d",&n);
    }

    return 0;
}