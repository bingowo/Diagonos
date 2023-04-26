#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int num(char *s)
{
    int a[200],cnt=0;
    for (int i=0; i<200; i++)
        a[i]=-1;
    int len=strlen(s);
    for(int i=0; i<len; i++)
        if (a[s[i]]==-1)
        {
            cnt++;
            a[s[i]]=1;
        }
        return cnt;
}
int cmp(const void *a,const  void *b)
{
    int n1,n2;
    char *p1=*(char(*)[101])a;
    char *p2=*(char(*)[101])b;
    n1=num(p1);
    n2=num(p2);
    if(n1<n2)
    return 1;
    else
        return -1;
}
int main()
{
    char s[200][21];
    int n,num1;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&num1);
        for(int j=0; j<num1; j++)
            scanf("%s",s[j]);
        qsort(s,num1,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<num1;j++)
        printf("%s\n",s[j]);
    }
    return 0;
}
