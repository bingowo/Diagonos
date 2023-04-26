#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int num;
    char* user;
    char* hos;
} STR;



int mgetline(char s[],int lim)
{
    int c,i;
    i=0;
    while ((c=getchar())!=EOF && c!='\n' && i<lim-1 && c!='@')
        s[i++]=c;
    if (c==EOF && i==0)
        return -1;
    s[i]='\0';
    return i;
}


int cmp(const void *a,const void *b)
{
    STR* pa=(STR*)a; STR* pb=(STR*)b;
    if (strcmp(pa->hos,pb->hos)<0) return -1;
    if (strcmp(pa->hos,pb->hos)>0) return 1;
    if (strcmp(pa->hos,pb->hos)==0)
    {
        return strcmp(pa->user,pb->user)<0?1:-1;
    }
}



int main()
{
    int T,n,j;
    int a,b;
    scanf("%d",&T);
    getchar();


    STR* arr=(STR*)malloc(T*sizeof(STR));
    for (int i=0;i<T;i++)
    {
        arr[i].num=100000/T;
        arr[i].user=(char*)malloc(arr[i].num*sizeof(char));
        arr[i].hos=(char*)malloc(arr[i].num*sizeof(char));
        a=mgetline(arr[i].user,arr[i].num);
        b=mgetline(arr[i].hos,arr[i].num);
    }
    qsort(arr,T,sizeof(STR),cmp);
    for (j=0;j<T;j++)
        printf("%s@%s\n",arr[j].user,arr[j].hos);
    for (int i=0;i<T;i++)
    {
        free(arr[i].user);
        free(arr[i].hos);
    }
    free(arr);


    return 0;
}
