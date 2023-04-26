#include<stdio.h>

int cmp(const void *a,const void*b)
{
    char *p1,*p2,*domain1,*domain2;
    int i=0;
    p1 = *((char **)a);
    p2 = *((char **)b);
    while(*(p1+i)!='@')i++;
    domain1 = p1+i+1;
    i=0;
    while(*(p2+i)!='@') i++;
    domain2 = p2+i+1;
}
int main()
{
    int n;
    char **email;
    scanf("%d\n",&n);
    email = (char **)malloc(n*sizeof(char*));
    
    char s[200],*p;
    int i,len;
    for(i =0;i<n;i++){
        scanf("%s",s);
        len = strlen(s);
        p=(char *)malloc(len+1);
        strcpy(p,s);
        *(email+i)=p;
    }
    return 0;
}