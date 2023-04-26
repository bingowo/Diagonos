#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char date[20];
    char time[10];
    int size;
    char name[65];
}file;
int main()
{
    int n;
    do{
        scanf("%d",&n);
        file a[101];
        for(int i=0;i<n;i++){
            scanf("%s %s %d %s",a[i].date,a[i].time,&a[i].size,a[i].name);
        }

        for(int i=0;i<n;i++)
            printf("%s %s %d %s",a[i].date,a[i].time,a[i].size,a[i].name);
        printf("\n");
    }while(n);
    return 0;
}