#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct text
{
    char name[64];
    char date[17];
    char time[10];
    int size;
}TEXT;
int cmp1(const void *a,const void *b)
{
    TEXT a1=*(TEXT *)a;
    TEXT b1=*(TEXT *)b;
    int s1=a1.size,s2=b1.size;
    
}
int main()
{
    int n;
    TEXT *a=NULL;
    scanf("%d",&n);
    a=(TEXT*)malloc(sizeof(TEXT)*n);
    do
    {
        for(int i=0;i<n;i++){
            scanf("%s %s %d %s",a[i].date,a[i].time,a[i].size,a[i].name)
        }
        qsort(a,n,sizeof(text),cmp1);
        scanf("%d",&n);
        if(n!=0)printf("\n");
    }while(n!=0);
    return 0;
}