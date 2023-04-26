#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
    char *p1=*((char**)a),*p2=*((char**)b);
    char*d1,*d2;
    int i=0;
    while(*(p1+i)!='@')i++;
    d1=p1+i+1;
    i=0;
    while(*(p2+i)!='@')i++;
    d2=p2+i+1;
    if(strcmp(d1,d2)==0) return strcmp(p2,p1);
    else return strcmp(d1,d2);

}
int main()
{
    int n;
    scanf("%d",&n);
    char s[1000001];
    char **email,*p;
    email=(char**)malloc(n*sizeof(char*));
    for (int i=0; i<n; i++)
    {
        scanf("%s",s);
        p =(char*)malloc(strlen(s)+1);
        strcpy(p,s);
        email[i] = p;
    }
    qsort(email,n,sizeof(char*),cmp);
    for (int i=0; i<n; i++)
    {
        printf("%s\n",email[i]);
    }
    for (int i=0;i<n;i++){
        p = email[i];
        free(p);
    }
    free(email);
return 0;
}
