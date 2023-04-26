#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char s[21];
    int s0;
} zf;
int cmp(const void *a,const void *b)
{
    zf* a0=(zf*)a;
    zf* b0=(zf*)b;
    if(a0->s0!=b0->s0)
        return b0->s0-a0->s0;
    return strcmp(a0->s,b0->s);
}
int main()
{
    zf a[100];
    int t,n,i,j,k,l;
    int c[26];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%s",a[j].s);
            l=strlen(a[j].s);
            a[j].s0=0;
            for(k=0;k<26;k++)
                c[k]=0;
            for(k=0;k<l;k++){
                if(c[a[j].s[k]-'A']==0)
                    a[j].s0++;
                c[a[j].s[k]-'A']++;
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
            printf("%s\n",a[j].s);
    }
    return 0;
}
