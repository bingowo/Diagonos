#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int cmp(const void*_a,const void*_b)
{
    char *p1,*p2,*q1,*q2;
    int i=0;
    p1=*((char**)_a);p2=*((char**)_b);
    while(*(p1+i)!='@') i++;
    q1=p1+i+1;
    i=0;
    while(*(p2+i)!='@') i++;
    q2=p2+i+1;
    if(strcmp(q1,q2)==0)    return strcmp(p2,p1);
    else    return strcmp(q1,q2);
}
int main()
{
    int n;
    scanf("%d",&n);
    char** email;
    email=(char**)malloc(n*sizeof(char*));
    char s[1000001],*p;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        int len=strlen(s);
        p=(char*)malloc(len+1);
        strcpy(p,s);
        *(email+i)=p;
    }
    qsort(email,n,sizeof(char*),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%s\n",email[i]);
    }
    for(int i=0;i<n;i++)
    {
        p=email[i];
        free(p);
    }
    free(email);
    return 0;
}
