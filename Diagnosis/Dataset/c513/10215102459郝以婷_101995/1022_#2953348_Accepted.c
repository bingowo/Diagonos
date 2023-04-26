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
    //printf("%c\n",*p);
    while(*(p++)!='@');
    while(*(q++)!='@');

    if(strcmp(p,q)==0)
    {
        return strcmp(n,m);
    }
    else
    {
        return strcmp(p,q);
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
        p=(char*)malloc(len*sizeof(char)+1);
        strcpy(p,s);
        
        *(email+i)=p;
    
        //printf("%c sb\n",*email[i]);
        //printf("%d\n",i);
    }

    qsort(email,N,sizeof(char*),cmp);
    //printf("%d\n",i);
    for(i=0;i<N;i++)
    {
        printf("%s\n",email[i]);
    }
    free(p);
    return 0;
}
