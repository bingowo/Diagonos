#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct mail
{
    char name[100];
    char src[100];
};
int cmp(void *a,void*b)
{
    if(strcmp(((struct mail*)a)->src,((struct mail*)b)->src)!=0) return strcmp(((struct mail*)a)->src,((struct mail*)b)->src);
    else return -strcmp(((struct mail*)a)->name,((struct mail*)b)->name);
}
int main()
{
    int n;
    scanf("%d",&n);
    char c;
    struct mail res[1000];
    for(int i=0;i<n;i++)
    {
        int p=0,q=0;
        while((c=getchar())!='@') res[i].name[p++]=c;
        res[i].name[p]='\0';
        scanf("%s",res[i].src);
    }
    qsort(res,n,sizeof(struct mail),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%s",res[i].name);
        printf("@");
        printf("%s",res[i].src);
        printf("\n");
    }
}