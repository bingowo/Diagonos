#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct a
{
    char time1[11];
    char time2[6];
    char size[10];
    char name[127];
}File;

void input(File *file);
void output(File *file);
int cmp_time(const void *a, const void *b);
int cmp_size(const void *a, const void *b);
int cmp_name(const void *a, const void *b);

int main()
{
    int n;
    int i;
    scanf("%d",&n);

    while (!n)
    {
        File *file = (File *)malloc(sizeof(File)*n);
        
        for (i=0;i<n;++i)
        {
            input(&file[i]);
        }

        char t1[5];
        char t2[6];
        scanf("%s %s",t1,t2);

        if (strcmp(t2+1,"TIME")==0)
            qsort(file,n,sizeof(File),cmp_time);
        else if (strcmp(t2+1,"SIZE")==0)
            qsort(file,n,sizeof(File),cmp_size);
        else if (strcmp(t2+1,"NAME")==0)
            qsort(file,n,sizeof(File),cmp_name);

        for (i=0;i<n;++i)
        {
            output(&file[i]);
        }
        putchar('\n');

        free(file);
        scanf("%d",&n);
    }

    return 0;
}

void input(File *file)
{
    scanf("%s",file->time1);
    scanf("%s",file->time2);
    scanf("%s",file->size);
    scanf("%s\n",file->name);

    return;
}

void output(File *file)
{
    printf(file->time1);
    
    putchar(' ');
    
    printf(file->time2);

    int len=strlen(file->size);
    int i;
    for (i=0;i<16-len;++i)
    {
        putchar(' ');
    }
    
    printf(file->size);
    
    putchar(' ');

    printf(file->name);

    putchar('\n');
    
    return;
}

int cmp_time(const void *a, const void *b)
{
    File *pa = (File *)a;
    File *pb = (File *)b;

    if(strcmp(pa->time1,pb->time1)==0)
    {
        return strcmp(pa->time1,pb->time1);
    }
    else
    {
        if (strcmp(pa->time2,pb->time2)==0)
        {
            return strcmp(pa->time2,pb->time2);
        }
        else 
        {
            return strcmp(pa->name,pb->name);
        }
    }
}

int cmp_size(const void *a, const void *b)
{
    File *pa = (File *)a;
    File *pb = (File *)b;

    if (strcmp(pa->size,pb->size)==0)
    {
        return strcmp(pa->name,pb->name);
    }
    else
    {
        return strcmp(pa->size,pb->size);
    }
}

int cmp_name(const void *a, const void *b)
{
    File *pa = (File *)a;
    File *pb = (File *)b;
    
    return strcmp(pa->name,pb->name);
}