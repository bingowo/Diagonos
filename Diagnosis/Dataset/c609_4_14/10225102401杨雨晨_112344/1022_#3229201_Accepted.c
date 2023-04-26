#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Address
{
    char* user, *main;
};

int cmp(const void *a,const void *b)
{
    struct Address x,y;
    x=*((struct Address *)a);
    y=*((struct Address *)b);
    if(strcmp(x.main,y.main)==0) return strcmp(y.user,x.user);
    return strcmp(x.main,y.main);
}
int main()
{
    long long int n,count=0;
    scanf("%lld",&n);
    getchar();
    struct Address *ip=NULL;
    while(count<n)
    {
        long long int counts=0;
        char ch;
        char* temp=NULL;
        char* tempuser=NULL;
        char* tempmain=NULL;
        do
        {
            ch=getchar();
            counts++;
            temp=(char*)realloc(temp, sizeof(char)*(counts+1));
            temp[counts-1]=ch;
        }while(ch!='\n');
        temp[counts]='\0';
        count++;
        ip=(struct Address *)realloc(ip,n*sizeof(struct Address));
        ip[count-1].user=NULL;
        ip[count-1].main=NULL;
        long long int i,j,len=strlen(temp);
        for(i=0;temp[i]!='@';i++)
        {
            tempuser=(char *)realloc(tempuser,sizeof(char)*(i+1));
            tempuser[i]=temp[i];
        }
        tempuser=(char *)realloc(tempuser,sizeof(char)*(i+2));
        tempuser[i]='\0';
        i++;
        for(j=0;i<len;i++,j++)
        {
            tempmain=(char *)realloc(tempmain,sizeof(char)*(j+1));
            tempmain[j]=temp[i];
        }
        tempmain=(char *)realloc(tempmain,sizeof(char)*(j+2));
        tempmain[j]='\0';
        ip[count-1].user=(char *)realloc(ip[count-1].user,
                         sizeof(char)*(strlen(tempuser) + 1));
        ip[count-1].main=(char *)realloc(ip[count-1].main,
                         sizeof(char)*(strlen(tempmain) + 1));
        strcpy(ip[count-1].user,tempuser);
        strcpy(ip[count-1].main,tempmain);
        free(tempuser);
        free(tempmain);
        free(temp);
    }
    qsort(ip,n,sizeof(ip[0]),cmp);
    int j;
    for(j=0;j<n;j++)
    {
        printf("%s@%s",ip[j].user,ip[j].main);
    }
    free(ip);
    return 0;
}
