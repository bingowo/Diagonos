#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b)
{
    char *A=*(char**)a;
    char *B=*(char**)b;
    return strcmp(A,B);
}
int main()
{
    int cnt=0;
    char c;
    scanf("%d%c",&cnt,&c);
    char *T[500];
    char s[501];
    char M[501];
    for(int i=0;i<cnt;i++)
    {
        int len=0;
        gets(s);
        for(int m=0,k=0;s[k]!='\0';k++)
        {
            if((s[k]>'z'||s[k]<'a') && m!=0)
            {
            	M[m]='\0';
            	char *N=(char*)malloc(sizeof(char)*501);
            	for(int x=0;x<m+1;x++) N[x]=M[x];
            	T[len++]=N;
                m=0;
            }
            else if((s[k]>'z'||s[k]<'a') && m==0);
            else M[m++]=s[k];
            if(s[k+1]=='\0')
			{
				M[m]='\0';
            	char *N=(char*)malloc(sizeof(char)*501);
            	for(int x=0;x<m+1;x++) N[x]=M[x];
            	T[len++]=N;
                m=0;
			}
    	}
        qsort(T,len,sizeof(char*),cmp);
        char *NT[500];
        NT[0]=T[0];
        int nn=1;
        for(int k=1;k<len;k++)
        {
        	if(strcmp(T[k],T[k-1])!=0) {NT[nn]=T[k];nn++;}
		}
        printf("case #%d:\n",i);
        for(int k=1;k<nn-1;k++) printf("%s ",NT[k]);
        printf("%s\n",NT[nn-1]);
        for(int k=0;k<len;k++) free(T[k]);
    }
    return 0;
}