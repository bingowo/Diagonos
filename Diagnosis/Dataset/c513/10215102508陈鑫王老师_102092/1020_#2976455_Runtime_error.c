#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct FILE{
    char year[11];
    char time[6];
    int size;
    char name[128];

};
int cmp1(const void*a,const void* b)
{
    struct FILE* x=(struct FILE*)a;
    struct FILE* y=(struct FILE*)b;
    return strcmp(x->name,y->name);
}
int cmp2(const void*a,const void*b)
{
    struct FILE* x=(struct FILE*)a;
    struct FILE* y=(struct FILE*)b;
    if(x->size!=y->size)return x->size-y->size;
    else return strcmp(x->name,y->name);


}
int cmp3(const void*a,const void*b)
{
    struct FILE* x=(struct FILE*)a;
    struct FILE* y=(struct FILE*)b;
    if(strcmp(x->year,y->year)!=0)return strcmp(x->year,y->year);
    else if(strcmp(x->time,y->time)!=0)return strcmp(x->time,y->time);
    else return strcmp(x->name,y->name);
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {

            struct FILE ans[n];

            for(int i=0;i<n;i++)
            {

                scanf("%s %s %d %s",ans[i].year,ans[i].time,ans[i].size,ans[i].name);


            }
            char c[5],s[5];
            scanf("%s %s",c,s);
            if(strcmp(s,"/NAME")==0)
                qsort(ans,n,sizeof(ans[0]),cmp1);
            else if(strcmp(s,"/SIZE")==0)
                qsort(ans,n,sizeof(ans[0]),cmp2);
            else if(strcmp(s,"/TIME")==0)
                qsort(ans,n,sizeof(ans[0]),cmp3);
            for(int i=0;i<n;i++)
            {
                printf("%s%c%s%16d%c%s\n",ans[i].year,' ',ans[i].time,ans[i].size,' ',ans[i].name);
            }
            scanf("%d",&n);
            if(n)
            printf("\n");



        }


    return 0;
}
