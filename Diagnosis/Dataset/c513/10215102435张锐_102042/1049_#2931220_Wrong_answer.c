#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int cmp(const void *a,const void *b)
{
    char *s1=(char *)a,*s2=(char *)b;
    return strcmp(s1,s2);
}
int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        char s[2000];
        gets(s);
        int len=strlen(s);
        char ans[500][25];int k=0,i1=0;
        for(int j=0;j<len;j++)
        {
            if(isalpha(s[j])) ans[k][i1++]=s[j];
            else {ans[k][i1]='\0';k++;i1=0;}
        }
        qsort(ans,k,sizeof(ans[0]),cmp);
        printf("case #%d:\n",i);
        for(int ii=0;ii<k;ii++)
        {
            if(strcmp(ans[ii],ans[ii+1])!=0) printf("%s ",ans[ii]);
        }
        printf("%s\n",ans[k]);
    }
    return 0;
}
