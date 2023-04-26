#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char alpha[27];
int alphadigit(char p);
int compar(const void *p1,const void *p2);
int main()
{
    char *a[101];
    int i=0;
    for(i=0;i<101;i++)
        a[i]=(char*)malloc(sizeof(char)*21);
    while(scanf("%s",alpha)!=EOF)
    {
        i=0;
        while(scanf("%s",a[i++])!=EOF);
        qsort(a,i,sizeof(char*),compar);
    }
    for(i=0;i<101;i++)
        free(a[i]);

    return 0;
}
int alphadigit(char p)
{
    int i;
    for(i=0;i<26;i++)
    {
        if(p==alpha[i]||p==alpha[i]+32)
        {
            //num=i;
            break;
        }
    }
    return i;
    //return num;
}
int compar(const void *p1,const void *p2)
{
    char *a,*b;
    a=(char*)p1;b=(char*)p2;
    int i=0,numa,numb,flag=0;
    while(a[i]!=0&&b[i]!=0)
    {
        if(a[i]==b[i]);
        else
        {
            numa=alphadigit(a[i]);
            numb=alphadigit(b[i]);
            if(numa<numb)
                flag=-1;
            else
                flag=1;
            break;
        }
        i++;
    }
    if(flag==0)
    {
        if(a[i]==0)
            flag=-1;
        else
            flag=1;
    }
    return flag;
}
