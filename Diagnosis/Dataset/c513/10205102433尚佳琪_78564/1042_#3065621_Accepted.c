#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    char m[20];
}node;
int cmp(const void *a,const void *b)
{
    char s1=*(char*)a;
    char s2=*(char*)b;
    return s1-s2;
}
int cmp2(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    return strcmp(s1.m,s2.m);
}
void f(char*s,char* nult)
{
    if(*s)
    {
        char left[20];
        sprintf(left,"%s%c",nult,s[0]);
        printf("%s\n",left);
        f(s+1,left);
        f(s+1,nult);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[20];
        char s2[20];
        int k=0;
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(s[0]),cmp);
        s2[k++]=s[0];
        for(int i=1;i<len;i++)
        {
            if(s[i]!=s[i-1])
            {
                s2[k++]=s[i];
            }
        }
        s2[k]='\0';
        printf("case #%d:\n",i);
        f(s2,"");
    }
}
