#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<malloc.h>
#define MAXN 1000001

int cmp(const void*a,const void*b)
{
    char *p1,*p2,*dm1,*dm2;
    p1=*((char**)a),p2=*((char**)b);
    int i=0,j=0;
    while(*(p1+i)!='@') i++;
    dm1=i+1+p1;
    while(*(p2+j)!='@') j++;
    dm2=j+1+p2;
    if(strcmp(dm1,dm2)==0) return strcmp(p1,p2);
    else return strcmp(dm1,dm2);
}

int main()
{
    int n;
    scanf("%d",&n);
    char s[MAXN];
    char*p;
    char **email=malloc(sizeof(char*)*n);
    for(int i=0;i<n;++i)
    {
        scanf("%s",s);
        int len=strlen(s);
        p=(char*)malloc(len+1);
        strcpy(p,s);
        *(email+i)=p;
    }
    qsort(email,n,sizeof(email[0]),cmp);
    for(int j=0;j<n;++j)
    {
        printf("%s\n",email[j]);
    }
     for(int j=0;j<n;j++)
    {
        p=email[j];
        free(p);
    }
    free(email);
    return 0;
}
