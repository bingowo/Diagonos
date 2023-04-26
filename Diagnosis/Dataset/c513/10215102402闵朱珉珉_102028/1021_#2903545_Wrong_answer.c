#include <stdio.h>
#include <stdlib.h>
int main()
{
    char s1[27],s2[100][21];
    int q[27],j=0;
    scanf("%s",s1);
    for (int i=0;i<26;i++)
        q[s1[i]-'A']=i;
    while (scanf("%s",s2[j])!=EOF)
        j++;
    int cmp(const void *a,const void *b)
{
    char *a1,*b1;
    int i=0;
    a1=*(char (*)[21])a;b1=*(char (*)[21])b;
    while (a1[i]&&b1[i])
    {
        a1[i]=a1[i]>'a'?a1[i]:a1[i]+'A'-'a';
        b1[i]=b1[i]>'a'?b1[i]:b1[i]+'A'-'a';
        if (q[a1[i]-'A']!=q[b1[i]-'A']) return q[a1[i]-'A']-q[b1[i]-'A'];
        i++;
    }
    if(*a1==0) return -1;
    else return 1;
}
    qsort(s2,j,sizeof(s2[0]),cmp);
    for (int i=0;i<j-1;i++)
        printf("%s ",s2[i]);
    printf("%s\n",s2[j-1]);
    return 0;
}
