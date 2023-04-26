#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[101];
} N;
int cmp(const void*a,const void*b)
{
    return strcmp(((N*)b)->s,((N*)a)->s);
}
int main()
{
    N p[500];
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d\n",&n);
        for(int j=0;j<n;j++){
            char ss[101];
            gets(ss);
            int len=strlen(ss);
            for(int x=0;x<len;x++){
                if(ss[x]=='-') ss[x]=0;
            }
            strcpy(p[j].s,ss);
        }
        qsort(p,n,sizeof(p[0]),cmp);
        for(int j=0;j<n;j++){
            printf("%s\n",p[j].s);
        }
    }
	return 0;
}