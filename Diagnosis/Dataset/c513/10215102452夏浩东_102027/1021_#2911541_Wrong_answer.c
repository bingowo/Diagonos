#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char std[27];
int cmp(const void *a,const void *b)
{
    char *A= *(char**) a;
    char *B= *(char**) b;
    for(int i=0;;i++)
    {
    	char c1,c2;
        if(A[i]>='a') c1=(char)(A[i]-'a'+'A');
        else c1=A[i];
        if(B[i]>='a') c2=(char)(B[i]-'a'+'A');
        else c2=B[i];
        
        if(c1==c2) continue;
        for(int j=0;j<26;j++)
        {
            if(std[j]==c1) return -1; 
            if(std[j]==c2) return 1;
        }
	}
    
}
int main()
{
    while(scanf("%s",std)!=EOF)
    {
        char *L[100];
        char c=' ';
        int i=0;
        for(i=0;c!='\n';i++)
        {
            char *s = (char*)malloc(20*sizeof(char));
            scanf("%s",s);
            L[i]=s;
            c=getchar();
        }
        qsort(L,i,sizeof(char*),cmp);
        for(int t=0;t<i;t++)
        {
            if(t!=i-1) printf("%s ",L[t]);
            else printf("%s\n",L[t]);
            free(L[t]);
        }
    }
    return 0;
}