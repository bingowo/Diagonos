#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
    char *p1,*p2,*m1,*m2;
    p1=*((char**)a);
    p2=*((char**)b);
    int i=0;
    while(*(p1+i)!='@')  i++;
    m1=p1+i+1;
    i=0;
    while(*(p2+i)!='@')  i++;
    m2=p2+i+1;
    if(strcmp(m1,m2)==0)  return strcmp(p2,p1);
    else  return strcmp(m1,m2);
}
int main()
{
    int n,i,len;
    char **email;
    scanf("%d",&n);
    email=(char**)malloc(n*sizeof(char*));
    char s[1000100],*p;
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        p=(char*)malloc((len+1)*sizeof(char));
        strcpy(p,s);
        *(email+i)=p;
    }
    qsort(email,n,sizeof(char*),cmp);
    for(i=0;i<n;i++)
    {
        printf("%s\n",email[i]);
    }
    for(i=0;i<n;i++)
    {
        p=email[i];
        free(p);
    }
    free(email);
    return 0;
}