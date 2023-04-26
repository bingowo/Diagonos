#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char *name;
    char *host;
} email;

int cmp(const void* a, const void* b)
{
    email* p1=(email*)a;email* p2=(email*)b;
    if(!strcmp(p1->host,p2->host))
    {
        return strcmp(p2->name,p1->name);
    }
    strcmp(p1->host,p2->host);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    email allemail[n];
    for(i=0;i<n;i++)
    {
        char tmp[300000],tmphost[300000],tmpname[300000];
        scanf("%s",&tmp);
        int j,p=0,flag=0;
        for(j=0;j<strlen(tmp);j++)
        {
            if(flag==1) tmphost[p++]=tmp[j];
            if(tmp[j]=='@') {strncpy(tmpname,tmp,j);tmpname[j]='\0';flag=1;}
        }
        tmphost[p]='\0';

        char *cpyhost=(char*)malloc((strlen(tmphost)+10)*sizeof(char));
        char *cpyname=(char*)malloc((strlen(tmpname)+10)*sizeof(char));
        strcpy(cpyhost,tmphost);strcpy(cpyname,tmpname);
        allemail[i].host=cpyhost,allemail[i].name=cpyname;
    }
    qsort(allemail,n,sizeof(allemail[0]),cmp);
    for(i=0;i<n;i++)
    {
        printf("%s@%s\n",allemail[i].name,allemail[i].host);
    }
    return 0;
}