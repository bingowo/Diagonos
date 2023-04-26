#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b)
{
    char *ap=*((char**)a);
    char *bp=*((char**)b);
    int l1,l2;
    for(l1=0;*(ap+l1);l1++)
    {
        if(*(ap+l1)!='@');
        else
            break;
    }
    for(l2=0;*(bp+l2);l2++)
    {
        if(*(bp+l2)!='@');
        else
            break;
    }
    char *dominant1,*dominant2;
    dominant1=ap+l1+1;
    dominant2=bp+l2+1;
    if(strcmp(dominant1,dominant2)==0)
        return(strcmp(bp,ap));
    else
        return(strcmp(dominant1,dominant2));
}

int main()
{
    int n;
    scanf("%d ",&n);
    char **mail;
    mail=(char **)calloc(n,sizeof(char *));
    int i;
    char *p;
    for(i=0;i<n;i++)
    {
        char s[1000001]={0};
        scanf("%s",s);
        int l;
        l=strlen(s);
        p=(char*)calloc(l+1,sizeof(char));
        strcpy(p,s);
        *(mail+i)=p;
    }
    qsort(mail,n,sizeof(char*),cmp);
    for(i=0;i<n;i++)
        printf("%s\n",*(mail+i));
}