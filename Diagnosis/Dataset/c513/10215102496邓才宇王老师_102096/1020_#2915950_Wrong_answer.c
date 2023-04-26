#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s1[100];
    char s2[100];
    long long int sz;
    char s3[100];
}Fl;
int cmp1(const void* p1,const void* p2)
{
    Fl* a=p1;
    Fl* b=p2;
    if(strcmp(a->s1,b->s1)!=0) return strcmp(a->s1,b->s1);
    else
    {
        if(strcmp(a->s2,b->s2)!=0) return strcmp(a->s2,b->s2);
        else return strcmp(a->s3,b->s3);
    }
}
int cmp2(const void* p1,const void* p2)
{
    Fl* a=p1;
    Fl* b=p2;
    if((a->sz)>(b->sz)) return 1;
    else if((a->sz)<(b->sz)) return -1;
    else return strcmp(a->s3,b->s3);
}
int cmp3(const void* p1,const void* p2)
{
    Fl* a=p1;
    Fl* b=p2;
    return strcmp(a->s3,b->s3);
}
int main()
{
    int n;
    scanf("%d",&n);
    char s4[6],s5[5];
    while(n)
    {
        Fl a[101];
        for(int i=0;i<n;i++)
        {
            scanf("%s %s %lld %s",&a[i].s1,&a[i].s2,&a[i].sz,&a[i].s3);
        }
        scanf("%s %s",s4,s5);
        if(strcmp(s5,"/NAME")==0)
        qsort(a,n,sizeof(Fl),cmp3);
         if(strcmp(s5,"/SIZE")==0)
        qsort(a,n,sizeof(Fl),cmp2);
         if(strcmp(s5,"/TIME")==0)
        qsort(a,n,sizeof(Fl),cmp1);
        for(int q=0;q<n;q++)
        {
            printf("%s %s %16lld %s\n",a[q].s1,a[q].s2,a[q].sz,a[q].s3);
        }
        scanf("%d",&n);
    }
}
