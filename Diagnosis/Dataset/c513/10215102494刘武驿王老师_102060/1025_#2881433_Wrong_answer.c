#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct str
{
    char ori[100];
    int num;
};
int cmp(void*a,void*b)
{
    if(((struct str*)a)->num!=((struct str*)b)->num) 
    return ((struct str*)b)->num-((struct str*)a)->num;
    else return strcmp(((struct str*)a)->ori,((struct str*)b)->ori);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int pros;
        scanf("%d",&pros);
        struct str res[100];
        for(int j=0;j<pros;j++) res[j].num=0;
        for(int j=0;j<pros;j++) scanf("%s",res[j].ori);
        for(int j=0;j<pros;j++)
        {
            int count=1,m;
            for(int x=1;x<strlen(res[j].ori);x++)
            {
                for(m=0;m<x;m++) if(res[j].ori[m]==res[j].ori[x]) break;
                if(m==x) count++;
            }
            res[j].num=count;
        }
        qsort(res,pros,sizeof(struct str),cmp);
        printf("case #%d:\n",n);
        for(int x=0;x<pros;x++)
        {
            printf("%s\n",res[x].ori);
        }
    }
    
}