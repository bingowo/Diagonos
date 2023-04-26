#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b)
{
    char *ap=(char*)a;
    char *bp=(char*)b;
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
    for(l1=l1+1,l2=l2+1;*(ap+l1)||*(bp+l2);l1++,l2++)
    {
        if(*(ap+l1)!=*(bp+l2))
            return (*(ap+l1)-*(bp+l2));
    }
    for(l1=0,l2=0;*(ap+l1)&&*(bp+l2);l1++,l2++)
    {
        if(*(ap+l1)=='@')
            return 1;
        if(*(bp+l2)=='@')
            return -1;
        return (*(bp+l2)-*(ap+l1));
    }
}

int main()
{
    int n;
    scanf("%d ",&n);
    char **mail;
    mail=(char **)calloc(n,sizeof(char *));
    int i;
    for(i=0;i<n;i++)
    {
        char s[100001]={0};
        scanf("%s",s);
        int l;
        l=strlen(s);
        char *p;
        p=(char*)calloc(l+1,sizeof(char));
        p=s;
        *(mail+i)=p;
    }
    qsort(mail,n,sizeof(char**),cmp);
    for(i=0;i<n;i++)
        printf("%s\n",*(mail+i));
}