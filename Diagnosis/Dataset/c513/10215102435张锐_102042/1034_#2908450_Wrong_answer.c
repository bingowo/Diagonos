#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float s[26]={0.0f};
int cmp(const void *a,const void *b)
{
    char s1=*(char*)a,s2=*(char*)b;
    int i1,i2;
    if(s1>='A'&&s1<'a') i1=s1-'A';
    if(s1>='a') i1=s1-'a';
    if(s2>='a') i2=s2-'a';
    if(s2>='A'&&s2<'a') i2=s2-'A';
    if(s[i1]<s[i2]) return 1;
    else if(s[i1]==s[i2]) return s2-s1;
    else return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<26;j++)
        {
            scanf("%f",&s[j]);
        }
        char a[150];
        scanf("%s",a);
        int len=strlen(s);
        qsort(a,len,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",a);
    }
    return 0;
}
