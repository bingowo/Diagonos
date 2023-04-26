#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char time[10];
    char name[64];
    char date[20];
    int size;
}file;

int cmp1(const void *a,const void*b )
{
    file *p1=(file*)a;
    file *p2=(file*)b;
    return strcmp(p1->name,p2->name);
}

int cmp2(const void *a,const void *b)
{
    file *p1=(file*)a;
    file *p2=(file*)b;
    if(p1->size != p2->size)
    {
        return p1->size-p2->size;
    }
    else {return strcmp(p1->name,p2->name);}

}


int cmp3(const void *a,const void *b)
{
   file *p1=(file*)a;
    file *p2=(file*)b;
    if(strcmp(p1->date,p2->date)!=0){
        return strcmp(p1->date,p2->date);
    } else if(strcmp(p1->time,p2->time)!=0){
        return strcmp(p1->time,p2->time);
    }else{
        return strcmp(p1->name,p2->name);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    //file a[n];
    while(n){
        file a[n];
        char s[5],l[5];
        for(int i=0;i<n;i++){
        scanf("%s %s %d %s",a[i].date,a[i].time,&a[i].size,a[i].name);

        }
        scanf("%s /%s",l,s);
        if(strcmp(s,"NAME")==0)
        {qsort(a,n,sizeof(a[0]),cmp1);}
        else if(strcmp(s,"SIZE")==0)
         {qsort(a,n,sizeof(a[0]),cmp2);}
        else //if(strcmp(s,"TMIE")==0)
        {qsort(a,n,sizeof(a[0]),cmp3);}
        for(int j=0;j<n;j++){
            printf("%s %s %16d %s\n",a[j].date,a[j].time,a[j].size,a[j].name);
        }
        scanf("%d",&n);
        printf("\n");
    }
    
    
    return 0;
}