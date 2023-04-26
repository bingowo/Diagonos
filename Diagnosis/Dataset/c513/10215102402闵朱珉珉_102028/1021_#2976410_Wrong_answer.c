#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int split_words(char *buf, char **dst) {
	int n = 0;
	char *p = strtok(buf, " ");
	while(p) {
		strcpy(*dst++, p);
		n++;
		p = strtok(NULL, " ");
	}
	return n;
}
int main()
{
    int p[256];
    char alpha[256];
    while(gets(alpha)!=NULL)
    {
        for(int i=0;i<26;i++)
            p[alpha[i]]=i;
    }
    char **a = (char **)malloc(101 * sizeof(char *));
	for(int i = 0; i < 101; i++)
	{
		a[i] = (char *)malloc(101 * sizeof(char));
	}
    int k=0,status=0;
    char line[50000];
    gets(line);
    int n = split_words(line, a);
    int cmp(const void *a,const void *b)
{
    const char *s1,*s2;char ch1,ch2;
    s1=*(char (*)[21])a;s2=*(char (*)[21])b;
    while(*s1&&*s2)
    {
        ch1=(*s1)>='a'?*s1-32:*s1;
        ch2=(*s2)>='a'?*s2-32:*s2;
        if(p[ch1]!=p[ch2])
                return p[ch1]-p[ch2];
        else {s1++;s2++;}
    }
    if(*s1==0) return -1;
    else return 1;
}
    qsort(a,n,sizeof(char *),cmp);
    for(int i = 0; i < n; ++i)
    {
        printf("%s", a[i]);
        if(i != n - 1) printf(" ");
    }
    printf("\n");
    for(int i = 0; i < 101; i++)
		free(a[i]);
	free(a);
    return 0;
}
