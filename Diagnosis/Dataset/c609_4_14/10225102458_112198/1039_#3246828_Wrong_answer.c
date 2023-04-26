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
        char s[81],s1[81],s2[81],*p,*q;
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        p=strstr(s,s1);
        int len1=strlen(s1);
        q=strrstr(s,s2);
        int len=q-p;
        printf("case #%d:\n",i);
        printf("%d\n",len-len1);

    }
    return 0;
}
