#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[21];
    int k;
} N;
int cmp(const void*a,const void*b)
{
    if(((N*)a)->k==((N*)b)->k) return strcmp(((N*)a)->s,((N*)b)->s);
    return ((N*)b)->k-((N*)a)->k;
}
int main()
{
    int a[26]={0};
    N p[100];
    int n,m,l;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        for(int j=0;j<100;j++) p[j].k=0;
        for(int j=0;j<m;j++){
            for(int x=0;x<26;x++) a[x]=0;
            scanf("%s",p[j].s);
            l=strlen(p[j].s);
            for(int x=0;x<l;x++){
                if(a[p[j].s[x]-'A']==0) {
                    a[p[j].s[x]-'A']=1;
                    p[j].k++;
                }
            }
        }
        qsort(p,m,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<m;j++) printf("%s\n",p[j].s);
    }
	return 0;
}
