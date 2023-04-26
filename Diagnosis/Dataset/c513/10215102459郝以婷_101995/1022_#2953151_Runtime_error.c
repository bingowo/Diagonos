#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    char *p,*q,*m,*n;
    p=*((char**)a);
    q=*((char**)b);
    m=p;
    n=q;
    printf("%c\n",*p);
    while(*(p++)!='@');

    while(*(q++)!='@');

    if(*p!=*q)
    {
        return *(char*)(*p)-*(char*)(*q);
    }
    else
    {
        return *(char*)(*n)-*(char*)(*m);
    }

}

int main()
{
    int N,i,len;
    scanf("%d ",&N);
    char** email;
    char s[1000000],*p;
    email=(char**)malloc(N*sizeof(char*));
    for(i=0;i<N;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        p=(char*)malloc(len*sizeof(char));
        strcpy(p,s);
        *(email+i)=*p;
    }
    qsort(email,N,sizeof(char*),cmp);
    for(i=0;i<N;i++)
    {
        printf("%s\n",**(email+i));
    }
    return 0;
}
