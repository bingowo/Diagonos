#include<stdio.h>
#include<stlib.h>
#include<string.h>

int cmp(const void*a,const void*b)
{
    char *p1,*p2,*domain,*domain2;
    int i=0;
    p1=*((char **)a);
    p2=*((char **)b);
    while(*(p1+i)!='@')i++;
    domain1=p1+i+1;
    i=0;
    while(*(p2+i)!='@')i++;
    domain2=p2+i+1;
    if(strcmp(domain1,domain2)==0)return strcmp(p2,p1);
    else return strcmp(domain1,domain2);
}

int main()
{
    int n;scanf("%d\n",&n);
    cahr **email;email=(char**)malloc(n*sizeof(char *));
    char s[1000001],*p;
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        p=(char *)malloc(len+1);
        strcpy(p,s);
        *(email+i)=p;
    }
    qsort(email,n,sizeof(char*),cmp);
    for(i=0;i<n;i++)printf("%s\n",email[i]);
    for(i=0;i<n;i++){p=email[i];free(p);}
    free(email);
}
