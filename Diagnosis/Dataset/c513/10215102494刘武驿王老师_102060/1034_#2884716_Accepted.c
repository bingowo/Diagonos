#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
double freq[26];
int cmp(void *a,void *b)
{
    char *a1=(char *)a;
    char *b1=(char *)b;
    if(toupper(*a1)==toupper(*b1)) return *b1-*a1;
    if(freq[toupper(*a1)-'A']>freq[toupper(*b1)-'A']) return -1;
    else return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int x=0;x<26;x++) scanf("%lf",&freq[x]);
        char str[200];
        scanf("%s",str);
        qsort(str,strlen(str),sizeof(str[0]),cmp);
        printf("case #%d:\n%s\n",i,str);
    }
}
