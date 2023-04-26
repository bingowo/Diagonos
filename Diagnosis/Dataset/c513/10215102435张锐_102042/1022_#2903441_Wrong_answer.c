#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char name1[10000];
    char name2[10000];
}you;
int cmp(const void *a,const void *b)
{
    you *s1=(you*)a,*s2=(you*)b;
    int i=strcmp(s1->name2,s2->name2);
    if(i>0) return 1;
    if(i<0) return -1;
    else {return -strcmp(s1->name1,s2->name1);}
}
int main()
{
    int t;char c;
    scanf("%d",&t);
    you *p=(you *) malloc(t*sizeof(you));
    for(int i=0;i<t;i++)
    {
        int j=0;
        getchar();
        while((c=getchar())!='@') {p[i].name1[j++]=c;}
        j=0;
        scanf("%s",&p[i].name2);
    }
    if(t==1)
    {
        printf("%s",p[0].name1);
        printf("@");
        printf("%s\n",p[0].name2);
    }
    qsort(p,t,sizeof(p[0]),cmp);
    for(int i=0;i<t;i++)
    {
        printf("%s",p[i].name1);
        printf("@");
        printf("%s\n",p[i].name2);
    }
    free(p);
    return 0;
}
