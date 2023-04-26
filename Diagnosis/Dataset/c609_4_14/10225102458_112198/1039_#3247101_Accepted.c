#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *strrstr(char *m,char* n)
{
    char *p=strstr(m,n);
    char *q=NULL;
    while(p!=NULL){
        q=p;
        p=strstr(1+p,n);
    }
    return q;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char s[81],s1[81],s2[81],*p,*q,*m,*n;
        int l,ss;
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        m=strstr(s,s1);
        n=strstr(s,s2);
        p=strrstr(s,s1);
        q=strrstr(s,s2);
        l=(q-m>=p-n?q-m:p-n);
        if(l==q-m)ss=strlen(s1);
        else ss=strlen(s2);
        printf("case #%d:\n",i);
        if(q==NULL||p==NULL)printf("0\n");
        else if(m==n&&m==p&&m==q)printf("0\n");
        else printf("%d\n",l-ss);

    }
    return 0;
}
