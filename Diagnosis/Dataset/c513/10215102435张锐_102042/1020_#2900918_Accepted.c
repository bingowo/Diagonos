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
    int i=strcmp(s1.A,s2.A);
    if(i>0) return 1;
    if(i<0) return -1;
    else if(i==0)
    {
        i=strcmp(s1.B,s2.B);
        if(i>0) return 1;
        else if(i<0) return -1;
    }
    return strcmp(s1.D,s2.D);
}
int cmpname(const void *a,const void *b)
{
    file s1=*(file*) a,s2=*(file*) b;
    return strcmp(s1.D,s2.D);
}
int cmpsize(const void *a,const void *b)
{
    file s1=*(file*) a,s2=*(file*) b;
    int num1=s1.num,num2=s2.num;
    if(num1<num2) return -1;
    else if(num1>num2) return 1;
    else return strcmp(s1.D,s2.D);
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
        char s[50]={'0'};
        scanf("%s",s);
        scanf("%s",s);
        if(s[1]=='T') qsort(p,n,sizeof(file),cmptime);
        else if(s[1]=='N') qsort(p,n,sizeof(file),cmpname);
        else if(s[1]=='S') qsort(p,n,sizeof(file),cmpsize);
        for(int i=0;i<n;i++)
        {
            printf("%s ",p[i].A);
            printf("%s",p[i].B);
            printf("%17d ",p[i].num);
            printf("%s\n",p[i].D);
        }
        printf("\n");
        free(p);
        scanf("%d",&n);
    }
    return 0;
}
