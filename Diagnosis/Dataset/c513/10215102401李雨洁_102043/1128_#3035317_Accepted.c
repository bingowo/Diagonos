#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char agreement[6],name[300],virtualname[300];
}http;

void handle(http* a,char* s)
{
    int i=0;
    while(s[i]!=':')
    {
        i++;
    }
    strncpy(a->agreement,s,i);
    a->agreement[i]='\0';
    s+=i+3;

    int j=0;
    while(s[j]!='/')
    {
        j++;
    }
    strncpy(a->name,s,j);
    s+=j+1;
    a->name[j]='\0';

    strcpy(a->virtualname,s);
}

int cmp(const void* a,const void *b)
{
    http* x=(http*)a;
    http* y=(http*)b;
    if(strcmp(x->name,y->name)!=0) return strcmp(x->name,y->name)<0?-1:1;
    else return strcmp(x->virtualname,y->virtualname)<0?-1:1;

}

int equal(http a,http b)
{
    if(strcmp(b.agreement,"https")==0) return 0;
    else
        {
        if(strcmp(a.name,b.name)==0&&strcmp(a.virtualname,b.virtualname)==0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    char* s=(char *)malloc(sizeof(char)*301);
    scanf("%d",&n);
    http a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        handle(a+i,s);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    http tmp={"1","1","1"};
    for(int i=0;i<n;i++)
    {
        if(equal(tmp,a[i])!=0)
        {
            printf("%s://%s/%s\n",a[i].agreement,a[i].name,a[i].virtualname);
            tmp=a[i];
        }
        else continue;

    }
    return 0;
}
