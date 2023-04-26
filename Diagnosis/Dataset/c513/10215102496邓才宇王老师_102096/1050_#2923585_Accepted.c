#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *strrstr(const char *s1, const char *s2)
{
    char *tmp = strstr(s1, s2);
    char *ret = NULL;
    while (1)
    {
        if (tmp != NULL)
        {
            ret = tmp;
        }
        else
            break;
        tmp = strstr(tmp + strlen(s2), s2);
    }
    return ret;
}
int main()
{
    int t;scanf("%d",&t);getchar();
    for(int i=0;i<t;i++)
    {
        char s1[100]={'\0'},s2[100]={'\0'},s[100]={'\0'};
        gets(s1);gets(s2);gets(s);
        char *p1=NULL,*p2=NULL;
        p1=strstr(s,s1);
        p2=strrstr(s,s2);
        printf("case #%d:\n",i);
        if(p1==NULL||p2==NULL||p1==p2) printf("0\n");
        else if(p2>p1)
            printf("%d\n",p2-p1-strlen(s1));
        else if(p2<p1)
            printf("%d\n",strrstr(s,s1)-strstr(s,s2)-strlen(s2));
    }
    return 0;
}

