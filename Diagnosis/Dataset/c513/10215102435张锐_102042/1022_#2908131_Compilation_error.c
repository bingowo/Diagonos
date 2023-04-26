#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    char *s1=*(char**)a,*s2=*(char**)b;char *p1,*p2;
    int len1=strlen(s1),len2=strlen(s2);
    int i=0;
    while(*(s1+i)!='@') i++;
    p1=s1+i+1;
    i=0;
    while(*(s1+i)!='@') i++;
    p2=s2+i+1;
    if(strcmp(p1,p2)==0) return strcmp(s2,s1);
    else return strcmp(p1,p2);
}
int main()
{
    int t;
    scanf("%d",&t);
    char **email=(char **) malloc(t*sizeof(char *));
    //动态分配指针数组空间
    char s[1000001],*p;
    int i,len;
    for(i=0;i<t;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        p=(char *) malloc(len-1);//动态申请内存
        strcmp(p,s);//把输入的字符串复制到动态申请的空间中
        *(email+i)=p;
    }
    qsort(email,t,sizeof(char *),cmp);
    for(int i=0;i<t;i++)
    {
        printf("%s\n",email[i]);
    }
    for(i=0;i<n;i++)
    {
        p=email[i];
        free(p);//内存逐个释放
    }
    free(email);
    return 0;
}
