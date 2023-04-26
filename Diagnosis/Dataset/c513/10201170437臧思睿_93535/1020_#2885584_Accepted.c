#include <string.h>
#include <stdlib.h>
 
typedef struct {
    char time[17]; 
    char name[70]; 
    int size;
} FileStruct;
 
int time(const void*a, const void*b)
{
    FileStruct *p1 = (FileStruct*)a, *p2 = (FileStruct*)b;
    if(!strcmp(p1->time, p2->time))
        return strcmp(p1->name, p2->name);
    return strcmp(p1->time, p2->time);
}
int name(const void*a, const void*b)
{
    FileStruct *p1=(FileStruct*)a, *p2=(FileStruct*)b;
    return strcmp(p1->name, p2->name);
}
int size(const void*a, const void*b)
{
    FileStruct *p1=(FileStruct*)a, *p2=(FileStruct*)b;
    if(p1->size==p2->size) 
        return strcmp(p1->name, p2->name);
    return p1->size-p2->size;
}
int main()
{
    int n;
    char command[6];
    scanf("%d",&n);
    while(n)
    {
        FileStruct f[100];
        int i; char t[6];
        for(i = 0; i < n; i++) {
            scanf("%s %s", f[i].time, t);
            strcat(f[i].time, " "); strcat(f[i].time, t);
            scanf("%d %s", &f[i].size, f[i].name);
        }
        scanf("%*5s%s",command);
        if(!strcmp(command, "/NAME"))
            qsort(f, n, sizeof(f[0]), name);
        else if(!strcmp(command, "/SIZE"))
            qsort(f, n, sizeof(f[0]), size);
        else
            qsort(f, n, sizeof(f[0]), time);
        for(i = 0; i<n; i++)
            printf("%s %16d %s\n", f[i].time, f[i].size, f[i].name);
        printf("\n");
        if(!scanf("%d",&n)) 
            break;
    }
    return 0;
}
