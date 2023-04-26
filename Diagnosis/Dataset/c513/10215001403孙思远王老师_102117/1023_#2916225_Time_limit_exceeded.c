#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void *a,const void *b)
{
    char *p1,*p2,pn1[10],pn2[10];
    int len1,len2,i,j,flag1=0,flag2=0;
    p1=*(char **)a;
    p2=*(char **)b;
    len1=strlen(p1);
    len2=strlen(p2);
    for(i=0,j=0;i<len1;i++)
    {
        if(isdigit(p1[i]))
        {
            pn1[j]=p1[i];
            j++;
            flag1=1;
        }
    }
    for(i=0,j=0;i<len2;i++)
    {
        if(isdigit(p1[2]))
        {
            pn2[j]=p2[i];
            j++;
            flag2=1;
        }
    }
    if(flag1==0&&flag2==0)
        return strcmp(p1,p2);
    else if(flag1==1&&flag2==0)
        return 1;
    else if(flag1==0&&flag2==1)
        return -1;
    else
    {
        if(atoi(pn1)==atoi(pn2))
            return strcmp(p1,p2);
        else
            return atoi(pn1)-atoi(pn2);
    }

}

int main()
{
    char s[100][31];
    int i=0,j;
    while(scanf("%s",s[i]))
    {
        i++;
    }
    qsort(s,i,sizeof(s[0]),cmp);
    for(j=0;j<i;j++)
    {
        printf("%s ",s[j]);
    }
    return 0;
}
