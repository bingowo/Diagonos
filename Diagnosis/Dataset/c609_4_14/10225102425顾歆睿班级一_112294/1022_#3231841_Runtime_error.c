#include<stdio.h>
#include<string.h>
#include<malloc.h>
int cmp(const void*a,const void *b){
    char *m,*n,*c1,*c2;
    m=*(char**)(a);
    n=*(char**)(b);
    int i=0;
    while(*(m+i)!='@')i++;
    c1=m+i+1;
    i=0;
    while(*(n+i)!='@')i++;
    c2=n+i+1;
    if(strcmp(c1,c2)==0)
        return strcmp(n,m);
    else
        return strcmp(c1,c2);
}
int main(){
    char **email,s[100000],*p;
    int n,length;
    scanf("%d",&n);
    email=(char **)malloc(n*sizeof(char **));
    for(int i=0;i<n;i++){
        scanf("%s",s);
        length=strlen(s);
        p=(char*)malloc(length+1);
        strcpy(p,s);
        *(email+i)=p;
    }
    qsort(email,n,sizeof(*email),cmp);
    for(int i=0;i<n;i++)
        printf("%s\n",*(email+i));
    for(int i=0;i<n;i++)
        free(*(email+i));
    free(email);
    return 0;
}