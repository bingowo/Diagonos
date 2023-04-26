#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>



typedef struct{int flag;char a[310];char yu[310];char xu[310];}line;

int cmp(const void*a1,const void*a2)
{
    line a=*(line*)a1;
    line b=*(line*)a2;
    if(a.flag!=b.flag) return a.flag-b.flag;
    else if(strcmp(a.yu,b.yu)!=0) return strcmp(a.yu,b.yu);
    else return strcmp(a.xu,b.xu);
}

int main()
{
    int n;
    scanf("%d",&n);
    int count=0;
    line*w;
    w=(line*)malloc(sizeof(line)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",w[i].a);
        if(w[i].a[4]=='s') w[i].flag=1;
        else {w[i].flag=0;count++;}
        char*p=strchr(w[i].a,'/');
        p++;p++;
        int e=0;
        while(*p!='/') {w[i].yu[e]=*p;p++;e++;}
        w[i].yu[e]='\0';
        e=0;
        p++;
        while(*p) {w[i].xu[e]=*p;p++;e++;}
        w[i].xu[e]='\0';
    }
    qsort(w,n,sizeof(line),cmp);
    for(int i=0;i<count;i++)
        printf("%s\n",w[i].a,w[i].flag);

    return 0;
}
