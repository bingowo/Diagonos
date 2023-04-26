#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    char *p,*q,*m,*n;
    m=p=*((char**)a);
    n=q=*((char**)b);
    while(*p!='@')  p++;
    while(*q!='@')  q++;
    if(*(p+1)!=*(q+1))
    {
        return *(int*)(*p+1)-*(int*)(*q+1);
    }
    else
    {
        return *(int*)(*n)-*(int*)(*m);
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
        printf("%s\n",*(email+i));
    }
    return 0;
}
