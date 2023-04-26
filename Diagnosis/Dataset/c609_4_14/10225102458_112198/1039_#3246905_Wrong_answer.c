#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
        int len2=strlen(s2);
        q=strrstr(s,s2);
        printf("case #%d:\n",i);
        if(q==NULL||p==NULL)printf("0\n");
        else if(p==q)printf("%d\n",abs(len1-len2));
        else if((p-q)<0)printf("%d\n",q-p-len1);
        else printf("%d\n",p-q-len2);

    }
    return 0;
}