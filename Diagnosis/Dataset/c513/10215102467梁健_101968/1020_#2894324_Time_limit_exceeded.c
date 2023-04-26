#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct text
{
    char date[15];
    char time[8];
    int s;
    char name[64];
}TEXT;
int main()
{
    int n;
    scanf("%d",&n);
    do{
        TEXT *a=NULL;
        char order[10];
        a=(TEXT*)malloc(sizeof(TEXT)*n);
        for(int i=0;i<n;i++)scanf("%s %s %ld %s",a[i].date,a[i].time,&a[i].s,a[i].name);
        scanf("%s",order);
        scanf("%d",&n);
    }while(n!=0);
    return 0;
}
