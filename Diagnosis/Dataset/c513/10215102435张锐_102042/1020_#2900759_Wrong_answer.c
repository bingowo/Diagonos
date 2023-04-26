#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char A[50];
    char B[50];
    int num;
    char D[50];
}file;
int cmptime(const void *a,const void *b)
{
    file s1=*(file*) a,s2=*(file*) b;
    int len=strlen(s1.A);
    for(int i=0;i<len;i++)
    {
        if(s1.A[i]<s2.A[i]) return 1;
    }
    len=strlen(s1.B);
    for(int i=0;i<len;i++)
    {
        if(s1.B[i]<s2.B[i]) return 1;
    }
    return -1;
}
int cmpname(const void *a,const void *b)
{
    file s1=*(file*) a,s2=*(file*) b;
    int len=strlen(s1.D);
    for(int i=0;i<len;i++)
    {
        if(s1.D[i]>s2.D[i]) return 1;
    }
    return -1;
}
int cmpsize(const void *a,const void *b)
{
    file s1=*(file*) a,s2=*(file*) b;
    int num1=s1.num,num2=s2.num;
    return num2-num1;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {
        file *p=(file*) malloc(n*sizeof(file));
        for(int i=0;i<n;i++)
        {
            scanf("%s",&p[i].A);
            scanf("%s",&p[i].B);
            scanf("%d",&p[i].num);
            scanf("%s",&p[i].D);
        }
        char s[50];
        scanf("%s",s);
        if(s[6]=='T') qsort(p,n,sizeof(file),cmptime);
        else if(s[6]=='N') qsort(p,n,sizeof(file),cmpname);
        else if(s[6]=='S') qsort(p,n,sizeof(file),cmpsize);
        for(int i=0;i<n;i++)
        {
            printf("%s ",p[i].A);
            printf("%s ",p[i].B);
            printf("%17d ",p[i].num);
            printf("%s\n",p[i].D);
        }
        printf("\n");
        free(p);
        scanf("%d",&n);
    }
    return 0;
}
